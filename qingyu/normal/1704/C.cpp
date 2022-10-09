#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 50;
const int mod = 998244353;
 
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

int a[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= m; ++i) cin >> a[i];
		sort(a + 1, a + m + 1);
		for (int i = 1; i <= m - 1; ++i) 
			b[i] = a[i + 1] - a[i] - 1;
		b[m] = n - a[m] + a[1] - 1;
		sort(b + 1, b + m + 1);
		int ans = n;
		// PA21
		for (int i = m; i >= 1; --i) {
			if (b[i] <= 4 * (m - i))
				break;
			ans -= std::max(1, b[i] - (m - i) * 4 - 1);
		}
		std::cout << ans << '\n';
	}
	return 0;
}