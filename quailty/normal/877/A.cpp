#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const string name[5]={"Danil","Olya","Slava","Ann","Nikita"};
int main()
{
    string str;
    cin>>str;
    int cnt=0;
    for(int i=0;i<5;i++)
        for(int j=0;j<=(int)str.size()-(int)name[i].size();j++)
            cnt+=(name[i]==str.substr(j,name[i].size()));
    printf("%s\n",(cnt==1 ? "YES" : "NO"));
    return 0;
}