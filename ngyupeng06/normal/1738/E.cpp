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

ll n, m, q, k, t, a, b, c;
ll arr[100005], fac[100005], ifac[100005];
ll mod = 998244353;
unordered_map<ll, ll> ml, mr;

ll mi(ll x){
	ll p = mod - 2;
	ll result = 1;
	ll thing = x;
	while (p){
		if (p%2) {
			result *= thing;
			result %= mod;
		}
		thing *= thing;
		thing %= mod;
		p /= 2;
	}
	return result;
}

ll ncr(ll a, ll b){
	if (b > a) return 0;
	return fac[a] * ifac[b] % mod * ifac[a-b] % mod;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	fac[0] = ifac[0] = 1;
	for (int i = 1; i < 100005 ;i++){
		fac[i] = fac[i-1] * i % mod;
		ifac[i] = mi(fac[i]);
	}
	
	cin >> t;
	while (t--) {
		ml.clear(), mr.clear();
		cin >> n;
		ll sum = 0;
		for (int i = 1; i <= n; i++){
			cin >> arr[i];
			sum += arr[i];
		}
		ll l1 = 1e9, r1 = -1;
		ll sum1 = 0, ch = sum / 2;
		if (sum % 2 == 0){
			for (ll i = 1; i <= n-1; i++){
				sum1 += arr[i];
				if (sum1 == ch) {
					l1 = min(l1, i);
					r1 = max(r1, i);
				}
			}
		}
		sum1 = 0, ch = (sum + 1) / 2;
		for (int i = 1; i <= n; i++){
			sum1 += arr[i];
			if (sum1 >= ch) break;
			ml[sum1]++;
		}
		sum1 = 0;
		for (int i = n; i >= 1; i--){
			sum1 += arr[i];
			if (sum1 >= ch) break;
			mr[sum1]++;
		}
		sum1 = 0, ch = (sum + 1) / 2;
		ll ans = 1;
		for (int i = 1; i <= n; i++){
			sum1 += arr[i];
			if (arr[i] == 0 && i > 1) continue;
			if (sum1 >= ch) break;
			ll x = ml[sum1], y = mr[sum1];
		//	cout << x << " " << y << nl;
			if (y) {
				ll th = 0;
				for (ll j = 0; j <= min(x, y); j++){
					th = (th + (ncr(x, j) * ncr(y, j) % mod)) % mod;
				}
				ans = ans * th % mod;
			}
		}
		for (ll i = l1; i <= r1; i++){
			ans = ans * 2 % mod;
		}
		cout << ans << nl;
	}

}