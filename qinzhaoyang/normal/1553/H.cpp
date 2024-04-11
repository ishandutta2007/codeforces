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

const int N = 1 << 20;

int n, k, siz[N];
vector <int> ans[N], L[N], R[N];

void Ins(int a) {
	int p = 1; siz[p]++;
	for (int i = k - 1; i >= 0; i--) {
		int t = (a >> i & 1);
		p = (p << 1 | t), siz[p] ++;
	}
}

void dfs(int x, int dep) {
	if (dep == 0) {
		// cout << (x - (1 << k)) << endl;
		ans[x].pb(inf);
		if (siz[x]) {
			L[x].pb(x - (1 << k));
			R[x].pb(x - (1 << k));
		}
		else L[x].pb(-1), R[x].pb(-1);
		return;
	}
	int lch = (x << 1), rch = (x << 1 | 1);
	dfs(lch, dep - 1), dfs(rch, dep - 1);
	// cout << "Run" << endl;
	// cout << x << " " << dep << endl;
	for (int i = 0; i < (1 << dep); i++) {
		int t = (i >> (dep - 1) & 1),
			B = i - ((1 & t) << (dep - 1));
		// cout << i << " " << t << " " << B << endl;
		ans[x].pb(inf), L[x].pb(-1), R[x].pb(-1);
		ans[x][i] = min(ans[lch][B], ans[rch][B]);
		if (t == 0) {
			if (siz[lch] && siz[rch])
				ckmin(ans[x][i], L[rch][B] - R[lch][B]);
			if (siz[rch] == 0) L[x][i] = L[lch][B], R[x][i] = R[lch][B];
			else if (siz[lch] == 0) L[x][i] = L[rch][B], R[x][i] = R[rch][B];
			else L[x][i] = L[lch][B], R[x][i] = R[rch][B];
		}
		else {
			if (siz[lch] && siz[rch])
				ckmin(ans[x][i], L[lch][B] - R[rch][B] + (1 << dep));
			int tmp = (1 << (dep - 1));
			if (siz[rch] == 0) {
				L[x][i] = L[lch][B] + tmp;
				R[x][i] = R[lch][B] + tmp;
			}
			else if (siz[lch] == 0) {
				L[x][i] = L[rch][B] - tmp;
				R[x][i] = R[rch][B] - tmp;
			}
			else {
				L[x][i] = L[rch][B] - tmp;
				R[x][i] = R[lch][B] + tmp;
			}
		}
	}
}

int main() {
	read(n), read(k);
	for (int i = 1; i <= n; i++) {
		int t; read(t); Ins(t);
	}
	dfs (1, k);
	for (int i = 0; i < (1 << k); i++)
		print(ans[1][i], ' ');
	puts("");
	return 0;
}