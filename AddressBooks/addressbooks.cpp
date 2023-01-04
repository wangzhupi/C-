#include<iostream>
#include<string>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;

// 最大人数1000
#define Max 1000

// 设计结构体 
// 每个学生的基本信息
struct Person{
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Addr;
};

// 定义结构体数组 通讯录结构体
struct Addressbooks{
    // 通讯录数组
    struct Person personArray[Max];
    // 通讯录的人数
    int m_Size;  
};



// 菜单界面 
void showMenu(){
    cout<<"*****************"<<endl;
    cout<<"  1. 添加联系人  "<<endl;
    cout<<"  2. 显示联系人  "<<endl;
    cout<<"  3. 删除联系人  "<<endl;
    cout<<"  4. 查找联系人  "<<endl;
    cout<<"  5. 修改联系人  "<<endl;
    cout<<"  6. 清空联系人  "<<endl;
    cout<<"  0. 退出通讯录  "<<endl;
    cout<<"*****************"<<endl;
}

// add_person
void add_Person(Addressbooks * abs){
    
    if (abs->m_Size == Max){
        cout<<"通讯录已满 无法添加"<<endl;
        return ;
    }else{
        // 添加具体联系人

        // 添加姓名
        string name;
        cout<<"请输入姓名: "<<endl;
        cin>>name;
        abs->personArray[abs->m_Size].m_Name = name;

        // 添加性别
        cout<<"请输入性别: 1 : 男 2 : 女"<<endl;
        int sex = 0;
        
        while (true)
        {
            cin>>sex;
            // 只有输入对的时候才能被替换
            if(sex ==1 || sex ==2 ){
                abs->personArray[abs->m_Size].m_Sex=sex;
                break;
            }
        }


        // 添加年龄
        cout<<"请输入年龄"<<endl;
        int age = 0;
        // 年龄段处于正常的水平内的时候才能输入 
        while (true)
        {
            cin>>age;
            if(age>10&&age<30){
                abs->personArray[abs->m_Size].m_Age=age;
                break;
            }
        }

        // 添加住址信息
        string address;
        cout<<"请输入地址信息"<<endl;
        cin>>address;
        abs->personArray[abs->m_Size].m_Addr = address;

        // 添加手机号码信息
        string phone_number;
        cout<<"请输入手机号信息"<<endl;
        cin>>phone_number;
        abs->personArray[abs->m_Size].m_Phone=phone_number;

        // 更新通讯录的人数
        abs->m_Size++;
        cout<<"添加成功"<<endl;

        // system("cls");


    }
}


// show person
void show_Person(Addressbooks * abs){
    if(abs->m_Size==0){
        cout<<"当前记录为空！"<<endl;
    }else{
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout<<"姓名为: "<<abs->personArray[i].m_Name<<"\t";
            cout<<"性别: "<<(abs->personArray[i].m_Sex == 1 ? "男":"女")<<"\t";
            cout<<"地址为: "<<abs->personArray[i].m_Addr<<"\t";
            cout<<"电话号码为: "<<abs->personArray[i].m_Phone<<"\t";
            cout<<"年龄为: "<<abs->personArray[i].m_Age<<endl;
        }   
    }
}


// is_exist 
// 检测联系人是否存在
// 参数为指针 abs 和用户的姓名
int is_Exist(Addressbooks * abs,string name){
    for (int i = 0; i < abs->m_Size; i++)
    {
        if(abs->personArray[i].m_Name==name){
            // 返回第i个的位置的信息
            return i;
        }
    }
    // 遍历都没找到的话 返回-1
    return -1;
}


// del person
void del_person(Addressbooks * abs){
    
    cout<<"请输入待查找人的姓名"<<endl;
    string name;
    cin>>name;

    int ret=0;
    ret = is_Exist(abs,name);

    if(ret == -1){
        cout<<"查无此人"<<endl;
    }else{
        for (int i = ret; i < abs->m_Size; i++)
        {
            abs->personArray[i]=abs->personArray[i+1];
        }
        return;
    }

    // 删除过后 更新size的数量
    abs->m_Size--;
}

