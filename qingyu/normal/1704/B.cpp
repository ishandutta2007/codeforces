#include <bits/stdc++.h>

using namespace std;

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int l = 1, r = 0, ans = -1;
		for (int i = 1; i <= n; ++i) {
			int y;
			cin >> y;
			l = max(l, y - x);
			r = min(r, y + x);
			if (l > r) {
				++ans;
				l = y - x, r = y + x;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}