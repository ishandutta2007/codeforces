#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll cnt[105][105];
int main()
{
    ll n,m,k,x,y,r=0;
    scanf("%lld%lld%lld%lld%lld",&n,&m,&k,&x,&y);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cnt[i][j]++,r++;
    for(int i=n-1;i>=2;i--)
        for(int j=1;j<=m;j++)
            cnt[i][j]++,r++;
    ll t=(k-1)/r;
    k-=t*r;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cnt[i][j]*=t;
    for(int i=1;i<=n && k;i++)
        for(int j=1;j<=m && k;j++)
            cnt[i][j]++,k--;
    for(int i=n-1;i>=2 && k;i--)
        for(int j=1;j<=m && k;j++)
            cnt[i][j]++,k--;
    ll mi=(1LL<<60)-1,mx=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            mi=min(mi,cnt[i][j]),mx=max(mx,cnt[i][j]);
    return 0*printf("%lld %lld %lld",mx,mi,cnt[x][y]);
}