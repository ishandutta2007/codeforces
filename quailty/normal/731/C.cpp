#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
int col[MAXN],cnt[MAXN],vis[MAXN];
vector<int>edge[MAXN],now;
void dfs(int u)
{
    if(vis[u])return;
    now.push_back(u);
    vis[u]=1;
    for(int i=0;i<(int)edge[u].size();i++)
        dfs(edge[u][i]);
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&col[i]);
    for(int i=1;i<=m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        edge[l].push_back(r);
        edge[r].push_back(l);
    }
    int res=n;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        now.clear();
        dfs(i);
        for(int j=0;j<(int)now.size();j++)
            cnt[col[now[j]]]++;
        int tmp=0;
        for(int j=0;j<(int)now.size();j++)
            tmp=max(tmp,cnt[col[now[j]]]);
        res-=tmp;
        for(int j=0;j<(int)now.size();j++)
            cnt[col[now[j]]]--;

    }
    return 0*printf("%d",res);
}