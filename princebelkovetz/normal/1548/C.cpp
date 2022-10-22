#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7, N = 3e6 + 5, bb = 32;

vector <int> fact(N), rfact(N);

int binpow(int a, int b) {
	if (!b) return 1;
	if (b & 1) return a * binpow(a, b - 1) % mod;
	int t = binpow(a, b / 2);
	return t * t % mod;
}

int C(int n, int k) {
	if (k > n or k < 0) return 0;
	int res = fact[n] * rfact[k] % mod;
	return res * rfact[n - k] % mod;
}

vector <int> divide(vector <int> p, vector <int> s) {
	int n = p.size(), m = s.size();
	vector <int> res;
	for (int i = n - 1; i >= m - 1; --i) {
		int mul = p[i];
		for (int j = 0; j < m; ++j) {
			p[i - j] -= mul * s[m - 1 - j] % mod;
			p[i - j] = (p[i - j] + mod) % mod;
		}
		res.push_back(mul);
	}
	reverse(res.begin(), res.end());
	return res;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	fact[0] = rfact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = fact[i - 1] * i % mod;
		rfact[i] = binpow(fact[i], mod - 2);
	}

	int n, q; cin >> n >> q;

	vector <int> p(3 * n + 4), s(4);
	for (int i = 0; i <= 3 * n + 3; ++i) {
		p[i] = C(3 * n + 3, i) - C(3, i);
	}
	for (int i = 0; i <= 3; ++i) {
		s[i] = C(3, i) - C(0, i);
	}

	for (auto& x : p) x = (x + mod) % mod;
	for (auto& x : s) x = (x + mod) % mod;

	p = divide(p, s);

	while (q --> 0) {
		int x; cin >> x;
		cout << p[x] << '\n';
	}

	return 0;
}