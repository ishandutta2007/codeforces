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

typedef long long ll;

ll c[N];
__int128 sum[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			sum[i] = 0;
			for (int j = 1; j <= m; ++j) {
				ll z;
				cin >> z;
				sum[i] += (__int128)j * z;
			}
		}
		__int128 sp = 0;
		if (sum[1] == sum[2]) sp = sum[1];
		else if (sum[1] == sum[3]) sp = sum[1];
		else sp = sum[2];
		int k = -1;
		long long delta = -1;
		for (int i = 1; i <= n; ++i)
			if (sum[i] != sp) {
				k = i;
				delta = sum[i] - sp;
				break;
			}
		std::cout << k << ' ' << delta << '\n';
	}
	return 0;
}