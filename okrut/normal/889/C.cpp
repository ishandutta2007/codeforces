#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug //
using namespace std; 
typedef long long ll;
typedef long double ld;
 
const int N = 1e6+100;

const ll mod = 1e9+7;
ll sil[N], odwr[N];
ll dp[N];
ll choose (int n, int k)
{
	if (n<0 || k<0 || n<k) return 0;
	return sil[n] * odwr[k] % mod * odwr[n-k] % mod;
}
int main ()
{
	sil[0]= 1LL;
	rep(i,1,N) sil[i] = sil[i-1] * ll(i) % mod;
	odwr[N-1] = 1LL;
	ll a = sil[N-1];
	int pot = mod-2;
	while (pot>0)
	{
		if (pot%2) odwr[N-1] = odwr[N-1] * a % mod;
		a = a*a % mod;
		pot/=2;
	}
	for (int i = N-1; i>0; i--) odwr[i-1] = odwr[i] * ll(i) % mod;
	int n, k;
	scanf ("%d %d", &n, &k);
	
	dp[0] = 0LL;
	ll sum = 0LL;
	ll res = 0LL;
	rep(i,1,n+1)
	{
		if (k+i>n) break;
		debug ("dp[%d]  = %lld * %lld \n", i, sum, sil[i-1]);
		if (i==1) dp[i] = 1;
		else dp[i] = sum * sil[i-2] % mod;
		
		
		ll d = choose(n-1, i+k) * choose(i+k-1,k) % mod * sil[k] % mod * dp[i] % mod * sil[n-k-i] % mod;
		res+= d;
		res%=mod;
		
		debug ("%d: input = %lld (%lld * %lld * %lld *%lld * %lld)\n", i, d, choose(n-1,i+k), choose(i+k-1,k), sil[k], dp[i], sil[n-k-i]);
		
		dp[i] = dp[i] * odwr[i-1] % mod;
		
		debug ("dp[%d]  = %lld \n", i, dp[i]);
		sum+=dp[i];
		if (i>=k) sum+= mod - dp[i-k];
		sum%=mod;
	}
	printf ("%lld\n", res%mod);
}