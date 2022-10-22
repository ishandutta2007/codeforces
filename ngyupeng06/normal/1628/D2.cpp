#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll k, n, m, t, mod = 1e9 + 7, fac[1000005], ifac[1000005];
ll dp[2005][2005];

ll mex(ll a, ll b){
	ll x = 1, thing = a;
	while (b){
		if (b%2){
			x = x * thing % mod;
		}
		b/=2;
		thing *= thing;
		thing %= mod;
	}
	return x;
}

ll muli(ll a){
	return mex(a, mod-2);
}

ll ncr(ll a, ll b){
	return fac[a] * ifac[b] % mod * ifac[a-b] % mod;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	fac[0] = ifac[0] = 1;
	for (int i=1; i<1000005; i++){
		fac[i] = fac[i-1] * i % mod;
		ifac[i] = muli(fac[i]);
	}
	while (t--){
		cin >> n >> m >> k;
		ll sum = 0;
		if (m != n){
			for (int i=1; i<=n; i++){
				ll x = i*k%mod *mex(2,i-1)%mod;
				if (m >= i) sum = (sum + x * ncr(n-i, m-i) % mod) % mod;
				if (m > i) sum = (sum - x * ncr(n-i-1, m-i-1) % mod + 3 * mod )% mod;
			}
		}
		else sum = n*k%mod *mex(2,n-1)%mod;
		cout << sum * muli(mex(2,n-1)) % mod << "\n";
	}
}