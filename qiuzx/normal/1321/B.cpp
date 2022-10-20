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
#define N 700010
using namespace std;
ll n,be[N],dp[N],ds[N],ans=0;
int main(){
	ll i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>be[i];
		ds[i]=be[i]-i+200000;
	}
	memset(dp,0,sizeof(dp));
	for(i=0;i<n;i++)
	{
		dp[ds[i]]=max(dp[ds[i]],dp[ds[i]]+be[i]);
		ans=max(ans,dp[ds[i]]);
	}
	cout<<ans<<endl;
	return 0;
}