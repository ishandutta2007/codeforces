#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN=100005;
const int MAXQ=200005;

int rx[MAXQ],ry[MAXQ];
int qx[MAXQ][2],qy[MAXQ][2];
int res[MAXQ];

struct node
{
    int l,r,m,v;
}s[MAXN<<2];
void push_up(int n)
{
    s[n].v=min(s[n<<1].v,s[n<<1|1].v);
}
void build(int l,int r,int n)
{
    int m=(l+r)>>1;
    s[n].l=l;
    s[n].r=r;
    s[n].m=m;
    s[n].v=0;
    if(r-l==1)return;
    build(l,m,n<<1);
    build(m,r,n<<1|1);
    push_up(n);
}
void update(int p,int v,int n)
{
    if(s[n].l==p && s[n].r==p+1)
    {
        s[n].v=max(s[n].v,v);
        return;
    }
    if(p<s[n].m)update(p,v,n<<1);
    else update(p,v,n<<1|1);
    push_up(n);
}
int query(int l,int r,int n)
{
    if(s[n].l==l && s[n].r==r)return s[n].v;
    if(r<=s[n].m)return query(l,r,n<<1);
    if(l>=s[n].m)return query(l,r,n<<1|1);
    return min(query(l,s[n].m,n<<1),query(s[n].m,r,n<<1|1));
}

struct Event
{
    int l,r,d,u,id;
    Event(){}
    Event(int _l,int _r,int _d,int _u,int _id):l(_l),r(_r),d(_d),u(_u),id(_id){}
    bool operator < (const Event &t)const
    {
        return r==t.r ? id<t.id : r<t.r;
    }
}e[MAXQ<<1];

int main()
{
    int n,m,k,q;
    scanf("%d%d%d%d",&n,&m,&k,&q);
    for(int i=1;i<=k;i++)
        scanf("%d%d",&rx[i],&ry[i]);
    for(int i=1;i<=q;i++)
        for(int j=0;j<2;j++)
            scanf("%d%d",&qx[i][j],&qy[i][j]);
    for(int _=0;_<2;_++)
    {
        int tot=0;
        for(int i=1;i<=k;i++)
            e[tot++]=Event(0,rx[i],0,ry[i],0);
        for(int i=1;i<=q;i++)
            e[tot++]=Event(qx[i][0],qx[i][1],qy[i][0],qy[i][1],i);
        sort(e,e+tot);
        build(1,m+1,1);
        for(int i=0;i<tot;i++)
        {
            if(e[i].id)res[e[i].id]|=query(e[i].d,e[i].u+1,1)>=e[i].l;
            else update(e[i].u,e[i].r,1);
        }
        swap(n,m);
        for(int i=1;i<=k;i++)
            swap(rx[i],ry[i]);
        for(int i=1;i<=q;i++)
            for(int j=0;j<2;j++)
                swap(qx[i][j],qy[i][j]);
    }
    for(int i=1;i<=q;i++)
        printf("%s\n",(res[i] ? "YES" : "NO"));
    return 0;
}