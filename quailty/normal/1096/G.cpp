#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
const ll Mod=998244353;
const ll g=3;
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
ll fp(ll a,ll k)
{
    if(k<0)
    {
        a=fp(a,Mod-2);
        k=-k;
    }
    ll res=1;
    while(k)
    {
        if(k&1)res=res*a%Mod;
        a=a*a%Mod;
        k>>=1;
    }
    return res;
}
void ntt(ll y[],int len,int on)
{
    change(y,len);
    for(int h=2;h<=len;h<<=1)
    {
        ll wn=fp(g,-on*(Mod-1)/h);
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
        ll t=fp(len,-1);
        for(int i=0;i<len;i++)
            y[i]=y[i]*t%Mod;
    }
}
ll x[MAXN*10];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
    {
        int d;
        scanf("%d",&d);
        x[d]=1;
    }
    int len=1;
    while(len<n*5)len<<=1;
    ntt(x,len,1);
    for(int i=0;i<len;i++)
        x[i]=fp(x[i],n/2);
    ntt(x,len,-1);
    ll res=0;
    for(int i=0;i<len;i++)
        res=(res+x[i]*x[i])%Mod;
    printf("%lld\n",res);
    return 0;
}