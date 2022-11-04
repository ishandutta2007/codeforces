#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
const int INF=0x3f3f3f3f;
pair<int,int>f[MAXN];
int p[MAXN<<1];
struct node
{
    int l,r,m,d,v;
}s[MAXN<<4];
void build(int l,int r,int n)
{
    int m=(l+r)>>1;
    s[n].l=l;
    s[n].r=r;
    s[n].m=m;
    s[n].v=INF;
    if(r-l==1)
    {
        s[n].d=p[l]-p[l-1];
        return;
    }
    build(l,m,n<<1);
    build(m,r,n<<1|1);
}
void update(int l,int r,int v,int n)
{
    if(s[n].l==l && s[n].r==r)
    {
        s[n].v=min(s[n].v,v);
        return;
    }
    if(r<=s[n].m)update(l,r,v,n<<1);
    else if(l>=s[n].m)update(l,r,v,n<<1|1);
    else
    {
        update(l,s[n].m,v,n<<1);
        update(s[n].m,r,v,n<<1|1);
    }
}
ll res;
void dfs(int n,int t)
{
    if(s[n].r-s[n].l==1)
    {
        res+=1LL*s[n].d*min(t,s[n].v);
    }
    else
    {
        dfs(n<<1,min(t,s[n].v));
        dfs(n<<1|1,min(t,s[n].v));
    }
}
int main()
{
    int d,n,m;
    scanf("%d%d%d",&d,&n,&m);
    f[0]=make_pair(0,0);
    for(int i=1;i<=m;i++)
        scanf("%d%d",&f[i].first,&f[i].second);
    sort(f+1,f+m+1);
    f[++m]=make_pair(d,0);
    for(int i=0;i<m;i++)
        if(f[i+1].first-f[i].first>n)
            return 0*printf("-1");
    int tot=0;
    for(int i=0;i<=m;i++)
    {
        p[tot++]=f[i].first;
        p[tot++]=min(f[i].first+n,d);
    }
    sort(p,p+tot);
    tot=unique(p,p+tot)-p;
    build(1,tot,1);
    for(int i=0;i<m;i++)
    {
        int l=lower_bound(p,p+tot,f[i].first)-p+1;
        int r=lower_bound(p,p+tot,min(f[i].first+n,d))-p+1;
        update(l,r,f[i].second,1);
    }
    res=0;
    dfs(1,INF);
    printf("%I64d",res);
    return 0;
}