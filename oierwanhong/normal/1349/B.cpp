//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
const ll INF=1ll<<58;
/**********/
#define MAXN 300011
ll sum[MAXN],a[MAXN];
int main()
{
    ll T=read();
    while(T--)
    {
        ll n=read(),k=read();
        sum[0]=sum[n+1]=0;
        if(n==1){puts(k==read()?"yes":"no");continue;}
        bool flag=0,flag2=0;
        ll minv=INF;
        for(ll i=1;i<=n;++i)a[i]=read(),flag|=(a[i]==k);
        for(ll i=1;i<n;++i)
        {
            if(a[i]>=k&&a[i+1]>=k)flag2=1;
            if(i<n-1&&a[i]>=k&&a[i+2]>=k)flag2=1;
        }
        puts(flag&&flag2?"yes":"no");
    }
}