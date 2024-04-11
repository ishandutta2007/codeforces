#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2e5 + 7, mod = 998244353;
int n, x, hb, a[N], pw[N], ns;
map < int, vi > mp;
int calc (vi A, vi B, int p) {
	if(!sz(A) || !sz(B)) return 0;
	if(p < 0) {
		return (ll) (pw[sz(A)] - 1) * (pw[sz(B)] - 1) % mod;
	}
	int ns = 0;
	vi a[2], b[2];
	for (const int &u : A) a[u >> p & 1].push_back (u & ((1 << p) - 1));
	for (const int &u : B) b[u >> p & 1].push_back (u & ((1 << p) - 1));
	if(x >> p & 1) {
		int x = (pw[sz(a[0])] + pw[sz(b[1])] - 1) % mod, y = (pw[sz(a[1])] + pw[sz(b[0])] - 1) % mod; 
		(ns += (ll) (calc (a[0], b[1], p - 1) + x) * (calc (a[1], b[0], p - 1) + y) % mod) %= mod;
		(ns += mod - (pw[sz(A)] + pw[sz(B)] - 1) % mod) %= mod;
	} else (ns += calc (a[0], b[0], p - 1)) %= mod, (ns += calc (a[1], b[1], p - 1)) %= mod;
	return ns;
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> x;
	pw[0] = 1;
	L(i, 1, n) pw[i] = (ll) pw[i - 1] * 2 % mod; 
	L(i, 0, 30) if(x >> i & 1) hb = i;
	L(i, 1, n) 
		cin >> a[i], mp[a[i] >> (hb + 1)].push_back(a[i] & ((1 << (hb + 1)) - 1));
	for (auto w : mp) {
		vi ra, rb;
		vi S = w.second;
		for (const int &u : S) 
			if(u >> hb & 1) ra.push_back (u & ((1 << hb) - 1)) ;
			else rb.push_back (u & ((1 << hb) - 1));
		(ns += pw[sz(ra)] - 1) %= mod;
		(ns += pw[sz(rb)] - 1) %= mod;
		if(x) 
			(ns += calc(ra, rb, hb - 1)) %= mod;
	}
	cout << ns << '\n';
	return 0;
}