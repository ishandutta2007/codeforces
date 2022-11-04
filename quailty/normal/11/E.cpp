#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1000005;
const ll MAXP=100000000;
const char sig[2]={'L','R'};
char s[MAXN],t[MAXN<<1];
ll cal(int n)
{
    ll l=0,r=MAXP;
    while(l<r)
    {
        ll m=(l+r+1)/2;
        ll p[2]={-MAXP,0},tp[2];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<2;j++)
                tp[j]=max(p[j^1],p[j]-m)+(t[i]==sig[j])*MAXP;
            for(int j=0;j<2;j++)
                p[j]=tp[j]-m;
        }
        if(max(p[0]-m,p[1])>=0)l=m;
        else r=m-1;
    }
    return l;
}
int main()
{
    scanf("%s",s);
    int n=0;
    for(int i=0;s[i];i++)
    {
        if(i>0 && s[i]!='X' && s[i]==t[n-1])t[n++]='X';
        t[n++]=s[i];
    }
    bool flag=0;
    if(t[n-1]!='X' && t[n-1]==t[0])
    {
        t[n++]='X';
        flag=1;
    }
    ll res=0;
    for(int i=0;i<n;i++)
        res+=(t[i]!='X');
    res=res/(2.0*(n|1))*MAXP+1e-2;
    res=max(res,cal(n));
    if(flag)
    {
        for(int i=n-2;i>=0;i--)
            swap(t[i],t[i+1]);
        res=max(res,cal(n));
    }
    printf("%I64d.%06I64d\n",res/1000000,res%1000000);
    return 0;
}