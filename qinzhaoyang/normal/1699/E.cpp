#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(X) (X).begin(), (X).end()
#define lep(i, j, k) for (int i = (j); i <= (k); i++)
#define rep(i, j, k) for (int i = (j); i >= (k); i--)
#define Lep(i, j, k) for (int i = (j); i < (k); i++)
#define Rep(i, j, k) for (int i = (j); i > (k); i--)

using namespace std;

using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;

template <typename T>
void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

namespace MOD {
	const int P = 998244353;
	inline int add(int x, int y) {return x + y >= P ? x + y - P : x + y;}
	inline int sub(int x, int y) {return x < y ? x - y + P : x - y;}
	inline int mul(int x, int y) {return (long long)x * y % P;}
	inline void inc(int &x, int y) {x = add(x, y);}
	inline void dec(int &x, int y) {x = sub(x, y);}
	inline void upd(int &x, int y) {x = mul(x, y);}
	inline int Pow(int x, int y) {int r = 1; for (; y; y >>= 1, x = mul(x, x)) if (y & 1) r = mul(r, x); return r;}
};
using namespace MOD;

const int N = 5e6 + 10;

int T, n, m, a[N], c[N], f[N];

void solve() {
	read(n), read(m);
	for (int i = 1; i <= m; i++)
		c[i] = f[i] = 0;
	int all = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]), c[a[i]]++;
		if (c[a[i]] == 1) all++;
	}
	f[1] = 1; int nw = 0, ans = 0x3f3f3f3f;
	if (c[1]) nw++;
	for (int l = 1, r = 1; l <= m; l++) {
		while (r <= m && nw < all) {
			++r;
			for (int i = r; i <= m; i += r) {
				if (!f[i] && f[i / r] && c[i]) nw++;
				inc(f[i], f[i / r]);
			}
		}
		if (nw < all) break;
		if (l == r) {
			ans = 0;
			break;
		}
		ans = min(ans, r - l);
		if (c[1]) break;
		if (l > 1) {
			for (int i = m / l * l; i >= 1; i -= l) {
				if (f[i] && f[i] == f[i / l] && c[i]) nw--;
				dec(f[i], f[i / l]);
			}
		}
	}
	printf("%d\n", ans);
}

int main() {
	for (read(T); T; T--) solve();
	return 0;
}