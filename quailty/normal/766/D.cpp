#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=100005;
map<string,int>mp;
int getId(string str)
{
    if(!mp[str])mp[str]=(int)mp.size();
    return mp[str];
}
int fa[MAXN],w[MAXN];
void Init(int n)
{
    for(int i=1;i<=n;i++)
        fa[i]=i,w[i]=0;
}
int Find(int x)
{
    if(x!=fa[x])
    {
        int rt=Find(fa[x]);
        w[x]^=w[fa[x]];
        fa[x]=rt;
    }
    return fa[x];
}
int Union(int x,int y,int v)
{
    int rx=Find(x),ry=Find(y);
    if(rx==ry)return -(w[x]^w[y]^v);
    fa[rx]=ry,w[rx]=w[x]^w[y]^v;
    return 1;
}
int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
    {
        char s[25];
        scanf("%s",s);
        getId(s);
    }
    Init(n);
    for(int i=1;i<=m;i++)
    {
        int r;
        char s[25],t[25];
        scanf("%d%s%s",&r,s,t);
        int tmp=Union(getId(s),getId(t),r-1);
        printf("%s\n",(tmp<0 ? "NO" : "YES"));
    }
    for(int i=1;i<=q;i++)
    {
        char s[25],t[25];
        scanf("%s%s",s,t);
        int x=getId(s),y=getId(t);
        int rx=Find(x),ry=Find(y);
        printf("%d\n",(rx==ry ? (w[x]^w[y] ? 2 : 1): 3));
    }
    return 0;
}