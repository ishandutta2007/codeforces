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
void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

const int N = 1e5 + 10;

int q, n;
char s[N], t[N];
int st[26][N], top[26], nw[26];

struct ST {
	int a[N];
	void init() {for (int i = 1; i <= n; i++) a[i] = 0;}
	void Mdf(int x, int c) {
		for (; x <= n; x += x & (-x)) a[x] += c;
	}
	int Qry(int x) {
		int r = 0;
		for (; x; x -= x & (-x)) r += a[x];
		return r;
	}
}	ts;

int main() {
	for (read(q); q; q--) {
		read(n), ts.init();
		scanf("%s%s", s + 1, t + 1);
		for (int i = 0; i < 26; i++) top[i] = nw[i] = 0;
		for (int i = 1; i <= n; i++) {
			int c = s[i] - 'a';
			st[c][++top[c]] = i;
		}
		ll ans = infll, tmp = 0, sum = 0;
		for (int i = 1; i <= n; i++) {
			int minp = n + 1, c = t[i] - 'a';
			for (int j = 0; j < c; j++)
				if (top[j] != nw[j])
					minp = min(minp, st[j][nw[j] + 1]);
			if (minp != n + 1) ans = min(ans, sum + minp - 1ll * i * (i + 1) / 2 + tmp + ts.Qry(n) - ts.Qry(minp));
			if (top[c] == nw[c]) break;
			int np = st[c][++nw[c]];
			tmp += ts.Qry(n) - ts.Qry(np), ts.Mdf(np, 1);
			sum += np;
		}
		if (ans == infll) puts("-1");
		else printf("%lld\n", ans);
	}
	return 0;
}