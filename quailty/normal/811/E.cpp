#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=10;
const int MAXM=100005;
int a[MAXN][MAXM];
struct DSU
{
    int fa[MAXN*4];
    void Init(int n)
    {
        for(int i=0;i<n;i++)fa[i]=i;
    }
    int Find(int x)
    {
        return fa[x]==x ? x : fa[x]=Find(fa[x]);
    }
    int Union(int x,int y)
    {
        x=Find(x),y=Find(y);
        if(x==y)return 0;
        if(x<y)swap(x,y);
        return fa[x]=y,1;
    }
}dsu;
vector<int> tmp[MAXN*4];
struct node
{
    static int n;
    int l,r,c[MAXN*2],v;
    void init()
    {
        v=n*2;
        dsu.Init(n*2);
        for(int i=0;i<n;i++)
            v-=dsu.Union(i,i+n);
        for(int i=1;i<n;i++)
            if(a[i][l]==a[i-1][l])
                v-=dsu.Union(i,i-1);
        for(int i=0;i<n;i++)
            c[i]=c[i+n]=dsu.Find(i);
    }
    node operator + (const node &t)const
    {
        node res;
        res.l=l,res.r=t.r,res.v=v+t.v;
        for(int i=0;i<n*2;i++)
        {
            dsu.fa[i]=c[i];
            dsu.fa[i+n*2]=t.c[i]+n*2;
        }
        for(int i=0;i<n;i++)
            if(a[i][r]==a[i][t.l])
                res.v-=dsu.Union(i+n,i+n*2);
        for(int i=0;i<n*4;i++)
            tmp[i].clear();
        for(int i=0;i<n;i++)
            tmp[dsu.Find(i)].push_back(i);
        for(int i=n*3;i<n*4;i++)
            tmp[dsu.Find(i)].push_back(i-n*2);
        for(int i=0;i<n*4;i++)
            for(int j=0;j<(int)tmp[i].size();j++)
                res.c[tmp[i][j]]=tmp[i][0];
        return res;
    }
}s[MAXM*4];
int node::n=0;
void build(int l,int r,int n)
{
    if(l==r)
    {
        s[n].l=s[n].r=l;
        s[n].init();
        return;
    }
    int m=(l+r)/2;
    build(l,m,n<<1);
    build(m+1,r,n<<1|1);
    s[n]=s[n<<1]+s[n<<1|1];
}
node query(int l,int r,int n)
{
    if(l==s[n].l && r==s[n].r)return s[n];
    int m=(s[n].l+s[n].r)/2;
    if(r<=m)return query(l,r,n<<1);
    if(l>m)return query(l,r,n<<1|1);
    return query(l,m,n<<1)+query(m+1,r,n<<1|1);
}
int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    node::n=n;
    for(int i=0;i<n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    build(1,m,1);
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",query(l,r,1).v);
    }
    return 0;
}