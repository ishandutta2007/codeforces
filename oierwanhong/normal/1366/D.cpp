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
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
const ll INF=1ll<<58;
/**********/
#define MAXE 20000011
ll vis[MAXE];
ll prime[MAXE/8],cnt=0;
void sieve()
{
    vis[1]=1;
    for(int i=2;i<MAXE;++i)
    {
        if(!vis[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&i*prime[j]<MAXE;++j)
        {
            vis[i*prime[j]]=prime[j];
            if(i%prime[j]==0)break;
        }
    }
}
int ans1[1000011],ans2[1000011];
int main()
{
    sieve();
    int n=read();
    for(int w=1;w<=n;++w)
    {
        int x=read();
        if(vis[x])
        {
            ll k=vis[x],p=1;
            while(x%k==0)x/=k,p*=k;
            if(x>1)ans1[w]=p,ans2[w]=x;
        }
    }
    for(int i=1;i<=n;++i)printf("%d ",ans1[i]?ans1[i]:-1ll);
    puts("");
    for(int i=1;i<=n;++i)printf("%d ",ans2[i]?ans2[i]:-1ll);
    return 0;
}