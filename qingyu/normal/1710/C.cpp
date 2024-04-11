#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 50;
const int mod = 998244353;
int f[N][8][2][2];
string str;

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
	cin >> str;
	int n = str.size();
	int x = 0;
	for(int i = 0; i < n; ++i) x = (x * 2 + str[i] - '0') % mod;
	reverse(str.begin(), str.end());
	f[0][0][0][0] = 1;
	for(int i = 0; i < n; ++i) {
		int limit = str[i] - '0';
		for(int s1 = 0; s1 < 8; ++s1) {
			for(int s2 = 0; s2 < 2; ++s2) {
				for(int d = 0; d < 2; ++d) if(f[i][s1][s2][d]) {
					for(int c1 = 0; c1 <= 1; ++c1) {
						int da = c1 < limit ? 0 : (c1 == limit ? s1 & 1 : 1);
						for(int c2 = 0; c2 <= 1; ++c2) {
							int db = c2 < limit ? 0 : (c2 == limit ? s1 >> 1 & 1 : 1);
							for(int c3 = 0; c3 <= 1; ++c3) {
								int dc = c3 < limit ? 0 : (c3 == limit ? s1 >> 2 : 1);
								int x = c1 ^ c2, y = c1 ^ c3, z = c2 ^ c3;
								int a = x, b = y + z + s2, ds2 = b > 1, dd, ds = da | db << 1 | dc << 2;
								b &= 1;
								if (a == b) dd = d;
								if (a < b) dd = 1;
								if (a > b) dd = 0;
								upd(f[i + 1][ds][ds2][dd], f[i][s1][s2][d]);
							}
						}
					}
				}
			}
		}
	}
	++x;
	int ans = mul(3, f[n][0][0][0]);
	dpu(ans, mul(3, mul(x, x)));
	upd(ans, x);
	int y = mul(mul(x, x), x);
	ans = dec(y, ans);
	cout << ans << '\n';
	return 0;
}