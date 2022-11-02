#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct que
{
    int point,next;
}b[100000];
int n,g[100010],tot,sum[100010];
double p[100010];
void build(int x,int y)
{
    b[tot].point=y; b[tot].next=g[x]; g[x]=tot++;
}
void dfs(int x)
{
    int t=g[x];
    while (t!=-1)
    {
        dfs(b[t].point);
        sum[x]=sum[x]+sum[b[t].point];
        t=b[t].next;
    }
    sum[x]++;
    return;
}
void get(int x)
{
    int t=g[x];
    while (t!=-1)
    {
        p[b[t].point]=p[x]+1+(sum[x]-sum[b[t].point]-1)/2.0;
        get(b[t].point);
        t=b[t].next;
    }
    return;
}
int main()
{
    scanf("%d",&n);
    memset(g,-1,sizeof(g));
    for (int i=2;i<=n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        build(tmp,i);
    }
    dfs(1);
    p[1]=1;
    get(1);
    for (int i=1;i<=n;i++) printf("%.1lf ",p[i]);
    return 0;
}