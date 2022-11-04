#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char str[105];
int main()
{
    int n;
    scanf("%d",&n);
    gets(str);
    int res=1,h=0,m=-1,cnt=1;
    for(int i=0;i<n;i++)
    {
        gets(str);
        int th=10*(str[1]-'0')+(str[2]-'0');
        int tm=10*(str[4]-'0')+(str[5]-'0');
        if(th==12)th=0;
        if(str[7]=='p')th+=12;
        if(th<h || (th==h && tm<m))res++;
        if(th==h && tm==m)cnt++;
        else cnt=1;
        if(cnt==11)res++,cnt=1;
        h=th,m=tm;
    }
    printf("%d\n",res);
    return 0;
}