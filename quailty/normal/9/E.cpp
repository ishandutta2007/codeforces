#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=55;
int fa[MAXN],d[MAXN];
void Init(int n)
{
    for(int i=1;i<=n;i++)fa[i]=i;
}
int Find(int x)
{
    return fa[x]==x ? x : fa[x]=Find(fa[x]);
}
int Union(int x,int y)
{
    x=Find(x);
    y=Find(y);
    if(x==y)return 0;
    fa[x]=y;
    return 1;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    Init(n);
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(!Union(u,v))cnt++;
        d[u]++;
        d[v]++;
    }
    if(cnt>1)return 0*printf("NO\n");
    if(cnt==1)
    {
        for(int i=1;i<=n;i++)
            if(d[i]!=2)return 0*printf("NO\n");
    }
    for(int i=1;i<=n;i++)
        if(d[i]>2)return 0*printf("NO\n");
    printf("YES\n%d\n",n-m);
    if(n==1 && m==0)return 0*printf("%d %d\n",1,1);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(Find(i)!=Find(j) && d[i]<2 && d[j]<2)
            {
                printf("%d %d\n",i,j);
                Union(i,j);
                d[i]++;
                d[j]++;
            }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(d[i]<2 && d[j]<2)
            {
                printf("%d %d\n",i,j);
                d[i]++;
                d[j]++;
            }
    return 0;
}