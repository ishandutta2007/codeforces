#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=400005;
const int MAXM=400005;
struct Edge
{
    int to,nxt;
} edge[MAXM<<1];
int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN],Size[MAXN];
int Index,top,block;
bool Instack[MAXN];
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}
int u[MAXM],v[MAXM],res[MAXM];
void addedge(int u,int v)
{
    edge[tot].to = v;
    edge[tot].nxt = head[u];
    head[u] = tot++;
}
void Tarjan(int u,int pre)
{
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = 1;
    for(int i = head[u]; i != -1; i = edge[i].nxt)
    {
        v = edge[i].to;
        if(v == pre)continue;
        if(res[i>>1]<0)res[i>>1]=~i&1;
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
            Instack[v] = 0;
            Belong[v] = block;
        }
        while( v!=u );
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    init();
    for(int i=0; i<m; i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        addedge(u[i],v[i]);
        addedge(v[i],u[i]);
    }
    memset(DFN,0,sizeof(DFN));
    memset(Instack,0,sizeof(Instack));
    Index = top = block = 0;
    Tarjan(1,0);
    for(int i=1; i<=n; i++)
        Size[Belong[i]]++;
    int mx=1;
    for(int i=1; i<=block; i++)
        if(Size[i]>Size[mx])mx=i;
    printf("%d\n",Size[mx]);
    int st=1;
    for(int i=1; i<=n; i++)
        if(Belong[i]==mx)st=i;
    memset(DFN,0,sizeof(DFN));
    memset(Instack,0,sizeof(Instack));
    memset(res,-1,sizeof(res));
    Index = top = block = 0;
    Tarjan(st,0);
    for(int i=0; i<m; i++)
    {
        if(res[i])swap(u[i],v[i]);
        printf("%d %d\n",u[i],v[i]);
    }
    return 0;
}