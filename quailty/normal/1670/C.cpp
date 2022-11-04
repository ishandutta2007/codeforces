#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
const int Mod=1000000007;
int a[MAXN],b[MAXN];
bool vis[MAXN],usd[MAXN];
vector<int> e[MAXN];
bool dfs(int u,int& cnt)
{
    vis[u]=1,cnt++;
    bool ok=usd[u];
    for(auto v : e[u])
    {
        if(vis[v])continue;
        ok|=dfs(v,cnt);
    }
    return ok;
}
int solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
    {
        e[a[i]].push_back(b[i]);
        e[b[i]].push_back(a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int d;
        scanf("%d",&d);
        usd[d]=1;
    }
    int res=1;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        int cnt=0;
        if(!dfs(i,cnt) && cnt>1)res=res*2%Mod;
    }
    for(int i=1;i<=n;i++)
        e[i].clear(),usd[i]=vis[i]=0;
    return 0*printf("%d\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}