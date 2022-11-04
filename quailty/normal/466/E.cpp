#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int t[MAXN],x[MAXN],y[MAXN],la[MAXN];
int fa[MAXN][20],ti[MAXN][20],dep[MAXN];
vector<int>e[MAXN];
void dfs(int u)
{
    for(int i=1;i<20;i++)
    {
        fa[u][i]=fa[fa[u][i-1]][i-1];
        ti[u][i]=max(ti[u][i-1],ti[fa[u][i-1]][i-1]);
    }
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        dep[v]=dep[u]+1;
        dfs(v);
    }
}
pair<int,int> goUp(int u,int d)
{
    int res=0;
    for(int i=0;i<20;i++)
        if(d&(1<<i))
        {
            res=max(res,ti[u][i]);
            u=fa[u][i];
        }
    return make_pair(u,res);
}
int main()
{
    int n,m,cnt=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&t[i],&x[i]);
        if(t[i]==1)
        {
            scanf("%d",&y[i]);
            fa[x[i]][0]=y[i];
            ti[x[i]][0]=i;
            e[y[i]].push_back(x[i]);
        }
        else if(t[i]==2)
            la[++cnt]=i;
        else if(t[i]==3)
            scanf("%d",&y[i]);
    }
    for(int i=1;i<=n;i++)
        if(!fa[i][0])dfs(i);
    for(int i=1;i<=m;i++)
        if(t[i]==3)
        {
            int s=x[la[y[i]]],t=x[i];
            if(dep[s]<dep[t] || goUp(s,dep[s]-dep[t]).first!=t)printf("NO\n");
            else printf("%s\n",(goUp(s,dep[s]-dep[t]).second<=la[y[i]] ? "YES" : "NO"));
        }
    return 0;
}