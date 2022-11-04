#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=500005;
int b[MAXN],l[MAXN],r[MAXN],t[MAXN];
void modify(int s[],int h[],int n)
{
    for(int i=1;i<=n;i++)h[i]=s[i];
    sort(h+1,h+n+1);
    int cnt=unique(h+1,h+n+1)-(h+1);
    for(int i=1;i<=n;i++)
        s[i]=lower_bound(h+1,h+cnt+1,s[i])-h;
}
struct person
{
    int b,l,r;
    person(int b=0,int l=0,int r=0):b(b),l(l),r(r){}
    bool operator < (const person &q)const
    {
        return b==q.b ? (l==q.l ? r>q.r : l<q.l) : b>q.b;
    }
}p[MAXN];
struct node
{
    int l,r,m,v;
}s[MAXN<<2];
void push_up(int num)
{
    s[num].v=max(s[num<<1].v,s[num<<1|1].v);
}
void build(int l,int r,int num)
{
    int m=(l+r)>>1;
    s[num].l=l;
    s[num].r=r;
    s[num].m=m;
    if(r-l==1)s[num].v=0;
    else
    {
        build(l,m,num<<1);
        build(m,r,num<<1|1);
        push_up(num);
    }
}
void update(int p,int k,int num)
{
    if(s[num].l==p && s[num].r==p+1)
    {
        s[num].v=max(s[num].v,k);
        return;
    }
    if(p<s[num].m)update(p,k,num<<1);
    else update(p,k,num<<1|1);
    push_up(num);
}
int query(int l,int r,int num)
{
    if(s[num].l==l && s[num].r==r)return s[num].v;
    if(r<=s[num].m)return query(l,r,num<<1);
    if(l>=s[num].m)return query(l,r,num<<1|1);
    return max(query(l,s[num].m,num<<1),query(s[num].m,r,num<<1|1));
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)scanf("%d",&l[i]);
    for(int i=1;i<=n;i++)scanf("%d",&r[i]);
    modify(b,t,n);
    modify(l,t,n);
    modify(r,t,n);
    for(int i=1;i<=n;i++)
    {
        p[i]=person(b[i],l[i],r[i]);
    }
    sort(p+1,p+n+1);
    build(1,n+2,1);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(query(p[i].l+1,n+2,1)>p[i].r)ans++;
        update(p[i].l,p[i].r,1);
    }
    printf("%d\n",ans);
    return 0;
}