#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define P 51123987
#define maxn 4000005
 
int n,m,i;
double a[101],dp[2][101],res;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	dp[0][0]=1;
	dp[1][0]=0;
	for (i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n+1);
	for (i=1;i<=n;i++)
	{
		dp[0][i]=dp[0][i-1]*(1-a[n+1-i]);
		dp[1][i]=dp[1][i-1]*(1-a[n+1-i])+dp[0][i-1]*a[n+1-i];
		if (res<dp[1][i]) res=dp[1][i];
	}
	cout<<fixed<<setprecision(10)<<res;
}