#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const ll INF=(1LL<<60)-1;
int a[MAXN],b[MAXN],h[MAXN],id[MAXN],x[MAXN<<1];
struct BIT
{
    int n;
    ll c[MAXN<<1];
    void init(int _n)
    {
        n=_n;
        for(int i=1;i<=n;i++)
            c[i]=-INF;
    }
    void update(int p,ll v)
    {
        for(int i=p;i<=n;i+=i&-i)c[i]=max(c[i],v);
    }
    ll query(int p)
    {
        ll res=-INF;
        for(int i=p;i>0;i-=i&-i)res=max(res,c[i]);
        return res;
    }
}bit;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&h[i]);
        x[2*i-1]=a[i];
        x[2*i]=b[i];
    }
    sort(x+1,x+2*n+1);
    for(int i=1;i<=n;i++)
    {
        a[i]=lower_bound(x+1,x+2*n+1,a[i])-x;
        b[i]=lower_bound(x+1,x+2*n+1,b[i])-x;
    }
    for(int i=1;i<=n;i++)
        id[i]=i;
    sort(id+1,id+n+1,[](int x,int y){return b[x]==b[y] ? a[x]>a[y] : b[x]>b[y];});
    bit.init(2*n);
    ll res=-INF;
    for(int ii=1;ii<=n;ii++)
    {
        int i=id[ii];
        ll now=max(0LL,bit.query(b[i]-1))+h[i];
        bit.update(a[i],now);
        res=max(res,now);
    }
    printf("%lld\n",res);
    return 0;
}