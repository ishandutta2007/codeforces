#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 600100
#define MOD 1000000007  //998244353
#define ll long long
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define rep2(i, a, b) for(ll i = a; i <= b; ++i)
#define rep3(i, a, b) for(ll i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>


int main() {
	ll c[62];
	ll p2[62];
	ll a[N];
	ll s, ans, x, y, z, n, ss;
	p2[0] = (ll)1;
	rep(i, 61)p2[i + 1] = (p2[i] * 2) % MOD;
	ll t;
	cin >> t;
	rep(tt, t) {
		cin >> n;
		rep(i, 60)c[i] = 0;
		ss = 0;
		rep(i, n) {
			cin >> a[i];
			ss = (ss + a[i]) % MOD;
			x = a[i];
			rep(j, 60) {
				if (x % 2 == 1)c[j]++;
				x /= 2;
			}
		}
		ans = 0;
		rep(i, n) {
			x = a[i];
			s = 0;
			rep(j, 60) {
				if (x % 2 == 1) {
					y = (c[j] * p2[j]) % MOD;
					s = (s + y) % MOD;
				}
				x /= 2;
			}
			x = a[i] % MOD;
			x = (x*n) % MOD;
			x = (x*s) % MOD;
			ans = (ans + x) % MOD;
			x = (ss*s) % MOD;
			ans = (ans + x) % MOD;
			x = (s*s) % MOD;
			ans = (ans + MOD - x) % MOD;
		}
		cout << ans << endl;
	}

	return 0;
}