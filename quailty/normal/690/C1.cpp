#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1005;
int fa[MAXN];
void Init(int n)
{
    for(int i=1;i<=n;i++)fa[i]=i;
}
int Find(int x)
{
    return fa[x]==x ? x : fa[x]=Find(fa[x]);
}
bool Union(int x,int y)
{
    x=Find(x),y=Find(y);
    if(x==y)return 0;
    return fa[x]=y,1;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    Init(n);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(!Union(a,b))return 0*printf("no");
    }
    for(int i=1;i<=n;i++)
        if(Find(i)!=Find(1))return 0*printf("no");
    return 0*printf("yes");
}