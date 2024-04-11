#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define puu pair<ull,ull>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define mset(a, b) memset(a, b, sizeof a)
#define lep(i, j, k) for (int i = (j); i <= (k); i++)
#define rep(i, j, k) for (int i = (j); i >= (k); i--)
#define Lep(i, j, k) for (int i = (j); i < (k); i++)
#define Rep(i, j, k) for (int i = (j); i > (k); i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template <typename T>
inline void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
inline void ckmax(T &A, T B) {A = A > B ? A : B;}

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

const int N = 2e5 + 10;

int gcd(int x, int y) {return y == 0 ? x : gcd(y, x % y);}

int T, n, p[N], c, g[N], inv[N], ct1[N], ct2[N], ans, temp = 1;

int first[N], cur;
struct Edge {int nxt, to, x, y;} e[N << 1];
void con(int x, int y, int a, int b) {
	e[++cur] = (Edge){first[x], y, a, b};
	first[x] = cur;
}

vector <int> res;

void dfs1(int x, int y) {
	for (int i = first[x]; i; i = e[i].nxt) {
		int v = e[i].to; if (v == y) continue;
		int a = e[i].x, b = e[i].y, ta = a, tb = b;
		while (tb != 1) {
			int tmp = g[tb];
			if (ct2[tmp] == 0) {
				ct1[tmp]++;
				if (ct1[tmp] == 1) res.push_back(tmp);
			}
			else ct2[tmp]--;
			tb /= tmp;
		}
		while (ta != 1) {
			int tmp = g[ta];
			ct2[tmp]++;
			ta /= tmp;
		}
		dfs1(v, x);
		while (b != 1) {
			int tmp = g[b];
			ct2[tmp]++;
			b /= tmp;
		}
		while (a != 1) {
			int tmp = g[a];
			ct2[tmp]--;
			a /= tmp;
		}
	}
}

void dfs2(int x, int y) {
	ans = add(ans, temp);
	for (int i = first[x]; i; i = e[i].nxt) {
		int v = e[i].to; if (v == y) continue;
		int a = e[i].x, b = e[i].y, ta = a, tb = b;
		while (tb != 1) {
			int tmp = g[tb];
			temp = mul(temp, inv[tmp]);
			tb /= tmp;
		}
		while (ta != 1) {
			int tmp = g[ta];
			temp = mul(temp, tmp);
			ta /= tmp;
		}
		dfs2(v, x);
		while (b != 1) {
			int tmp = g[b];
			temp = mul(temp, tmp);
			b /= tmp;
		}
		while (a != 1) {
			int tmp = g[a];
			temp = mul(temp, inv[tmp]);
			a /= tmp;
		}
	}
}

int main() {
	for (int i = 2; i <= 200000; i++) {
		if (!g[i]) p[++c] = i, g[i] = i;
		for (int j = 1; j <= c && p[j] * i <= 200000; j++) {
			g[i * p[j]] = p[j];
			if (i % p[j] == 0) break;
		}
	}
	inv[0] = inv[1] = 1;
	for (int i = 2; i <= 200000; i++)
		inv[i] = mul(P - P / i, inv[P % i]);
	for (read(T); T; T--) {
		read(n), ans = 0;
		cur = 0;
		for (int i = 1; i <= n; i++) first[i] = 0;
		while (res.size()) ct1[res.back()] = ct2[res.back()] = 0, res.pop_back();
		for (int i = 1; i < n; i++) {
			int a, b, x, y; scanf("%d%d%d%d", &a, &b, &x, &y);
			int g = gcd(x, y); x /= g, y /= g;
			con(a, b, y, x), con(b, a, x, y);
		}
		dfs1(1, 0);
		temp = 1;
		for (int v : res)
			temp = mul(temp, Pow(v, ct1[v]));
		dfs2(1, 0);
		printf("%d\n", ans);
	}
	return 0;
}