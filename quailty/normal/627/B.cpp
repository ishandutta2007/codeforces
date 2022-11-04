#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
int a,b;
struct node
{
    int l,r,m,v[2];
}s[MAXN<<2];
void push_up(int n)
{
    for(int i=0;i<2;i++)
        s[n].v[i]=s[n<<1].v[i]+s[n<<1|1].v[i];
}
void build(int l,int r,int n)
{
    int m=(l+r)>>1;
    s[n].l=l;
    s[n].r=r;
    s[n].m=m;
    if(r-l==1)
    {
        s[n].v[0]=s[n].v[1]=0;
        return;
    }
    build(l,m,n<<1);
    build(m,r,n<<1|1);
    push_up(n);
}
void update(int p,int v,int n)
{
    if(s[n].l==p && s[n].r==p+1)
    {
        s[n].v[0]=min(b,s[n].v[0]+v);
        s[n].v[1]=min(a,s[n].v[1]+v);
        return;
    }
    if(p<s[n].m)update(p,v,n<<1);
    else update(p,v,n<<1|1);
    push_up(n);
}
int query(int l,int r,int n,int id)
{
    if(r<=l)return 0;
    if(s[n].l==l && s[n].r==r)return s[n].v[id];
    if(r<=s[n].m)return query(l,r,n<<1,id);
    if(l>=s[n].m)return query(l,r,n<<1|1,id);
    return query(l,s[n].m,n<<1,id)+query(s[n].m,r,n<<1|1,id);
}
int main()
{
    int n,k,q;
    scanf("%d%d%d%d%d",&n,&k,&a,&b,&q);
    build(1,n+1,1);
    for(int i=1;i<=q;i++)
    {
        int ty;
        scanf("%d",&ty);
        if(ty==1)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            update(x,y,1);
        }
        else
        {
            int p;
            scanf("%d",&p);
            printf("%d\n",query(1,p,1,0)+query(p+k,n+1,1,1));
        }
    }
    return 0;
}