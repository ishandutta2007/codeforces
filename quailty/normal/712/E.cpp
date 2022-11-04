#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long double db;
const int MAXN=100005;
pair<db,db> operator + (const pair<db,db> &a,const pair<db,db> &b)
{
    db tf=a.first*b.first/(1-(1-b.first)*(1-a.second));
    db ts=a.second*b.second/(1-(1-b.first)*(1-a.second));
    return make_pair(tf,ts);
}
db p[MAXN];
struct node
{
    int l,r,m;
    pair<db,db>v;
}s[MAXN<<2];
void build(int l,int r,int n)
{
    int m=(l+r)/2;
    s[n].l=l;
    s[n].r=r;
    s[n].m=m;
    if(l==r)
    {
        s[n].v=make_pair(p[l],1-p[l]);
        return;
    }
    build(l,m,n<<1);
    build(m+1,r,n<<1|1);
    s[n].v=s[n<<1].v+s[n<<1|1].v;
}
void update(int p,db v,int n)
{
    if(s[n].l==s[n].r)
    {
        s[n].v=make_pair(v,1-v);
        return;
    }
    if(p<=s[n].m)update(p,v,n<<1);
    else update(p,v,n<<1|1);
    s[n].v=s[n<<1].v+s[n<<1|1].v;
}
pair<db,db> query(int l,int r,int n)
{
    if(l==s[n].l && r==s[n].r)return s[n].v;
    if(r<=s[n].m)return query(l,r,n<<1);
    if(l>s[n].m)return query(l,r,n<<1|1);
    return query(l,s[n].m,n<<1)+query(s[n].m+1,r,n<<1|1);
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        p[i]=1.0*a/b;
    }
    build(1,n,1);
    for(int i=1;i<=q;i++)
    {
        int ty;
        scanf("%d",&ty);
        if(ty==1)
        {
            int i,a,b;
            scanf("%d%d%d",&i,&a,&b);
            update(i,1.0*a/b,1);
        }
        else
        {
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%.10f\n",(double)query(l,r,1).first);
        }
    }
    return 0;
}