#include<cstdio>
#include<algorithm>
using namespace std;
int fir[200010],ne[400010],to[400010],vis[200010],f[400010],num[200010],
n,m,k,clo;
void add(int num,int u,int v)
{
    ne[num]=fir[u];
    fir[u]=num;
    to[num]=v;
}
void dfs(int u)
{
    int v;
    f[++clo]=u;
    vis[u]=1;
    for (int i=fir[u];i;i=ne[i])
        if (!vis[v=to[i]])
        {
            dfs(v);
            f[++clo]=u;
        }
}
int main()
{
    int x,y;
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        add(i*2,x,y);
        add(i*2+1,y,x);
    }
    dfs(1);
    for (int i=1;i<=k;i++) num[i]=(2*n-1)/k;
    for (int i=1;i<=(2*n-1)%k;i++) num[i]++;
    for (int i=1,j=1;i<=k;i++)
    {
        printf("%d ",num[i]);
        while (num[i]--) printf("%d ",f[j++]);
        putchar('\n');
    }
}