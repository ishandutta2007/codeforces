#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
ll a[MAXN],sz[MAXN];
vector<pair<int,ll> >e[MAXN];
int dfs1(int u)
{
    sz[u]=1;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].first;
        sz[u]+=dfs1(v);
    }
    return sz[u];
}
int dfs2(int u,ll ma)
{
    if(ma>a[u])return sz[u];
    int res=0;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].first;
        ll w=e[u][i].second;
        res+=dfs2(v,max(0LL,ma+w));
    }
    return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    for(int i=2;i<=n;i++)
    {
        ll p,c;
        scanf("%I64d%I64d",&p,&c);
        e[p].push_back(make_pair(i,c));
    }
    dfs1(1);
    printf("%d\n",dfs2(1,0));
    return 0;
}