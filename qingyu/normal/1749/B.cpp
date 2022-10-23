#include <bits/stdc++.h>

using namespace std;

#define QINGYU_LOCAL
#ifdef QINGYU_LOCAL
#define debug(x) \
        cerr << "Func " << __FUNCTION__ << ", " << "L" << __LINE__ << ": " << #x << " = " << x << '\n'
#else
#define debug(x) 0
#endif

const int mod = 1e9 + 9;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }  
inline int mul(int x, int y) { return 1ll * x * y % mod; }

inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

inline int fastpow(int x, int64_t p) {
	int r = 1;
	while (p) {
		if (p & 1) pud(r, x);
		pud(x, x);
		p >>= 1;
	}
	return r;
}

const int N = 5e5 + 50;

int64_t a[N], b[N], sa[N], sb[N];

void solve() {
	int n;
	cin >> n;
	int64_t ans = 1e18, suma = 0, sumb = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sa[i] = sa[i - 1] + a[i];
		suma += a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		sb[i] = sb[i - 1] + b[i];
		sumb += b[i];
	}
	for (int i = 1; i <= n; ++i) {
		ans = min(ans, suma + sumb - b[i]);
	}
	cout << ans << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}

}