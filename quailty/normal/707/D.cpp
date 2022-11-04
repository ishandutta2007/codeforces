#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXQ=100005;
int n,m;

struct nodeY
{
    int v;
    nodeY *ls,*rs;
    nodeY()
    {
        v=0;
        ls=rs=this;
    }
    nodeY(nodeY* rhs)
    {
        v=rhs->v;
        ls=rhs->ls;
        rs=rhs->rs;
    }
}*nullY;

void updateY(int y,int ty,int l,int r,nodeY *lu,nodeY *&u)
{
    u=new nodeY(lu);
    if(l==r)
    {
        u->v=ty;
        return;
    }
    int m=(l+r)/2;
    if(y<=m)updateY(y,ty,l,m,lu->ls,u->ls);
    else updateY(y,ty,m+1,r,lu->rs,u->rs);
    u->v=u->ls->v+u->rs->v;
}

struct nodeX
{
    int v,r;
    nodeX *ls,*rs;
    nodeY *rty;
    nodeX()
    {
        v=r=0;
        ls=rs=this;
        rty=nullY;
    }
    nodeX(nodeX* rhs)
    {
        v=rhs->v;
        r=rhs->r;
        ls=rhs->ls;
        rs=rhs->rs;
        rty=rhs->rty;
    }
}*nullX,*rt[MAXQ];

void updateX(int x,int y,int ty,int l,int r,nodeX* lu,nodeX *&u)
{
    u=new nodeX(lu);
    if(l==r)
    {
        if(ty<2)updateY(y,ty^lu->r,1,m,lu->rty,u->rty);
        else
        {
            u->rty=new nodeY(lu->rty);
            u->r^=1;
        }
        u->v=(u->r ? m-u->rty->v : u->rty->v);
        return;
    }
    int m=(l+r)/2;
    if(x<=m)updateX(x,y,ty,l,m,lu->ls,u->ls);
    else updateX(x,y,ty,m+1,r,lu->rs,u->rs);
    u->v=u->ls->v+u->rs->v;
}

int main()
{
    nullY=new nodeY;
    nullX=new nodeX;
    int q;
    scanf("%d%d%d",&n,&m,&q);
    rt[0]=nullX;
    for(int i=1;i<=q;i++)
    {
        int ty,x,y;
        scanf("%d",&ty);
        if(ty<=2)
        {
            scanf("%d%d",&x,&y);
            updateX(x,y,ty==1,1,n,rt[i-1],rt[i]);
        }
        else if(ty==3)
        {
            scanf("%d",&x);
            updateX(x,0,2,1,n,rt[i-1],rt[i]);
        }
        else if(ty==4)
        {
            scanf("%d",&x);
            rt[i]=rt[x];
        }
        printf("%d\n",rt[i]->v);
    }
    return 0;
}