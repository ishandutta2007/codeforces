#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 50;
const int mod = 998244353;

int f[N], g[N], h[N];

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
 
inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }
 
inline int fastpow(int x, int p) {
	int r = 1;
	while (p) {
		if (p & 1) pud(r, x);
		pud(x, x);
		p >>= 1;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	int sum = 0;
	g[0] = 1;
	for (int i = k; i <= n; ++i) {
		if (sum > n) break;
		for (int j = 0; j < sum; ++j) {
			f[j] = 0;
		}
		for (int j = sum; j <= n; ++j) {
			f[j] = inc(f[j - i], g[j - i]);
			upd(h[j], f[j]);
		}
		for (int i = 0; i <= n; ++i) g[i] = f[i];
		sum += i;
	}
	for (int i = 1; i <= n; ++i)
		cout << h[i] << " \n"[i == n];
	return 0;
}