#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
const int Mod=998244353;
int C[MAXN][MAXN];
struct DSU
{
    int fa[MAXN],sz[MAXN],cnt[MAXN],dp[MAXN][MAXN];
    void init(int n)
    {
        for(int i=1;i<=n;i++)
        {
            fa[i]=i,sz[i]=1,cnt[i]=0;
            for(int j=0;j<=n;j++)
                dp[i][j]=(j==1);
        }
    }
    int find(int x)
    {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    void merge(int x,int y)
    {
        x=find(x),y=find(y);
        if(x==y)
        {
            ++cnt[x];
            return;
        }
        fa[x]=y;
        cnt[y]+=cnt[x]+1;
        static int tmp[MAXN];
        for(int i=0;i<=sz[x]+sz[y];i++)tmp[i]=0;
        for(int i=0;i<=sz[x];i++)
            for(int j=0;j<=sz[y];j++)
                tmp[i+j]=(tmp[i+j]+1LL*C[i+j][i]*dp[x][i]%Mod*dp[y][j])%Mod;
        for(int i=0;i<=sz[x]+sz[y];i++)dp[y][i]=tmp[i];
        sz[y]+=sz[x];
    }
}dsu;
int main()
{
    for(int i=(C[0][0]=1);i<MAXN;i++)
        for(int j=(C[i][0]=1);j<MAXN;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
    int n;
    scanf("%d",&n);
    static int x[MAXN],y[MAXN];
    for(int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);
    vector<tuple<int,int,int>> edges;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            edges.emplace_back(abs(x[i]-x[j])+abs(y[i]-y[j]),i,j);
    sort(edges.begin(),edges.end());
    dsu.init(n);
    vector<int> vis(n+1,-1);
    for(int i=0,j=0;i<(int)edges.size();i=j)
    {
        while(j<(int)edges.size() && get<0>(edges[i])==get<0>(edges[j]))j++;
        for(int k=i;k<j;k++)
            dsu.merge(get<1>(edges[k]),get<2>(edges[k]));
        for(int k=i;k<j;k++)
        {
            int u=dsu.find(get<1>(edges[k]));
            if(vis[u]==i)continue;
            if(dsu.cnt[u]==dsu.sz[u]*(dsu.sz[u]-1)/2)
                dsu.dp[u][1]=(dsu.dp[u][1]+1)%Mod;
            dsu.cnt[u]=0,vis[u]=i;
        }
    }
    int rt=dsu.find(1),res=0;
    for(int i=1;i<=n;i++)
        res=(res+1LL*C[n][i]*dsu.dp[rt][i])%Mod;
    return 0*printf("%d\n",res);
}