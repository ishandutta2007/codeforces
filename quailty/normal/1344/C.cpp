#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
vector<int> e[MAXN],r[MAXN];
int vis1[MAXN];
void dfs1(int u)
{
    vis1[u]=1;
    for(auto &v:e[u])
    {
        if(!vis1[v])dfs1(v);
        else if(vis1[v]==1)throw 0;
    }
    vis1[u]=2;
}
int vis2[MAXN];
void dfs2(int u)
{
    vis2[u]=1;
    for(auto &v:r[u])
    {
        if(!vis2[v])dfs2(v);
        else if(vis2[v]==1)throw 0;
    }
    vis2[u]=2;
}
char res[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        r[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        try
        {
           if(!vis1[i])dfs1(i);
        }
        catch(...)
        {
            return 0*printf("-1\n");
        }
    }
    for(int i=1;i<=n;i++)
        vis1[i]=vis2[i]=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(vis1[i] || vis2[i])res[i]='E';
        else res[i]='A',cnt++;
        if(!vis1[i])dfs1(i);
        if(!vis2[i])dfs2(i);
    }
    return 0*printf("%d\n%s\n",cnt,res+1);
}