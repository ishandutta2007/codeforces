#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
const int MAXM = 600005;
struct Edge
{
    int to,next;
} edge[MAXM];
int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];
int Index,top;
int block;
bool Instack[MAXN];
void addedge(int u,int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void Tarjan(int u,int pre)
{
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        v = edge[i].to;
        if(v == pre)continue;
        if( !DFN[v] )
        {
            Tarjan(v,u);
            if( Low[u] > Low[v] )Low[u] = Low[v];
        }
        else if( Instack[v] && Low[u] > DFN[v] )
            Low[u] = DFN[v];
    }
    if(Low[u] == DFN[u])
    {
        block++;
        do
        {
            v = Stack[--top];
            Instack[v] = false;
            Belong[v] = block;
        }
        while( v!=u );
    }
}
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}
vector<int> tree[MAXN];
int dp[MAXN],res;
void dfs(int u,int f)
{
    for(auto &v:tree[u])
    {
        if(v==f)continue;
        dfs(v,u);
        res=max(res,dp[u]+dp[v]+1);
        dp[u]=max(dp[u],dp[v]+1);
    }
}
void solve(int n)
{
    memset(DFN,0,sizeof(DFN));
    memset(Instack,false,sizeof(Instack));
    Index = top = block = 0;
    Tarjan(1,0);
    for(int u=1;u<=n;u++)
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(Belong[u]!=Belong[v])
                tree[Belong[u]].push_back(Belong[v]);
        }
    dfs(1,0);
    printf("%d\n",res);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    init();
    for(int i=1; i<=m; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        addedge(x,y);
        addedge(y,x);
    }
    solve(n);
    return 0;
}