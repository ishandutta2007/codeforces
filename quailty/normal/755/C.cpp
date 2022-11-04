#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=10005;
int fa[MAXN];
void Init(int n)
{
    for(int i=1;i<=n;i++)fa[i]=i;
}
int Find(int x)
{
    return x==fa[x] ? x : fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
    x=Find(x),y=Find(y);
    if(x==y)return;
    fa[x]=y;
}
int main()
{
    int n;
    scanf("%d",&n);
    Init(n);
    for(int i=1;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        Union(p,i);
    }
    int res=0;
    for(int i=1;i<=n;i++)
        res+=(Find(i)==i);
    return 0*printf("%d",res);
}