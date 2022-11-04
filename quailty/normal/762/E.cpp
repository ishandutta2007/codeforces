#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int x[MAXN],r[MAXN],f[MAXN],id[MAXN];
int rt[MAXN],v[MAXN*40],ls[MAXN*40],rs[MAXN*40],tot;
void add(int p,int l,int r,int &n)
{
    if(!n)n=++tot;
    v[n]++;
    if(l==r)return;
    int m=(l+r)/2;
    if(p<=m)add(p,l,m,ls[n]);
    else add(p,m+1,r,rs[n]);
}
int query(int ql,int qr,int l,int r,int n)
{
    if(!n)return 0;
    if(ql==l && qr==r)return v[n];
    int m=(l+r)/2;
    if(qr<=m)return query(ql,qr,l,m,ls[n]);
    if(ql>m)return query(ql,qr,m+1,r,rs[n]);
    return query(ql,m,l,m,ls[n])+query(m+1,qr,m+1,r,rs[n]);
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&x[i],&r[i],&f[i]);
    for(int i=1;i<=n;i++)
        id[i]=i;
    sort(id+1,id+n+1,[&](int a,int b){return r[a]>r[b];});
    long long res=0;
    for(int ii=1;ii<=n;ii++)
    {
        int i=id[ii];
        for(int j=max(f[i]-k,1);j<=min(f[i]+k,10000);j++)
            res+=query(max(x[i]-r[i],1),min(x[i]+r[i],1000000000),1,1000000000,rt[j]);
        add(x[i],1,1000000000,rt[f[i]]);
    }
    printf("%lld",res);
    return 0;
}