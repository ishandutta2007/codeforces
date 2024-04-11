#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int la,t[15],res[100005];
char str[15],tmp[15];
int cal(int m,int len)
{
    for(int i=0;i<len;i++)
    {
        tmp[++tmp[0]]=m%10+'0';
        m/=10;
    }
    int res=0;
    for(int i=0;str[i];i++)
    {
        if(str[i]!='?')res=res*10+str[i]-'0';
        else res=res*10+tmp[tmp[0]--]-'0';
    }
    return res;
}
int check()
{
    int len=0;
    for(int i=0;str[i];i++)
        len+=(str[i]=='?');
    int l=(str[0]=='?')*t[len-1],r=t[len];
    while(l<r)
    {
        int m=(l+r)/2;
        if(cal(m,len)>la)r=m;
        else l=m+1;
    }
    return (l<t[len] ? cal(l,len) : -1);
}
int main()
{
    for(int i=(t[0]=1);i<10;i++)
        t[i]=10*t[i-1];
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",str);
        int s=check();
        if(s>0)res[i]=la=s;
        else return 0*printf("NO\n");
    }
    printf("YES\n");
    for(int i=1;i<=n;i++)
        printf("%d\n",res[i]);
    return 0;
}