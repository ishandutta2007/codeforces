#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
vector<pair<int,int>> e[MAXN];
int vis[MAXN];
bool dfs(int u,int siz[])
{
    siz[vis[u]]++;
    for(auto& t : e[u])
    {
        int v=t.first;
        int c=t.second;
        if(vis[v]==-1)
        {
            vis[v]=vis[u]^c;
            if(!dfs(v,siz))return 0;
        }
        else if(vis[v]!=(vis[u]^c))
            return 0;
    }
    return 1;
}
void solve()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        char str[15];
        scanf("%d%d%s",&u,&v,str);
        e[u].emplace_back(v,str[0]=='i');
        e[v].emplace_back(u,str[0]=='i');
    }
    for(int i=1;i<=n;i++)
        vis[i]=-1;
    int isok=1,res=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]>=0)continue;
        int siz[2]={0,0};
        vis[i]=0;
        isok&=dfs(i,siz);
        res+=max(siz[0],siz[1]);
    }
    printf("%d\n",(isok ? res : -1));
    for(int i=1;i<=n;i++)
        e[i].clear();
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}