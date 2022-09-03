#include <cstdio>
#define two(n) ((n)*1ll*((n)-1)*3)
using namespace std;
typedef unsigned long long LL;
const int maxn=100005;
int head[maxn],next[maxn*2],to[maxn*2],cnt;
double times[maxn],N,M;
int n,s[maxn],t[maxn],fa[maxn],cost[maxn],count[maxn];
int q;
bool use[maxn];
inline void addedge(int x,int y)
{
    cnt++;
    next[cnt]=head[x];
    head[x]=cnt;
    to[cnt]=y;
}
void dfs(int x,int f)
{
    fa[x]=f;
    count[x]=1;
    for(int i=head[x];i;i=next[i])
        if(to[i]!=f)
        {
            dfs(to[i],x);
            count[x]+=count[to[i]];
        }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d%d",s+i,t+i,cost+i);
        addedge(s[i],t[i]);
        addedge(t[i],s[i]);
    }
    dfs(1,0);
    LL t1,t2;
    for(int i=1;i<n;i++)
    {
        if(s[i]==fa[t[i]])
        {
            t1=count[t[i]];
            t2=n-t1;
        }
        else
        {
            t1=count[s[i]];
            t2=n-t1;
        }
        times[i]=two(t2)*t1*2+two(t1)*t2*2;
        M+=times[i]*cost[i];
    }
    N=n*(n-1ll)*(n-2);
    scanf("%d",&q);
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        M-=times[x]*(cost[x]-y);
        
        cost[x]=y;
        printf("%.8lf\n",M/N);
    }
    return 0;
}