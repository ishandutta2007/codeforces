#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const ll INF=(1LL<<60)-1;
ll b[MAXN];
int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    ll a=0;
    for(int i=1,j=1,t;i<=n;i++,j=-j)
        scanf("%d",&t),a+=t*j;
    for(int i=1,j=1;i<=m;i++,j=-j)
        scanf("%lld",&b[i]),b[i]=b[i]*j+b[i-1];
    for(int i=0,j=1;i<=m-n;i++,j=-j)
        b[i]=(b[i+n]-b[i])*j;
    sort(b,b+m-n+1);
    ll res=INF;
    int t=lower_bound(b,b+m-n+1,a)-b;
    if(t<=m-n)res=min(res,b[t]-a);
    if(t>0)res=min(res,a-b[t-1]);
    printf("%lld\n",res);
    while(q--)
    {
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        if((l&1)==(r&1))a+=(l&1 ? x : -x);
        res=INF,t=lower_bound(b,b+m-n+1,a)-b;
        if(t<=m-n)res=min(res,b[t]-a);
        if(t>0)res=min(res,a-b[t-1]);
        printf("%lld\n",res);
    }
    return 0;
}