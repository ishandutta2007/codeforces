#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
ll a[MAXN],pre[MAXN],suf[MAXN];
int main()
{
    int n,k;
    ll x;
    scanf("%d%d%I64d",&n,&k,&x);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    for(int i=1;i<=n;i++)
        pre[i]=(pre[i-1]|a[i]);
    for(int i=n;i>=1;i--)
        suf[i]=(suf[i+1]|a[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=k;j++)
            a[i]*=x;
    ll ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,(pre[i-1]|a[i]|suf[i+1]));
    printf("%I64d\n",ans);
    return 0;
}