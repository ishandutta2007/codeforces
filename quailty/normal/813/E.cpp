#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int rt[MAXN],v[MAXN<<6],ls[MAXN<<6],rs[MAXN<<6],tot;
void build(int l,int r,int &n)
{
    if(!n)n=++tot;
    if(l==r)return;
    int m=(l+r)/2;
    build(l,m,ls[n]);
    build(m+1,r,rs[n]);
}
void update(int p,int x,int l,int r,int ln,int &n)
{
    n=++tot,v[n]=v[ln]+x,ls[n]=ls[ln],rs[n]=rs[ln];
    if(l==r)return;
    int m=(l+r)/2;
    if(p<=m)update(p,x,l,m,ls[ln],ls[n]);
    else update(p,x,m+1,r,rs[ln],rs[n]);
}
int query(int ql,int qr,int l,int r,int n)
{
    if(ql==l && qr==r)return v[n];
    int m=(l+r)/2;
    if(qr<=m)return query(ql,qr,l,m,ls[n]);
    if(ql>m)return query(ql,qr,m+1,r,rs[n]);
    return query(ql,m,l,m,ls[n])+query(m+1,qr,m+1,r,rs[n]);
}
vector<int> loc[MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    build(1,n,rt[0]);
    for(int i=1,a;i<=n;i++)
    {
        scanf("%d",&a);
        rt[i]=rt[i-1];
        if(i<n)update(i+1,-1,1,n,rt[i],rt[i]);
        int t=loc[a].size();
        if(t<k)update(1,1,1,n,rt[i],rt[i]);
        else update(loc[a][t-k]+1,1,1,n,rt[i],rt[i]);
        loc[a].push_back(i);
    }
    int q,las=0;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        l=(l+las)%n+1,r=(r+las)%n+1;
        if(l>r)swap(l,r);
        printf("%d\n",las=query(1,l,1,n,rt[r]));
    }
    return 0;
}