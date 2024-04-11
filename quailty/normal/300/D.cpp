#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll Mod=7340033;
const ll g=3;
ll fp(ll a,ll k)
{
    ll res=1;
    while(k)
    {
        if(k&1)res=res*a%Mod;
        a=a*a%Mod;
        k>>=1;
    }
    return res;
}
void change(ll y[],int len)
{
    for(int i=1,j=len/2;i<len-1;i++)
    {
        if(i<j)swap(y[i],y[j]);
        int k=len/2;
        while(j>=k)
        {
            j-=k;
            k/=2;
        }
        if(j<k)j+=k;
    }
}
void fft(ll y[],int len,int on)
{
    change(y,len);
    for(int h=2;h<=len;h<<=1)
    {
        ll wn=fp(g,(Mod-1)/h);
        if(on==-1)wn=fp(wn,Mod-2);
        for(int j=0;j<len;j+=h)
        {
            ll w=1;
            for(int k=j;k<j+h/2;k++)
            {
                ll u=y[k];
                ll t=w*y[k+h/2]%Mod;
                y[k]=(u+t)%Mod;
                y[k+h/2]=(u-t+Mod)%Mod;
                w=w*wn%Mod;
            }
        }
    }
    if(on==-1)
    {
        ll inv=fp(len,Mod-2);
        for(int i=0;i<len;i++)
            y[i]=y[i]*inv%Mod;
    }
}
const int DEG=35;
const int MAXK=1005;
ll x[MAXK<<3];
ll dp[DEG][MAXK];
void prepare()
{
    for(int j=0;j<=1000;j++)
        dp[0][j]=(j==0);
    int len=1;
    while(len<4*MAXK)len<<=1;
    for(int i=1;i<=30;i++)
    {
        memset(x,0,sizeof(x));
        for(int j=0;j<=1000;j++)
            x[j]=dp[i-1][j];
        fft(x,len,1);
        for(int j=0;j<=len;j++)
            x[j]=x[j]*x[j]%Mod*x[j]%Mod*x[j]%Mod;
        fft(x,len,-1);
        for(int j=0;j<=1000;j++)
            dp[i][j]=(j==0 ? 1 : x[j-1]);
    }
}
int dep(int n)
{
    int res=0;
    while(n>1 && n%2)
    {
        res++;
        n/=2;
    }
    return res;
}
int main()
{
    prepare();
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        printf("%I64d\n",dp[dep(n)][k]);
    }
    return 0;
}