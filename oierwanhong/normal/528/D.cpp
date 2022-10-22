#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
typedef long long ll;
typedef unsigned un;
//typedef std::string str;
typedef std::pair<ll,ll> pll;
typedef std::pair<int,int> pii;
typedef std::pair<double,double> pd;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
bool umin(ll& a,ll t){if(t<a)return a=t,1;return 0;}
const ll INF=1ll<<50;
#define MAXN 800011
const ll mod=998244353;
ll Qpow(ll a,ll p)
{
    ll res=1;
    while(p)
    {
        if(p&1)res=res*a%mod;
        a=a*a%mod,p>>=1;
    }
    return res;
}
ll inv3=Qpow(3,mod-2);
int status[MAXN];
void DFT(ll* a,int len,int type)
{
    for(int i=0;i<len;++i)
        if(status[i]>i)std::swap(a[i],a[status[i]]);
    for(int cur=1;cur<len;cur<<=1)
    {
        ll r=Qpow(type==1?3:inv3,(mod-1)/(cur<<1));
        for(int j=0;j<len;j+=cur<<1)
        {
            ll w=1;
            for(int k=0;k<cur;++k,w=w*r%mod)
            {
                ll x=a[j+k],y=w*a[j+cur+k];
                a[j+k]=(x+y)%mod,a[j+cur+k]=(x-y)%mod;
            }
        }
    }
    if(type==-1)
    {
        ll inv_len=Qpow(len,mod-2);
        for(int i=0;i<len;++i)a[i]=(a[i]*inv_len%mod+mod)%mod;
    }
}
char s[MAXN],t[MAXN],ch[]={'A','C','G','T'};
ll f[MAXN],g[MAXN],sum[MAXN];
int main()
{
    int la=read(),lb=read(),k=read();
    int len=1;
    while(len<=la+lb)len<<=1;
    for(int i=0;i<len;++i)
        status[i]=(status[i>>1]>>1)|((i&1)*(len>>1));
    scanf("%s%s",s,t);
    std::reverse(t,t+lb);
    for(int x=0;x<4;++x)
    {
        char c=ch[x];
        int cnt=0;
        for(int i=0;i<k;++i)cnt+=(s[i]==c);
        for(int i=0;i<la;++i)
        {
            if(i+k<la)cnt+=(s[i+k]==c);
            if(i-k-1>=0)cnt-=(s[i-k-1]==c);
            f[i]=!!cnt;
        }
        for(int i=0;i<lb;++i)g[i]=(t[i]==c);
        DFT(f,len,1),DFT(g,len,1);
        for(int i=0;i<len;++i)f[i]=f[i]*g[i]%mod;
        DFT(f,len,-1);
        for(int i=0;i<len;++i)sum[i]=(sum[i]+f[i])%mod,f[i]=g[i]=0;
    }
    int ans=0;
    for(int i=lb-1;i<la;++i)
        if(sum[i]==lb)++ans;
    printf("%d",ans);
    return 0;
}