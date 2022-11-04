#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
vector<int> e[MAXN];
int in[MAXN],out[MAXN],time_tag;
void dfs(int u)
{
    in[u]=++time_tag;
    for(auto &v:e[u])dfs(v);
    out[u]=time_tag;
}
int tl[MAXN<<2],tr[MAXN<<2],val[MAXN<<2],lz[MAXN<<2];
void build(int l,int r,int n)
{
    tl[n]=l,tr[n]=r;
    if(l==r)return;
    int m=(l+r)/2;
    build(l,m,n<<1);
    build(m+1,r,n<<1|1);
}
void push_up(int n)
{
    val[n]=val[n<<1]+val[n<<1|1];
}
void push_down(int n)
{
    if(!lz[n])return;
    val[n<<1]=(tr[n<<1]-tl[n<<1]+1)-val[n<<1];
    val[n<<1|1]=(tr[n<<1|1]-tl[n<<1|1]+1)-val[n<<1|1];
    lz[n<<1]^=1;
    lz[n<<1|1]^=1;
    lz[n]=0;
}
void update(int ql,int qr,int n)
{
    if(ql==tl[n] && qr==tr[n])
    {
        val[n]=(tr[n]-tl[n]+1)-val[n];
        lz[n]^=1;
        return;
    }
    push_down(n);
    int m=(tl[n]+tr[n])/2;
    if(qr<=m)update(ql,qr,n<<1);
    else if(ql>m)update(ql,qr,n<<1|1);
    else
    {
        update(ql,m,n<<1);
        update(m+1,qr,n<<1|1);
    }
    push_up(n);
}
int query(int ql,int qr,int n)
{
    if(ql==tl[n] && qr==tr[n])return val[n];
    push_down(n);
    int m=(tl[n]+tr[n])/2;
    if(qr<=m)return query(ql,qr,n<<1);
    if(ql>m)return query(ql,qr,n<<1|1);
    return query(ql,m,n<<1)+query(m+1,qr,n<<1|1);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        e[p].push_back(i);
    }
    dfs(1);
    build(1,n,1);
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        if(t)update(in[i],in[i],1);
    }
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        char ty[5];
        int v;
        scanf("%s%d",ty,&v);
        if(*ty=='p')update(in[v],out[v],1);
        else printf("%d\n",query(in[v],out[v],1));
    }
    return 0;
}