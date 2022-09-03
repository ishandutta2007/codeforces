#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define pb push_back
using namespace std;
const int maxn=205;
const int inf=2147483647;
struct edge{int to,cap,rev;};
vector<edge> g[maxn];
int level[maxn],iter[maxn],que[maxn];
inline void addedge(int from,int to,int cap)
{
    g[from].push_back((edge){to,cap,g[to].size()});
    g[to].push_back((edge){from,0,g[from].size()-1});
}
void bfs(int s)
{
    memset(level,-1,sizeof(level));
    int front=0,rear=1;
    level[s]=0;
    que[0]=s;
    while(front!=rear)
    {
        int v=que[front++];
        for(int i=0;i<g[v].size();i++)
        {
            edge &e=g[v][i];
            if(e.cap>0&&level[e.to]<0)
            {
                level[e.to]=level[v]+1;
                que[rear++]=e.to;
            }
        }
    }
}
int dfs(int v,int t,int f)
{
    if(v==t)
        return f;
    for(int &i=iter[v];i<g[v].size();i++)
    {
        edge &e=g[v][i];
        if(e.cap>0&&level[v]<level[e.to])
        {
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0)
            {
                e.cap-=d;
                g[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int maxflow(int s,int t)
{
    int flow=0;
    for(;;)
    {
        bfs(s);
        if(level[t]<0)
            return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while((f=dfs(s,t,inf))>0)
            flow+=f;
    }
}
int a[maxn],prime[maxn*maxn],n;
void MakePrime(int Length)
{
    for(int i=2;i<=Length;i++)
        prime[i]=true;
    for(int i=2;i*i<=Length;i++)
    {
        if(prime[i])
            for(int j=i*i;j<=Length;j+=i)
                prime[j]=false;
    }
}
bool use[maxn];
vector<int> tmp;
void dfs(int x)
{
    use[x]=true;
    tmp.pb(x);
    int f=(a[x]&1)^1;
    for(int i=1;i<g[x].size();i++)
        if(g[x][i].cap==f&&!use[g[x][i].to])
            dfs(g[x][i].to);
}
bool full(int x)
{
    for(int i=0;i<g[x].size();i++)
        if(g[x][i].cap!=0)
            return false;
    return true;
}
void OUTPUT()
{
    vector<vector<int> >ans;
    for(int i=1;i<=n;i++)
        if(!use[i])
        {
            tmp.clear();
            dfs(i);
            ans.push_back(tmp);
        }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
    {
        printf("%d ",ans[i].size());
        for(int j=0;j<ans[i].size();j++)
            printf("%d ",ans[i][j]);
        puts("");
    }
}
int main()
{
    MakePrime(20000);
    scanf("%d",&n);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        if(a[i]&1)
            addedge(0,i,2);
        else
            addedge(i,n+1,2);
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(prime[a[i]+a[j]])
            {
                if(a[i]&1)
                    addedge(i,j,1);
                else
                    addedge(j,i,1);
            }
    if(maxflow(0,n+1)==n)
        OUTPUT();
    else
        puts("Impossible");
    return 0;
}