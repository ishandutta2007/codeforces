#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 110
using namespace std;
ll n,a[N],sum[N],tsum[N];
int main(){
	ll T,i,lst;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(i=0;i<=n;i++)
		{
			sum[i]=tsum[i]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			tsum[i+1]=tsum[i]+i;
			sum[i+1]=sum[i]+a[i];
		}
		for(i=0;i<=n;i++)
		{
			if(tsum[i]>sum[i])
			{
				puts("NO");
				i=-1;
				break;
			}
		}
		if(i!=-1)
		{
			puts("YES");
		}
	}
	return 0;
}