#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f)) 
#define uint unsigned int
using namespace std;
ll ns = -1;
ll calc(ll k, ll u, ll v, bool op) {
	ll n = u + v;
	if(k <= u) return v + k;
	ll ns = -1;
	if(k / n <= n) {
		L(c, 1, k / n) {
			ll S = k - c * n, p = S / c, r = S % c;
			if(u < r) continue ;
			ll t = (p - v - r + c) / (c + 1);
			t = max(t, 0LL);
			if(r + t * c < op) ++t;
			ll s = p - t, g = r + t * c;
			if(g >= op && s <= g + v && g <= u) return s;
		}
		return ns;
	}
	
	R(sum, n, 0) {
		ll l = max(sum - v, (ll) op);
		ll c = (k - l) / (sum + n);
		ll da = k - (sum + n) * c;
		if(da <= u) return sum;
	}
	return ns;
}
ll n, l, r, k, u, v;
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> l >> r >> k;
	if(n == 1) return cout << 1 << '\n', 0;
	u = (r - l + n) % n + 1, v = n - u;
	k -= u;
	if(k < 0) return cout << -1 << '\n', 0;
	ns = max(ns, calc(k, u, v, false));
	ns = max(ns, calc(k + 1, u, v, true));
	cout << ns << '\n';
	return 0;
} //