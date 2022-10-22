//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
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
#define MAXN 1000011
ll phi[MAXN],pri[MAXN],cnt=0;
bool vis[MAXN];
void sieve()
{
	phi[1]=1;
    for(ll i=2;i<MAXN;++i)
    {
        if(!vis[i])
        {
            pri[++cnt]=i;
            phi[i]=i-1;
        }
        for(ll j=1;j<=cnt&&i*pri[j]<MAXN;++j)
        {
            vis[i*pri[j]]=1;
            if(i%pri[j]==0)
            {
                phi[i*pri[j]]=phi[i]*pri[j];break;
            }
            phi[i*pri[j]]=phi[i]*phi[pri[j]];
        }
    }
}
int main()
{
    sieve();
    ll n=read(),k=read()+2,ans=0;
    if(k==3){puts("3");return 0;}
    std::sort(phi+1,phi+n+1);
    for(ll i=1;i<=k;++i)ans+=phi[i];
    std::cout<<ans;
}