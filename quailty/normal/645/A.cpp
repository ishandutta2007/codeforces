#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[15],t[15];
int main()
{
    scanf("%s%s",s,s+2);
    swap(s[2],s[3]);
    int loc=0;
    for(int i=0;i<4;i++)
        if(s[i]=='X')loc=i;
    for(int i=loc;i+1<4;i++)
        swap(s[i],s[i+1]);
    scanf("%s%s",t,t+2);
    swap(t[2],t[3]);
    for(int i=0;i<4;i++)
        if(t[i]=='X')loc=i;
    for(int i=loc;i+1<4;i++)
        swap(t[i],t[i+1]);
    while(t[0]!=s[0])
    {
        char p=t[0];
        for(int i=0;i<2;i++)t[i]=t[i+1];
        t[2]=p;
    }
    printf("%s\n",strcmp(s,t)==0 ? "YES" : "NO");
    return 0;
}