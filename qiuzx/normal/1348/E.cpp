//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 510
using namespace std;
ll n,k,a[N],b[N],ans=0,sum=0;
bool dp[N][N];
int main(){
	ll i,j,l,mx;
	scanf("%lld%lld",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&a[i],&b[i]);
		sum+=a[i]+b[i];
	}
	memset(dp,false,sizeof(dp));
	dp[0][0]=true;
	for(i=0;i<n;i++)
	{
		for(j=0;j<k;j++)
		{
			if(!dp[i][j])
			{
				continue;
			}
			dp[i+1][(j+a[i])%k]=true;
			for(l=0;l<min(k,a[i]+1);l++)
			{
				if(b[i]+(a[i]+k-l)%k>=k)
				{
					dp[i+1][(j+l)%k]=true;
				}
			}
		}
	}
	for(i=0;i<k;i++)
	{
		if(dp[n][i])
		{
			ans=(sum-i)/k;
			break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}