// find_person
// 利用名字来进行查找
void find_Person(Addressbooks * abs){

    // 输入姓名
    string name;
    cout<<"请输入要查找的姓名："<<endl;
    cin>>name;

    cout<<"以下是你查找姓名的全部信息"<<endl;

    for (int i = 0; i < abs->m_Size; i++)
    {
        if(name == abs->personArray[i].m_Name){
            // 如果找到对应名字的联系人 输入所有的信息
            cout<<abs->personArray[i].m_Name<<"\t";
            cout<<abs->personArray[i].m_Age<<"\t";
            cout<<abs->personArray[i].m_Phone<<"\t";
            cout<<(abs->personArray[i].m_Sex == 1 ? "男":"女")<<"\t";
            cout<<abs->personArray[i].m_Addr<<endl;
        }
    }
}

// 修改联系人 
// 通过姓名修改
void modify_Person(Addressbooks * abs){
    // 也是通过姓名来进行查找然后修改
    // 调用之前写的is_Exist来进行处理
    string name;
    cout<<"请输入待修改的联系人姓名"<<endl;
    cin>>name;
    
    int ret=0;
    ret = is_Exist(abs,name);

    if(ret==-1){
        cout<<"待修改的联系人不存在！"<<endl;
    }else{
        // 如果找到了那么说明返回的ret就是其在数组中位置 直接进行修改

        // 修改姓名
        cout<<"请输入想要修改的类型"<<endl;

        cout<<"1: 姓名 2: 年龄 3: 电话号码  4:地址 5:性别"<<endl;

        int select = 0;

        cin>>select;

        switch (select)
        {
        // 修改姓名
        case 1:{
            cout<<"请输入需要修改成的姓名"<<endl;
            string name;
            cin>>name;
            abs->personArray[ret].m_Name = name;
            break;
        }
            
        // 修改年龄
        case 2:{
            cout<<"请输入需要修改成的年龄"<<endl;
            int age;
            cin>>age;
            abs->personArray[ret].m_Age = age;
            break;
        }

        case 3:{
            cout<<"请输入需要修改的电话号码"<<endl;
            string phone_number;
            cin>>phone_number;
            abs->personArray[ret].m_Phone = phone_number;
            break;
        }
        
        case 4:{
            cout<<"请输入需要修改的地址"<<endl;
            string address;
            cin>>address;
            abs->personArray[ret].m_Addr = address;
            break;
        }

        case 5:{
            cout<<"请输入需要修改的性别"<<endl;
            int sex;
            cin>>sex;
            abs->personArray[ret].m_Sex = sex;
            break;
        }
        }
    }   
}

// 删除通讯录的所有信息
void del_Allperson(Addressbooks * abs){
    // 逻辑置空操作
    abs->m_Size = 0;
    cout<<"已将所有联系人清空!"<<endl;
}

int main(){
    //创建通讯录变量
    Addressbooks abs;
    abs.m_Size = 0;
    int select = 0;

    while (true)
    {
        showMenu();
        cin>> select;
        switch (select)
        {
        // for add
        case 1:{
            add_Person(&abs);
            break;
        } 
 
        // for show
        case 2:{
            show_Person(&abs);
            break;
        }
           
        // for del
        case 3:{
            cout<<"请输入姓名"<<endl;
            string name;
            cin>>name;
            if(is_Exist(&abs,name)==-1){
                cout<<"查无此人"<<endl;
            }else{
                cout<<"找到此人"<<endl;
                del_person(&abs);
            }
            break;
        }
            
        // for find
        case 4:{
            find_Person(&abs);
            break;
        }

        // moidfy_person
        case 5:{
            modify_Person(&abs);
            break;
        }
        // del_allperson
        case 6:{
            del_Allperson(&abs);
            break;
        }
        // for quit
        case 0:{
            cout<<"欢迎下次使用"<<endl;
            return 0;
            break;
        }
        default:
            break;
        }
    }
}
