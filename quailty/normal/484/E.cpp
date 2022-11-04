#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
struct info
{
    int m,l,r,s,w;
    info(){}
    info(int _m,int _l,int _r,int _s,int _w):m(_m),l(_l),r(_r),s(_s),w(_w){}
    info operator + (const info &t)const
    {
        return info(max({m,t.m,r+t.l}),l+(l==w)*t.l,t.r+(t.r==t.w)*r,s+t.s,w+t.w);
    }
};
struct node
{
    info v;
    int ls,rs;
}s[MAXN*25];
int rt[MAXN],tot;
void pushUp(int n)
{
    s[n].v=s[s[n].ls].v+s[s[n].rs].v;
}
void build(int l,int r,int &n)
{
    n=tot++;
    if(l==r)
    {
        s[n].v=info(0,0,0,0,1);
        return;
    }
    int m=(l+r)/2;
    build(l,m,s[n].ls);
    build(m+1,r,s[n].rs);
    pushUp(n);
}
void update(int p,int l,int r,int ln,int &n)
{
    s[n=tot++]=s[ln];
    if(l==r)
    {
        s[n].v=info(1,1,1,1,1);
        return;
    }
    int m=(l+r)/2;
    if(p<=m)update(p,l,m,s[ln].ls,s[n].ls);
    else update(p,m+1,r,s[ln].rs,s[n].rs);
    pushUp(n);
}
info query(int ql,int qr,int l,int r,int n)
{
    if(ql==l && qr==r)return s[n].v;
    int m=(l+r)/2;
    if(qr<=m)return query(ql,qr,l,m,s[n].ls);
    if(ql>m)return query(ql,qr,m+1,r,s[n].rs);
    return query(ql,m,l,m,s[n].ls)+query(m+1,qr,m+1,r,s[n].rs);
}
int h[MAXN],id[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    for(int i=1;i<=n;i++)
        id[i]=i;
    sort(id+1,id+n+1,[](int a,int b){return h[a]>h[b];});
    build(1,n,rt[0]);
    for(int i=1;i<=n;i++)
        update(id[i],1,n,rt[i-1],rt[i]);
    int m;
    scanf("%d",&m);
    while(m--)
    {
        int l,r,w;
        scanf("%d%d%d",&l,&r,&w);
        int tl=1,tr=n;
        while(tl<tr)
        {
            int tm=(tl+tr)/2;
            if(query(l,r,1,n,rt[tm]).m>=w)tr=tm;
            else tl=tm+1;
        }
        printf("%d\n",h[id[tl]]);
    }
    return 0;
}