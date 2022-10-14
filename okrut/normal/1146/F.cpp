#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi fist
#define se second
#define mitte (lewy+prawy)/2
#define debug //
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 998244353LL;
const int N = 2e5 + 1;
vector <vector <int> > graf;
ll dp[N][3];

ll odwr (ll a)
{
	int k = mod-2;
	ll ret =1;
	while (k>0)
	{
		if (k%2==0) ret = ret * a % mod;
		 a = a * a % mod;
		 k/=2;
	}
	return ret;
}
void dfs (int a)
{
	if ((int)graf[a].size()==0)
	{
		debug ("leaf %d\n", a);
		dp[a][0]=1; //moge byc samodzielny
		dp[a][1]=1; //moge nie byc samodzielny
		dp[a][2]=0; //nie do 2
		return;
	}
	
	dp[a][0]=1LL; //roboczo
	dp[a][2]=0LL;
	dp[a][1]=0LL;
	
	for (int s: graf[a])
	{
		dfs(s);
		
		dp[a][2] = dp[a][2] * (dp[s][0] + dp[s][1] + 2LL * dp[s][2]) % mod + dp[a][1] * (dp[s][1] + dp[s][2]) % mod;
		dp[a][1] =	dp[a][0] * (dp[s][1] + dp[s][2]) + dp[a][1] * (dp[s][0] + dp[s][2]); 
		
		dp[a][0] *= dp[s][0] + dp[s][2];
		
		rep(i,0,3) dp[a][i]%=mod;
	}
}
int main ()
{
	int n;
	scanf ("%d", &n);
	graf.resize(n+1);
	int a;
	rep(i,2,n+1)
	{
		scanf ("%d", &a);
		graf[a].pb(i);
	}
	dfs(1);
	
	rep(i,1,n+1) debug("%d: %lld %lld %lld\n", i, dp[i][0], dp[i][1], dp[i][2]);
	
	printf ("%lld\n", (dp[1][0] + dp[1][2] ) % mod);
}