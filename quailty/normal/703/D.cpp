#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=1000005;
int s[MAXN<<1];
inline int getId(int l,int r)
{
    return (l+r)|(l<r);
}
void update(int ql,int qr,int v,int l,int r)
{
    int n=getId(l,r),m=(l+r)/2;
    if(ql==l && qr==r)
    {
        s[n]^=v;
        return;
    }
    if(qr<=m)update(ql,qr,v,l,m);
    else if(ql>m)update(ql,qr,v,m+1,r);
    else
    {
        update(ql,m,v,l,m);
        update(m+1,qr,v,m+1,r);
    }
}
int query(int p,int l,int r)
{
    int n=getId(l,r),m=(l+r)/2;
    if(l==r)return s[n];
    if(p<=m)return query(p,l,m)^s[n];
    else return query(p,m+1,r)^s[n];
}
struct query
{
    int l,r,id;
    bool operator < (const query &t)const
    {
        return r<t.r;
    }
}q[MAXN];
map<int,int>mp;
int a[MAXN],res[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].id=i;
    }
    sort(q+1,q+m+1);
    for(int i=1,j=1;i<=m;i++)
    {
        while(j<=q[i].r)
        {
            if(mp[a[j]])update(1,mp[a[j]],a[j],1,n);
            mp[a[j]]=j;
            j++;
        }
        res[q[i].id]=query(q[i].l,1,n);
    }
    for(int i=1;i<=m;i++)
        printf("%d\n",res[i]);
    return 0;
}