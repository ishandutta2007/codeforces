#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
int fa[MAXN],link[MAXN];
void init(int p[],int n)
{
    for(int i=1;i<=n;i++)p[i]=i;
}
int Find(int p[],int x)
{
    return p[x]==x ? x : p[x]=Find(p,p[x]);
}
void Union(int p[],int x,int y)
{
    x=Find(p,x);
    y=Find(p,y);
    if(x==y)return;
    if(x<y)p[x]=y;
    else p[y]=x;
}
bool vis[MAXN];
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    init(fa,n);
    init(link,n);
    int type,x,y;
    while(q--)
    {
        scanf("%d%d%d",&type,&x,&y);
        if(type==1)
        {
            Union(fa,x,y);
        }
        else if(type==2)
        {
            int pp=Find(link,x);
            for(int i=pp;i<=y;)
            {
                Union(fa,pp,Find(link,i));
                Union(link,pp,i);
                i=Find(link,i)+1;
            }
        }
        else
        {
            if(Find(fa,x)==Find(fa,y))printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}