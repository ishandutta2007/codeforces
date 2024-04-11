#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
vector<pair<int,int>> e[MAXN];
int res[MAXN];
void dfs(int u,int fa,int c)
{
    for(auto& [v,idx] : e[u])
    {
        if(v==fa)continue;
        res[idx]=c;
        dfs(v,u,5-c);
    }
}
void solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        e[i].clear();
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].emplace_back(v,i);
        e[v].emplace_back(u,i);
    }
    int rt=0;
    for(int i=1;i<=n;i++)
    {
        if(e[i].size()==1u)rt=i;
        if(e[i].size()>2u)
        {
            printf("-1\n");
            return;
        }
    }
    dfs(rt,0,2);
    for(int i=1;i<n;i++)
        printf("%d%c",res[i]," \n"[i==n-1]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}