#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 1e5 + 7;
int n, m, seed, vmax;
int qpow (int x, int y, int mod) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
map < int, ll > mp;
int rnd () {
	int ret = seed;
	seed = ((ll) seed * 7 + 13) % 1000000007;
	return ret; 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie (0); cout.tie (0); 
	cin >> n >> m >> seed >> vmax;
	L(i, 1, n) mp[i] = rnd () % vmax + 1;
	mp[n + 1] = -1; 
	while (m--) {
		int op, l, r, x, y;
		op = rnd () % 4 + 1, l = rnd () % n + 1, r = rnd() % n + 1;
		if (l > r) swap (l, r);
		++ r;
		// [l, r)
		if (op == 3) x = rnd () % (r - l) + 1;
		else x = rnd() % vmax + 1;
		auto L = --mp.upper_bound(l), R = --mp.upper_bound(r);
		if (L -> first != l) mp[l] = L -> second, L = --mp.upper_bound(l);
		if (R -> first != r) mp[r] = R -> second, R = --mp.upper_bound(r);
		if (op == 1) while (L != R) L -> second += x, L++;
		if (op == 2) L -> second = x, L ++, mp.erase (L, R);
		if (op == 3) {
			vector < pair < ll, int > > s;
			ll ls1, ls2;
			while (L != R) ls1 = L -> first, ls2 = L -> second, ++L, s.push_back(make_pair(ls2, L -> first - ls1));
			sort(s.begin(), s.end());
			L(i, 0, sz(s) - 1) {
				if(x <= s[i].second) {
					cout << s[i].first << "\n";
					break;
				}
				x -= s[i].second;
			} 
		}
		if (op == 4) {
			y = rnd () % vmax + 1;
			int ns = 0, ls1, ls2;
			while (L != R) ls1 = L -> first, ls2 = L -> second % y, L++, 
				(ns += (ll) qpow (ls2, x, y) * ((L -> first) - ls1) % y) %= y;
			cout << ns << "\n";
		}
	}
	return 0;
}