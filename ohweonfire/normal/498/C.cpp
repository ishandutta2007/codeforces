#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
const int inf=2147483647;
struct edge{int to,cap,rev;};
vector<edge> g[maxn];
int level[maxn],iter[maxn],que[maxn];
void addedge(int from,int to,int cap)
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
int a[maxn],n,m,px[maxn],py[maxn],ans;
set<int> st;
map<int,int> cnt[maxn];
void fun(int x)
{
    int y=a[x];
    for(int i=2;i*i<=y;i++)
        if(y%i==0)
        {
            st.insert(i);
            while(y%i==0)
            {
                cnt[x][i]++;
                y/=i;
            }
        }
    if(y!=1)
    {
        st.insert(y);
        cnt[x][y]=1;
    }
}
void gao(int pr)
{
    for(int i=0;i<maxn;i++)
        g[i].clear();
    for(int i=1;i<=m;i++)
        if(cnt[px[i]][pr]&&cnt[py[i]][pr])
            addedge(px[i],py[i],min(cnt[px[i]][pr],cnt[py[i]][pr]));
    for(int i=1;i<=n;i++)
    {
        if(g[i].empty())
            continue;
        if(i&1)
            addedge(0,i,cnt[i][pr]);
        else
            addedge(i,n+1,cnt[i][pr]);
    }
    int t=maxflow(0,n+1);
    ans+=t;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        fun(i);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",px+i,py+i);
        if(py[i]&1)
            swap(px[i],py[i]);
    }
    for(set<int>::iterator it=st.begin();it!=st.end();it++)
        gao(*it);
    printf("%d\n",ans);
    return 0;
}