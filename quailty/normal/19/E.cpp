#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
const int MAXN=10005;
const int MAXM=10005;
int u[MAXM],v[MAXM],ok[MAXM];
struct Info
{
    int u,fa,ra,cl,id;
};
stack<Info>stk;
int fa[MAXN],ra[MAXN],cl[MAXN];
void Init(int n)
{
    for(int i=1;i<=n;i++)
        fa[i]=i,ra[i]=0,cl[i]=0;
}
int Find(int x,int &c)
{
    return x==fa[x] ? x : Find(fa[x],c=c^cl[x]);
}
bool Union(int u,int v,int id)
{
    int cu=0,cv=0;
    int fu=Find(u,cu),fv=Find(v,cv);
    if(fu==fv)return cu^cv;
    stk.push(Info{fu,fa[fu],ra[fu],cl[fu],id});
    stk.push(Info{fv,fa[fv],ra[fv],cl[fv],id});
    if(ra[fu]<ra[fv])
    {
        fa[fu]=fv;
        cl[fu]=cu^cv^1;
    }
    else
    {
        fa[fv]=fu;
        cl[fv]=cu^cv^1;
        if(ra[fu]==ra[fv])ra[fu]++;
    }
    return 1;
}
bool Work(int l,int r,int id)
{
    for(int i=l;i<=r;i++)
        if(!Union(u[i],v[i],id))return 0;
    return 1;
}
void Undo(int l,int r,int id)
{
    while(!stk.empty())
    {
        Info tmp=stk.top();
        if(tmp.id!=id)break;
        fa[tmp.u]=tmp.fa;
        ra[tmp.u]=tmp.ra;
        cl[tmp.u]=tmp.cl;
        stk.pop();
    }
}
void Solve(int l,int r,int id)
{
    if(l>=r)return;
    int m=(l+r)/2;
    if(Work(m+1,r,id))Solve(l,m,id<<1);
    else for(int i=l;i<=m;i++)ok[i]=0;
    Undo(m+1,r,id);
    if(Work(l,m,id))Solve(m+1,r,id<<1|1);
    else for(int i=m+1;i<=r;i++)ok[i]=0;
    Undo(l,m,id);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d",&u[i],&v[i]);
    for(int i=1;i<=m;i++)
        ok[i]=1;
    Init(n);
    Solve(1,m,1);
    int tot=0;
    for(int i=1;i<=m;i++)
        tot+=ok[i];
    printf("%d\n",tot);
    for(int i=1;i<=m;i++)
        if(ok[i])printf("%d ",i);
    return 0;
}