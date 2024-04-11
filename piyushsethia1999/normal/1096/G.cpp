#include <bits/stdc++.h>
#define pb emplace_back
#define int long long
#define ll long long
#define mp make_pair

using namespace std;

int root = 15311432, root_1 = 469870224, MOD = 998244353, root_pw = 1 << 23;

int powm(int a, int b, int m)
{
	int res = 1;
	while (b) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

void ntt(vector<int32_t> & a, bool invert) {
	int n = a.size();

	for (int32_t i = 1, j = 0; i < n; i++) {
		int32_t bit = n >> 1;
		for (; j & bit; bit >>= 1)
			j ^= bit;
		j ^= bit;

		if (i < j)
			swap(a[i], a[j]);
	}

	for (int32_t len = 2; len <= n; len <<= 1) {
		int32_t wlen = invert ? root_1 : root;
		for (int32_t i = len; i < root_pw; i <<= 1)
			wlen = (int32_t)(1LL * wlen * wlen % MOD);
		for (int32_t i = 0; i < n; i += len) {
			int32_t w = 1;
			for (int32_t j = 0; j < len / 2; j++) {
				int32_t u = a[i + j], v = (int32_t)(1LL * a[i + j + len / 2] * w % MOD);
				a[i + j] = u + v < MOD ? u + v : u + v - MOD;
				a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + MOD;
				w = (int32_t)(1LL * w * wlen % MOD);
			}
		}
	}

	if (invert) {
		int32_t n_1 = powm(n, MOD - 2, MOD);
		for (int32_t & x : a)
			x = (1LL * x * n_1 % MOD);
	}
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	auto tim = clock();
	int n; cin >> n;
	int k; cin >> k;
	std::vector<int32_t> a(1 << 21, 0);
	for (int i = 0; i < k; ++i)
	{
		int x; cin >> x;
		a[x]++;
	}
	ntt(a, false);
	for (int i = 0; i < a.size(); ++i)
		a[i] = (int32_t)(powm(a[i], n / 2, MOD));
	ntt(a, true);
	int re = 0;
	for (int i = 0; i < a.size(); ++i)
		re += (1LL * a[i] * a[i] % MOD);
	cout << (re % MOD);
}