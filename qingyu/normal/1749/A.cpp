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

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
	}
	if (n == m) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
	}
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