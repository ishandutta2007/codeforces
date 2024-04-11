//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
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
#define MAXN 10011
ll a[MAXN],b[MAXN];
bool vis[10011];
int main()
{
    ll t=read();
    while(t--)
    {
        ll n=read(),k=read(), len;
        for(ll i=1;i<=n;++i)vis[i]=0;
        for(ll i=1;i<=n;++i)b[i]=a[i]=read(),vis[a[i]]=1;
        std::sort(b+1,b+n+1);len=std::unique(b+1,b+n+1)-b-1;
        if(len>k){puts("-1");continue;}
        ll pos=b[len];
        while(len<k)
        {
        	while(vis[pos])pos=pos%n+1;
        	vis[pos]=1,b[++len]=pos;pos=pos%n+1;
		}
        printf("%lld\n",k*n);
        for(ll i=1;i<=n;++i)
        	for(ll j=1;j<=k;++j)printf("%lld ",b[j]);
        puts("");
    }
}