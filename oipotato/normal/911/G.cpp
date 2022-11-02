#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <bitset>
using namespace std;
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
struct node
{
    int f[110];
    int p;
}st[810000],base;
int n,q;
int a[310000],ans[310000];
node merge(node &a,node &b)
{
    node ans;
    for(int i=1;i<=100;i++)
        ans.f[i]=b.f[a.f[i]];
    ans.p=1;
    return ans;
}
void build(int t,int l,int r)
{
    int mid=(l+r)/2;
    if (l!=r)
    {
        build(t*2,l,mid);
        build(t*2+1,mid+1,r);
    }
    for(int i=1;i<=100;i++)st[t].f[i]=i;
    st[t].p=0;
}
void clear(int t)
{
    st[2*t]=merge(st[2*t],st[t]);
    st[2*t+1]=merge(st[2*t+1],st[t]);
    for(int i=1;i<=100;i++)st[t].f[i]=i;
    st[t].p=0;
}
void modify(int t,int l,int r,int a,int b)
{
    if (a<=l && r<=b)
    {
        st[t]=merge(st[t],base);
        return;
    }
    clear(t);
    int mid=(l+r)/2;
    if (a<=mid)modify(2*t,l,mid,a,b);
    if (b>mid)modify(2*t+1,mid+1,r,a,b);
}
void print(int t,int l,int r)
{
    if (l==r)
    {
        ans[l]=st[t].f[a[l]];
        return;
    }
    clear(t);
    int mid=(l+r)/2;
    print(2*t,l,mid);
    print(2*t+1,mid+1,r);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    build(1,1,n);
    scanf("%d",&q);
    for(int i=1;i<=100;i++)base.f[i]=i;
    for(int i=1;i<=q;i++)
    {
        int l,r,x,y;
        scanf("%d%d%d%d",&l,&r,&x,&y);
        base.f[x]=y;
        modify(1,1,n,l,r);
        base.f[x]=x;
    }
    print(1,1,n);
    for(int i=1;i<=n;i++)printf("%d%c",ans[i],i==n?'\n':' ');
}