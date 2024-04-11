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
#define LCM 360360
using namespace std;
ll x,y,k,dp[LCM+20],dp2[LCM+20];
int main(){
	ll i,j;
	cin>>x>>y>>k;
	memset(dp,63,sizeof(dp));
	memset(dp2,63,sizeof(dp2));
	dp[0]=0;
	dp2[y%LCM]=0;
	for(i=1;i<=LCM;i++)
	{
		dp[i]=min(dp[i],dp[i-1]+1);
		dp2[i]=min(dp2[i],dp2[i-1]+1);
		for(j=2;j<=k;j++)
		{
			dp[i]=min(dp[i],dp[i-(i%j)]+1);
			dp2[i]=min(dp2[i],dp2[i-(i%j)]+1);
		}
	}
	if(x/LCM==y/LCM)
	{
		cout<<dp2[x%LCM]<<endl;
		return 0;
	}
	cout<<dp[x%LCM]+dp2[LCM]+dp[LCM]*((x/LCM)-(y/LCM)-1)<<endl;
	return 0;
}