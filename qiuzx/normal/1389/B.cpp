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
#define N 100010
using namespace std;
ll T,n,k,z,dp[N][6][2],a[N],ans;
int main(){
	ll T,i,j;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&n,&k,&z);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=0;i<k;i++)
		{
			for(j=0;j<=z;j++)
			{
				dp[i][j][0]=dp[i][j][1]=0;
			}
		}
		dp[0][0][0]=a[1];
		for(i=1;i<k;i++)
		{
			for(j=0;j<=z;j++)
			{
				if(i+1-j*2>=0)
				{
					dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1])+a[i+1-j*2];
				}
				if(i+1-j*2>=0&&j>0)
				{
					dp[i][j][1]=dp[i-1][j-1][0]+a[i+1-j*2];
				}
			}
		}
		ans=0;
		for(i=0;i<=z;i++)
		{
			ans=max(ans,max(dp[k-1][i][1],dp[k-1][i][0]));
		}
		printf("%lld\n",ans+a[0]);
	}
	return 0;
}