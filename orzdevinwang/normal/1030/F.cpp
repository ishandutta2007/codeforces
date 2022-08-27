#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 3e5 + 7, mod = 1e9 + 7; 
int n, q, a[N], w[N];
struct fenwt {
	ll a[N], n = N - 1;
	void add (int x, int w) {
		for (; x <= n; x += x & -x) a[x] += w;
	}
	ll query (int x) {
		ll ret = 0;
		for (; x; x -= x & -x) ret += a[x];
		return ret;
	}
	ll get (int l, int r) {
		if(l > r) return 0;
		return query (r) - query (l - 1);
	}
} s, S;
int getid (ll x, int L, int R) {
	int l = L, r = R, ns = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if(s.get(L, mid) >= x) ns = mid, r = mid - 1;
		else l = mid + 1;
	}
	return ns;
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	L(i, 1, n) cin >> a[i], a[i] -= i;
	L(i, 1, n) cin >> w[i], s.add(i, w[i]), S.add(i, (ll) w[i] * a[i] % mod);
	while (q--) {
		int l, r;
		cin >> l >> r;
		if(l < 0) 
			l = -l, s.add(l, r - w[l]), S.add(l, (ll) (r - w[l] + mod) * a[l] % mod), w[l] = r;
		else {
			int mid = getid((s.get(l, r) + 1) / 2, l, r), ns = 0;
//			L(i, l, mid) (ns += (ll) w[i] * (mod - a[i]) % mod) %= mod;
//			L(i, mid, r) (ns += (ll) w[i] * a[i] % mod) %= mod;
			(ns += mod - S.get(l, mid) % mod) %= mod;
			(ns += S.get(mid, r) % mod) %= mod;
			(ns += (ll) (s.get(l, mid) - s.get(mid, r) + mod) * a[mid] % mod) %= mod;
			cout << ns << '\n';
		}
	}
	return 0;
}