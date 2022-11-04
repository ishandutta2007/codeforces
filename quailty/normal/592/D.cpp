#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=123456+5;
vector<int>e[MAXN];
int cnt[MAXN],dep[MAXN][2];
int len[MAXN],res[MAXN];
void dfs1(int u,int fa)
{
    int key=cnt[u];
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa)continue;
        dfs1(v,u);
        len[1]+=(cnt[v]>0);
        cnt[u]+=cnt[v];
        for(int j=0;j<2;j++)
            if(dep[v][0]>=dep[u][j])
            {
                for(int _=1;_>j;_--)
                    dep[u][_]=dep[u][_-1];
                dep[u][j]=dep[v][0];
                break;
            }
    }
    for(int j=0;j<2;j++)
        dep[u][j]+=(dep[u][j]>=0);
    if(key)for(int j=0;j<2;j++)
        if(dep[u][j]<=0)
        {
            for(int _=1;_>j;_--)
                dep[u][_]=dep[u][_-1];
            dep[u][j]=0;
            break;
        }
}
void dfs2(int u,int fa,int mx,int m)
{
    res[u]=2*len[u]-max(mx,dep[u][0]);
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa)continue;
        len[v]=len[u]+(cnt[v]==0)-(cnt[v]==m);
        int tx=max(mx,dep[u][dep[v][0]+1==dep[u][0]]);
        dfs2(v,u,tx+(tx>=0),m);
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=m;i++)
    {
        int d;
        scanf("%d",&d);
        cnt[d]=1;
    }
    memset(dep,0xf0,sizeof(dep));
    dfs1(1,0);
    dfs2(1,0,-1,m);
    int loc=1;
    for(int i=1;i<=n;i++)
        if(res[i]<res[loc])loc=i;
    printf("%d\n%d\n",loc,res[loc]);
    return 0;
}