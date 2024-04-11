#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
char s[200005];
set<int>st;
int main()
{
    int n,t,d;
    scanf("%d%d%s",&n,&t,s);
    for(int i=0;i<n;i++)
        if(s[i]=='.')d=i;
    for(int i=d+1;i<n;i++)
        if(s[i]>='5')st.insert(i);
    int now=n;
    while(t--)
    {
        if(st.empty() || *st.begin()>=now || *st.begin()<d)break;
        int u=*st.begin();
        if(s[u-1]=='.')u--;
        if(++s[u-1]>='5')st.insert(u-1);
        now=u;
    }
    bool flag=0;
    for(int i=d-1;i>=0;i--)
    {
        if(i)s[i-1]+=(s[i]-'0')/10;
        else if(s[i]>'9')flag=1;
        s[i]=(s[i]-'0')%10+'0';
    }
    if(flag)printf("1");
    for(int i=0;i<now;i++)
        printf("%c",s[i]);
    return 0;
}