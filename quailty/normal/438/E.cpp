#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const ll Mod=998244353;
const ll pmr=3;
ll fp(ll a,ll k)
{
    if(k<0)a=fp(a,Mod-2),k=-k;
    ll res=1;
    while(k)
    {
        if(k&1)(res*=a)%=Mod;
        (a*=a)%=Mod;
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
ll x1[MAXN<<2],x2[MAXN<<2];
void fft(ll y[],int len,int on)
{
    change(y,len);
    for(int h=2;h<=len;h<<=1)
    {
        ll wn=fp(pmr,-on*(Mod-1)/h);
        for(int j=0;j<len;j+=h)
        {
            ll w=1;
            for(int k=j;k<j+h/2;k++)
            {
                ll u=y[k];
                ll v=w*y[k+h/2]%Mod;
                y[k]=(u+v)%Mod;
                y[k+h/2]=(u-v+Mod)%Mod;
                (w*=wn)%=Mod;
            }
        }
    }
    if(on==-1)
    {
        ll tmp=fp(len,-1);
        for(int i=0;i<len;i++)
            (y[i]*=tmp)%=Mod;
    }
}
ll f[MAXN<<2],g[MAXN<<2];
void solve(int l,int r)
{
    if(l==r)return;
    int m=(l+r)/2;
    solve(l,m);
    int k=1;
    while(k<=r-l+1)k<<=1;
    if(r-l<l)for(int i=0;i<k;i++)
    {
        x1[i]=(i+l<=r ? 2*f[i]%Mod : 0);
        x2[i]=(i+l<=m ? f[i+l] : 0);
    }
    else for(int i=0;i<k;i++)
        x1[i]=x2[i]=(i+l<=m ? f[i+l] : 0);
    fft(x1,k,1);
    fft(x2,k,1);
    for(int i=0;i<k;i++)
        (x1[i]*=x2[i])%=Mod;
    fft(x1,k,-1);
    for(int i=0;i<k;i++)
    {
        x1[i]=(i+l<=r ? x1[i] : 0);
        x2[i]=(i+l<=r ? g[i] : 0);
    }
    fft(x1,k,1);
    fft(x2,k,1);
    for(int i=0;i<k;i++)
        (x1[i]*=x2[i])%=Mod;
    fft(x1,k,-1);
    for(int i=m+1;i<=r;i++)
        (f[i]+=x1[i-l])%=Mod;
    solve(m+1,r);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int c;
        scanf("%d",&c);
        g[c]=1;
    }
    int t=1;
    while(t<=m)t<<=1;
    f[0]=1;
    solve(0,t-1);
    for(int i=1;i<=m;i++)
        printf("%I64d\n",f[i]);
    return 0;
}