#include <bits/stdc++.h>

using namespace std;

#define QINGYU_LOCAL
#ifdef QINGYU_LOCAL
#define debug(x) \
        cerr << "Func " << __FUNCTION__ << ", " << "L" << __LINE__ << ": " << #x << " = " << x << '\n'
#else
#define debug(x) 0
#endif

const int mod = 998244353;

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

const int N = 1e6 + 50;
long long a[N], b[N], c[N];
map<long long, long long> g1, g2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	long long sum = 0, g = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i] >> c[i];
		g1[a[i]] += c[i];
		g2[b[i]] += c[i];
		sum += c[i];
		g = gcd(g, c[i]);
	}
	for (int i = 1; i <= n; ++i) {
		__int128 x1 = g1[a[i]];
		__int128 y1 = sum;
		__int128 x2 = c[i];
		__int128 y2 = g2[b[i]];
		if (x1 * y2 != x2 * y1) {
			cout << 0 << '\n';
			return 0;
		}
	}
	int ans = 0;
	for (long long i = 1; i * i <= g; ++i)
		if (g % i == 0) {
			++ans;
			if (i * i != g)
				++ans;
		}
	cout << ans << '\n';
}