#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
ll a[MAXN],b[MAXN],c[MAXN];
void update(int p,ll v,int n)
{
    for(int i=p;i<=n;i+=i&-i)c[i]=max(c[i],v);
}
ll query(int p)
{
    ll res=0;
    for(int i=p;i;i-=i&-i)res=max(res,c[i]);
    return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        ll r,h;
        scanf("%I64d%I64d",&r,&h);
        a[i]=b[i]=r*r*h;
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(b+1,b+n+1,a[i])-b;
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        ll t=query(a[i]-1)+b[a[i]];
        update(a[i],t,n);
        res=max(res,t);
    }
    printf("%.12f",res*acos(-1.0));
    return 0;
}