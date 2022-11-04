#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
ll a[MAXN],dp[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        a[i]+=a[i-1];
    }
    ll mx=max(a[n],a[n-1]-(dp[n-1]=a[n]));
    for(int i=n-2;i>=1;i--)
    {
        dp[i]=mx;
        mx=max(mx,a[i]-dp[i]);
    }
    return 0*printf("%I64d",dp[1]);
}