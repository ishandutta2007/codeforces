//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll int
#define N 5010
using namespace std;
ll n,a[N],dp[N][N],dp2[N][8],f[N][N],id[100010],ans=0;
int main(){
	ll i,j;
	scanf("%d",&n);
	memset(id,-1,sizeof(id));
	id[a[0]]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		id[a[i]]=i;
	}
	for(i=0;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			dp[i][j]=max((ll)((i==0)?1:2),dp2[i][a[j]%7]+1);
			dp[i][j]=max(dp[i][j],dp[0][i]+1);
			if(id[a[j]-1]!=-1)
			{
				dp[i][j]=max(dp[i][j],f[i][id[a[j]-1]]+1);
			}
			if(id[a[j]+1]!=-1)
			{
				dp[i][j]=max(dp[i][j],f[i][id[a[j]+1]]+1);
			}
//			cout<<dp[i][j]<<" ";
			ans=max(ans,dp[i][j]);
			if(i)
			{
				dp2[j][a[i]%7]=max(dp2[j][a[i]%7],dp[i][j]);
			}
			dp2[i][a[j]%7]=max(dp2[i][a[j]%7],dp[i][j]);
			f[i][id[a[j]]]=max(f[i][id[a[j]]],dp[i][j]);
			if(i)
			{
				f[j][id[a[i]]]=max(f[j][id[a[i]]],dp[i][j]);
			}
		}
//		puts("");
	}
	printf("%d\n",ans);
	return 0;
}