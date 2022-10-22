#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(v) v.begin(),v.end()

ll n, m, t;
ll dp[300006], fac[300006], ifac[300006];
ll mod = 998244353;

ll mi(ll a){
	ll b = mod - 2;
	ll sum = 1;
	ll thing = a;
	while (b){
		if (b%2){
			sum *= thing;
			sum %= mod;
		}
		b/=2;
		thing *= thing;
		thing %= mod;
	}
	return sum;
}

ll ncr(ll a, ll b){
	if (a == 0) return 0;
	if (b == 0) return 1;
	if (b > a) return 0;
	return fac[a] * ifac[b] % mod * ifac[a-b] % mod;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	dp[0] = dp[1] = 1;
	fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
	for (int i = 2; i <= 300005; i++){
		dp[i] = (i-1) * dp[i-2] + dp[i-1];
		dp[i] %= mod;
		fac[i] = fac[i-1] * i % mod;
		ifac[i] = mi(fac[i]);
	}
	cin >> t;
	while (t--) {
		cin >> n;
		ll ans = 0;
		for (int i = 0; 4*i <= n; i++){
			m = n - 4*i;
			ans += (((ncr(2*i + m, 2*i) * fac[2*i] % mod) * ifac[i] % mod) * dp[m] )% mod;
			ans %= mod;
		}
		cout << ans << nl;
	}

}