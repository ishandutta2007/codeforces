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
#define N 410
using namespace std;
ll n,t[N],dp[N][N];
int main(){
	ll q,i,j;
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&t[i]);
		}
		sort(t,t+n);
		memset(dp,63,sizeof(dp));
		dp[0][0]=0;
		for(i=0;i<=2*n;i++)
		{
			for(j=0;j<=n;j++)
			{
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
				dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+abs(i+1-t[j]));
			}
		}
		printf("%lld\n",dp[2*n+1][n]);
	}
	return 0;
}