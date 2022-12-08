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

const int N = 1e3 + 10;

int n, d, fa[N], s[N];
int b[N], c;

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void con(int x, int y) {
	if (find(x) != find(y)) {
		s[fa[y]] += s[fa[x]];
		fa[fa[x]] = fa[y];
	}
}

inline int cmp(int x, int y) {
	return s[x] > s[y];
}

int main() {
	read(n), read(d);
	for (int i = 1; i <= n; i++)
		fa[i] = i, s[i] = 1;
	int ned = 0;
	for (int i = 1; i <= d; i++) {
		int x, y; read(x), read(y);
		if (find(x) != find(y))
			con(x, y), ned++;
		c = 0;
		for (int j = 1; j <= n; j++)
			if (fa[j] == j) b[++c] = j;
		sort (b + 1, b + c + 1, cmp);
		int ans = 0;
		for (int j = 1; j <= i - ned + 1; j++)
			ans += s[b[j]];
		print(ans - 1, '\n');
	}
	return 0;
}