#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
vector<pair<int,ll> > e[MAXN];
vector<ll> base;
void add(ll x)
{
    for(int i=0;i<(int)base.size();i++)
        x=min(x,x^base[i]);
    if(x)base.push_back(x);
}
int vis[MAXN];
ll t[MAXN];
void dfs(int u,ll now)
{
    vis[u]=1,t[u]=now;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].first;
        if(vis[v])add(now^e[u][i].second^t[v]);
        else dfs(v,now^e[u][i].second);
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        ll w;
        scanf("%d%d%lld",&x,&y,&w);
        e[x].push_back(make_pair(y,w));
        e[y].push_back(make_pair(x,w));
    }
    dfs(1,0);
    for(int i=0;i<(int)base.size();i++)
        t[n]=min(t[n],t[n]^base[i]);
    return 0*printf("%lld\n",t[n]);
}