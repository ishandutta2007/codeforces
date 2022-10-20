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

const int N = 110;

int n, ok[N][N][N], fa[N * N], siz[N * N], d[N][N];
char s[N];

int id(int x, int y) {
	if (x > y) swap(x, y);
	return (x - 1) * n + y;
}

int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
void con(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	siz[y] += siz[x], fa[x] = y;
}

int nfa[N];

int nfind(int x) {return nfa[x] == x ? x : nfa[x] = nfind(nfa[x]);}
void ncon(int x, int y) {
	x = nfind(x), y = nfind(y);
	if (x == y) return;
	nfa[x] = y;
}

void fl() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n * n; i++)
		fa[i] = i, siz[i] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n - i; j++) {
			scanf("%s", s + 1);
			for (int k = 1; k <= n; k++) {
				ok[i][i + j][k] = s[k] - '0';
				if (s[k] == '1') con(id(i, k), id(i + j, k));
			}
		}
	}
	//n = 2
	for (int i = 1; i <= n * n; i++) {
		if (siz[i] != n - 1 || find(i) != i) continue;
		for (int j = 1; j <= n; j++)
			nfa[j] = j;
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				d[j][k] = inf;
		for (int j = 1; j <= n; j++)
			d[j][j] = 0;
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				if (find(id(j, k)) == find(i)) {
					ncon(j, k);
					d[j][k] = d[k][j] = 1;
				}
		int flag = 1;
		for (int j = 1; j <= n; j++)
			if (nfind(j) != nfind(1))
				flag = 0;
		if (!flag)
			continue;
		fl();
		for (int j = 1; j < n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int o = 1; o <= n; o++) {
					if (ok[j][k][o] != (d[j][o] == d[k][o])) {
						flag = 0;
						break;
					}
					if (flag == 0) break;
				}
				if (flag == 0) break;
			}
			if (flag == 0) break;
		}
		if (flag == 1) {
			puts("Yes");
			for (int j = 1; j <= n; j++)
				for (int k = j + 1; k <= n; k++)
					if (find(id(j, k)) == find(i))
						printf("%d %d\n", j, k);
			return;
		}
	}
	puts("No");
}

int T;

int main() {
	for (scanf("%d", &T); T; T--) solve();
	return 0;
}