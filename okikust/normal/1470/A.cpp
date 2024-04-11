#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
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
	ll t, n, k, m;
	ll x, y, z;
	ll s, ans;
	vector<ll> a, b;
	bool v;
	cin >> t;
	rep(tt, t) {
		a.clear();
		b.clear();
		cin >> n >> m;
		rep(i, n) {
			cin >> x;
			a.pb(x - 1);
		}
		rep(i, m) {
			cin >> x;
			b.pb(x);
		}
		sort(all(a), greater<ll>());
		ans = 0;
		rep(i, n) {
			if (a[i] >= i)ans += b[i];
			else ans += b[a[i]];
		}
		cout << ans << endl;
	}
	return 0;
}