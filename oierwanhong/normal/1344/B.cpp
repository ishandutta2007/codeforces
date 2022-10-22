//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
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
#define MAXN 1011
char a[MAXN][MAXN];
bool vis[MAXN][MAXN];
ll ans=0;
const ll mx[]={0,1,0,-1},my[]={1,0,-1,0};
void dfs(ll x,ll y)
{
    a[x][y]=0;
    for(ll i=0;i<4;++i)
    {
        ll vx=x+mx[i],vy=y+my[i];
        if(a[vx][vy]=='#')dfs(vx,vy);
    }
}
int main()
{
    ll n=read(),m=read();
    for(ll i=1;i<=n;++i)scanf("%s",a[i]+1);
    for(ll x=1;x<=n;++x)
    {
        bool flag=0,cur=0;
        for(ll y=1;y<=m;++y)
            if(a[x][y]=='#')
            {
                if(!flag||cur)flag=1,cur=1;
                else return puts("-1")&0;
            }
            else cur=0;
        if(flag)
            for(ll y=1;y<=m;++y)vis[x][y]=1;
    }
    for(ll y=1;y<=m;++y)
    {
        bool flag=0,cur=0;
        for(ll x=1;x<=n;++x)
            if(a[x][y]=='#')
            {
                if(!flag||cur)flag=1,cur=1;
                else return puts("-1")&0;
            }
            else cur=0;
        if(flag)
            for(ll x=1;x<=n;++x)vis[x][y]=1;
    }
    for(ll x=1;x<=n;++x)
    {
        bool f=0;
        for(ll y=1;y<=m;++y)
            if(!vis[x][y]||a[x][y]=='#')f=1;
        if(!f)return puts("-1")&0;
    }
    for(ll y=1;y<=m;++y)
    {
        bool f=0;
        for(ll x=1;x<=n;++x)
            if(!vis[x][y]||a[x][y]=='#')f=1;
        if(!f)return puts("-1")&0;
    }
    for(ll x=1;x<=n;++x)
        for(ll y=1;y<=m;++y)
            if(a[x][y]=='#')++ans,dfs(x,y);
    return printf("%lld",ans)&0;
}