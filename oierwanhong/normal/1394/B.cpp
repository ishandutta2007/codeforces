#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<ctime>
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
#define MAXN 200011
std::vector<pii>g[MAXN];
ll f1[15][15],f2[15][15];
ll val1[MAXN],val2[MAXN],all1=0,all2=0,n,m,k,ans=0;
void dfs(int x,ll now1,ll now2)
{
    if(x>k){ans+=(now1==all1&&now2==all2);return;}
    for(int i=0;i<x;++i)
    {
        dfs(x+1,now1+f1[x][i],now2+f2[x][i]);
    }
}
int main()
{
    srand(time(0));
    n=read(),m=read(),k=read();
    for(int i=1;i<=n;++i)val1[i]=rand(),all1+=val1[i],val2[i]=rand(),all2+=val2[i];
    for(int i=1;i<=m;++i)
    {
        int u=read(),v=read(),w=read();
        g[u].push_back(pii(w,v));
    }
    for(int u=1;u<=n;++u)
    {
        std::sort(g[u].begin(),g[u].end());
        for(int j=0;j<g[u].size();++j)f1[g[u].size()][j]+=val1[g[u][j].second],f2[g[u].size()][j]+=val2[g[u][j].second];
    }
    dfs(1,0,0);
    printf("%lld",ans);
    return 0;
}