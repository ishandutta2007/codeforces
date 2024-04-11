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

const int N = 1e5 + 10;

typedef unsigned long long ull;

const int P = 998244353;

const int B = 271, Bf = 233;

struct Node {int a[5], w;} o[N];
int n, m, siz[33];
pair <ull, int> hsh1[N][33];
int hsh[N][33];

inline bool cmp(Node x, Node y) {
	return x.w < y.w;
}

pair<ull,int> ab[N * 33];
int top;
vector <int> p[N * 33];
int s[N * 33];

int check(int l, int r) {
	int ret = l;
	for (int i = 1; i < (1 << m); i++) {
		int &k = s[hsh[r][i]];
		while (k > 0 && p[hsh[r][i]][k - 1] > l) k--;
		if (siz[i] & 1) ret -= k;
		else ret += k;
	}
	return ret;
}

int main() {
	read(n), read(m);
	for (int i = 1; i < (1 << m); i++)
		siz[i] = siz[i >> 1] + (i & 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++)
			read(o[i].a[j]);
		sort (o[i].a, o[i].a + m);
		read(o[i].w);
		int flag = 0;
		for (int j = 0; j < m - 1; j++)
			if (o[i].a[j] == o[i].a[j + 1])
				flag = 1;
		if (flag) n--, i--;
	}
	sort (o + 1, o + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < (1 << m); j++) {
			ull t = 0;
			int t2 = 0;
			for (int k = 0; k < m; k++)
				if (j >> k & 1) {
					t = t * B + o[i].a[k];
					t2 = 1ll * t2 * Bf % P;
					t2 = (t2 + o[i].a[k]) % P;
				}
			hsh1[i][j] = mp(t, t2);
			ab[++top] = mp(t, t2);
		}
	sort (ab + 1, ab + top + 1);
	top = unique (ab + 1, ab + top + 1) - ab - 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < (1 << m); j++) {
			hsh[i][j] = lower_bound(ab + 1, ab + top + 1, hsh1[i][j]) - ab;
			p[hsh[i][j]].pb(i);
		}
	for (int i = 1; i <= top; i++)
		s[i] = p[i].size();
	int ans = 2e9 + 1, lst = n;
	for (int i = 2; i <= n; i++) {
		if (lst == 1 || check(lst, i) == 0) continue;
		while (lst > 1 && check(lst - 1, i)) lst--;
		ans = min(ans, o[i].w + o[lst].w);
	}
	printf("%d\n", ans == 2e9 + 1 ? -1 : ans);
	return 0;
}