#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=200005;
vector<int>e[MAXN];
int key[MAXN],dp[MAXN],mx[MAXN];
void dfs1(int u,int fa)
{
    dp[u]=key[u];
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa)continue;
        dfs1(v,u);
        dp[u]+=dp[v];
    }
}
void dfs2(int u,int fa)
{
    mx[u]=max(mx[u],dp[1]-dp[u]);
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa)continue;
        dfs2(v,u);
        mx[u]=max(mx[u],dp[v]);
    }
}
vector<int>id[MAXN];
void getId(int u,int fa,vector<int>&now)
{
    if(key[u])now.push_back(u);
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa)continue;
        getId(v,u,now);
    }
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for(int i=1;i<=2*k;i++)
    {
        int c;
        scanf("%d",&c);
        key[c]=1;
    }
    dfs1(1,0);
    dfs2(1,0);
    int rt=0;
    for(int i=1;i<=n;i++)
        if(mx[i]<=k)rt=i;
    printf("1\n%d\n",rt);
    int cnt=0;
    id[cnt++].push_back(rt);
    for(int i=0;i<(int)e[rt].size();i++)
        getId(e[rt][i],rt,id[cnt++]);
    priority_queue<pair<int,int> >pq;
    for(int i=0;i<cnt;i++)
        pq.push(make_pair((int)id[i].size(),i));
    for(int i=0;i<k;i++)
    {
        int l=pq.top().second;
        pq.pop();
        int r=pq.top().second;
        pq.pop();
        printf("%d %d %d\n",id[l].back(),id[r].back(),rt);
        id[l].pop_back();
        id[r].pop_back();
        pq.push(make_pair((int)id[l].size(),l));
        pq.push(make_pair((int)id[r].size(),r));
    }
    return 0;
}