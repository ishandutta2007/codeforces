#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5005;//
const int MAXM = 5005;//
struct Edge
{
    int to,next;
} edge[MAXM];
int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];//Belong1~scc
int Index,top;
int scc;//
bool Instack[MAXN];
void addedge(int u,int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void Tarjan(int u)
{
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        v = edge[i].to;
        if( !DFN[v] )
        {
            Tarjan(v);
            if( Low[u] > Low[v] )Low[u] = Low[v];
        }
        else if(Instack[v] && Low[u] > DFN[v])
            Low[u] = DFN[v];
    }
    if(Low[u] == DFN[u])
    {
        scc++;
        do
        {
            v = Stack[--top];
            Instack[v] = false;
            Belong[v] = scc;
        }
        while( v != u);
    }
}
void solve(int N)
{
    memset(DFN,0,sizeof(DFN));
    memset(Instack,0,sizeof(Instack));
    Index = scc = top = 0;
    for(int i = 1; i <= N; i++)
        if(!DFN[i])
            Tarjan(i);
}
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}
int u[MAXN],v[MAXN],in[MAXN],vis[MAXN];
vector<int> dag[MAXN];
void dfs(int u)
{
    vis[u]=1;
    for(auto &v:dag[u])
        if(!vis[v])dfs(v);
}
int main()
{
    int n,m,s;
    scanf("%d%d%d",&n,&m,&s);
    init();
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        addedge(u[i],v[i]);
    }
    solve(n);
    for(int i=1;i<=m;i++)
    {
        if(Belong[u[i]]==Belong[v[i]])continue;
        dag[Belong[u[i]]].push_back(Belong[v[i]]);
        in[Belong[v[i]]]++;
    }
    dfs(Belong[s]);
    int res=0;
    for(int i=1;i<=scc;i++)
        res+=(!in[i] && !vis[i]);
    printf("%d\n",res);
    return 0;
}