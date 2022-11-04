#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=3005;
const int MAXQ=400005;
vector<int> g[MAXN],h[MAXN];
struct query
{
    int s,k,id;
};
vector<query> r[MAXN];
int vis[MAXN],res[MAXQ];
int go[13][MAXN];
void dfs(int u)
{
    if(vis[u])return;
    vis[u]=1;
    for(int i=0;i<(int)h[u].size();i++)
        dfs(h[u][i]);
}
int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        h[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        sort(g[i].begin(),g[i].end());
    for(int i=1;i<=q;i++)
    {
        int s,t,k;
        scanf("%d%d%d",&s,&t,&k);
        r[t].push_back(query{s,k,i});
    }
    for(int t=1;t<=n;t++)
    {
        memset(vis,0,(n+1)*sizeof(vis[0]));
        dfs(t);
        for(int i=1;i<=n;i++)
        {
            if(i==t)go[0][i]=n+1;
            else
            {
                go[0][i]=0;
                if(vis[i])for(int j=0;j<(int)g[i].size();j++)
                    if(vis[g[i][j]])
                    {
                        go[0][i]=g[i][j];
                        break;
                    }
            }
        }
        go[0][n+1]=n+1;
        for(int _=1;_<=12;_++)
            for(int i=1;i<=n+1;i++)
                go[_][i]=go[_-1][go[_-1][i]];
        for(int i=0;i<(int)r[t].size();i++)
        {
            int s=r[t][i].s,k=r[t][i].k-1,id=r[t][i].id;
            if(go[12][s]==t || go[12][s]==n+1)
            {
                for(int _=0;_<=12;_++)
                    if(k>>_&1)s=go[_][s];
                res[id]=(s>n ? -1 : s);
            }
            else res[id]=-1;
        }
    }
    for(int i=1;i<=q;i++)
        printf("%d\n",res[i]);
    return 0;
}