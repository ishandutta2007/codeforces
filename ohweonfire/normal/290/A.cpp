#include<string>  
#include<iostream>  
using namespace std;  
const string a[]={"Washington","Adams","Jefferson","Madison","Monroe","Adams","Jackson","Van Buren","Harrison","Tyler",  
"Polk","Taylor","Fillmore","Pierce","Buchanan","Lincoln","Johnson","Grant","Hayes","Garfield","Arthur",  
"Cleveland","Harrison","Cleveland","McKinley","Roosevelt","Taft","Wilson","Harding","Coolidge","Hoover","Roosevelt",  
"Truman","Eisenhower","Kennedy","Johnson","Nixon","Ford","Carter","Reagan","Bush","Clinton","Bush","Obama"};  
int main(){  
    int x;  
    cin>>x;  
    cout<<a[x-1]<<endl;  
    return 0;  
}