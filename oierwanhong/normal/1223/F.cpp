//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
/**********/
#define MAXN 500011
ll a[MAXN],f[MAXN],nxt[MAXN];
std::map<ll,ll>p[MAXN];
int main()
{
    ll task=read();
    while(task--)
    {
        ll n=read(),ans=0;
        for(ll i=1;i<=n;++i)a[i]=read();
        for(ll i=0;i<=n;++i)p[i].clear(),nxt[i]=0,f[i]=0;
        for(ll i=1;i<=n;++i)
        {
            if(p[i-1][a[i]])
            {
                ll pos=p[i-1][a[i]];
                f[i]=f[pos-1]+1;
                ans+=f[i];
                std::swap(p[i],p[pos-1]);
                if(pos>1)p[i][a[pos-1]]=pos-1;
            }
            p[i][a[i]]=i;
        }
        printf("%lld\n",ans);
    }
}