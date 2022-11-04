#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
vector<int> e[MAXN],f[MAXN];
int r[MAXN],k;
int mi[MAXN],mx[MAXN],vis[MAXN];
void dfs(int u)
{
    if(vis[u]==1)throw 1;
    if(vis[u]==2)return;
    vis[u]=1;
    mi[u]=1;
    for(auto &v:e[u])
    {
        dfs(v);
        mi[u]=max(mi[u],mi[v]+1);
    }
    if(mi[u]>k)throw 1;
    if(r[u])
    {
        if(mi[u]<=r[u])mi[u]=r[u];
        else throw 1;
    }
    vis[u]=2;
}
void rdfs(int u)
{
    if(vis[u]==1)throw 1;
    if(vis[u]==2)return;
    vis[u]=1;
    mx[u]=k;
    for(auto &v:f[u])
    {
        rdfs(v);
        mx[u]=min(mx[u],mx[v]-1);
    }
    if(mx[u]<1)throw 1;
    if(r[u])
    {
        if(mx[u]>=r[u])mx[u]=r[u];
        else throw 1;
    }
    vis[u]=2;
}
void solve(int n)
{
    memset(vis,0,(n+1)*sizeof(vis[0]));
    for(int i=1;i<=n;i++)
        if(!vis[i])dfs(i);
    memset(vis,0,(n+1)*sizeof(vis[0]));
    for(int i=1;i<=n;i++)
        if(!vis[i])rdfs(i);
}
int idx[MAXN];
void remark(int n)
{
    for(int i=1;i<=n;i++)
        idx[i]=i;
    sort(idx+1,idx+n+1,[](int x,int y){return mx[x]>mx[y];});
    priority_queue<pair<int,int> > pq;
    for(int i=k,j=1;i>=1;i--)
    {
        while(j<=n && mx[idx[j]]>=i)
            pq.push(make_pair(mi[idx[j]],idx[j])),j++;
        while(!pq.empty() && pq.top().first>i)
            pq.pop();
        if(pq.empty())throw 1;
        r[pq.top().second]=i;
        pq.pop();
    }
}
int main()
{
    int n,m;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&r[i]);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        f[y].push_back(x);
    }
    try
    {
        solve(n);
        remark(n);
        solve(n);
    }
    catch(...)
    {
        return 0*printf("-1\n");
    }
    for(int i=1;i<=n;i++)
        printf("%d%c",mi[i]," \n"[i==n]);
    return 0;
}