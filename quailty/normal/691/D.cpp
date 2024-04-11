#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000005;
vector<int>v[MAXN];
int p[MAXN],fa[MAXN];
void Init(int n)
{
    for(int i=1;i<=n;i++)fa[i]=i;
}
int Find(int x)
{
    return fa[x]==x ? x : fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
    x=Find(x),y=Find(y);
    if(x!=y)fa[x]=y;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    Init(n);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        Union(a,b);
    }
    for(int i=1;i<=n;i++)
        v[Find(i)].push_back(p[i]);
    for(int i=1;i<=n;i++)
        sort(v[i].begin(),v[i].end());
    for(int i=1;i<=n;i++)
    {
        printf("%d ",v[Find(i)].back());
        v[Find(i)].pop_back();
    }
    return 0;
}