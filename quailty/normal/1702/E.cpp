#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
vector<int> e[MAXN];
bool vis[MAXN];
void dfs(int u,int& c)
{
    vis[u]=1,c++;
    for(auto v : e[u])
        if(!vis[v])dfs(v,c);
}
int solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        e[i].clear(),vis[i]=0;
    bool isok=1;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        isok&=(a!=b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    if(!isok)return 0*printf("NO\n");
    for(int i=1;i<=n;i++)
        isok&=(e[i].size()%2==0);
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        int c=0;
        dfs(i,c);
        isok&=(c%2==0);
    }
    return 0*printf("%s\n",isok ? "YES" : "NO");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}