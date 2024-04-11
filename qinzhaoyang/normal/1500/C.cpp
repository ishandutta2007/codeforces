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
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a < b ? b : a)

typedef long long ll;
typedef unsigned long long ull;
typedef std::vector <int> Vi;
typedef std::vector <ll> Vl;

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
inline void read(char &x) {scanf(" %c", &x);}

const int N = 1510;

int n, m, A[N][N], B[N][N], tl[N], tr[N], c, cAns, Ans[N], per[N], vis[N], C[N];
std::queue <int> Q;

int cmp(int x, int y) {
	for (int i = 1; i <= cAns; i++) {
		if (A[x][Ans[i]] != A[y][Ans[i]])
			return A[x][Ans[i]] < A[y][Ans[i]];
	}
	return x < y;
}

int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			read(A[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			read(B[i][j]);
	for (int j = 1; j <= m; j++)
		for (int i = 2; i <= n; i++)
			C[j] += (B[i - 1][j] > B[i][j]);
	for (int j = 1; j <= m; j++)
		if (!C[j]) Q.push(j), vis[j] = 1;
	tl[c = 1] = 1, tr[c] = n;
	while (Q.size()) {
		int p = Q.front(); Q.pop();
		int tc = c; Ans[++cAns] = p;
		for (int i = 1; i <= tc; i++) {
			int l = tl[i], r = tr[i], id = i;
			for (int k = l + 1; k <= r; k++) if (B[k - 1][p] < B[k][p]) {
				for (int j = 1; j <= m; j++) if (!vis[j] && B[k - 1][j] > B[k][j]) {
					if(!(--C[j])) Q.push(j), vis[j] = 1;
				}
				tr[id] = k - 1, tl[++c] = k, tr[c] = r, id = c;
			}
		}
	}
	for (int i = 1; i <= n; i++) per[i] = i;
	std::sort (per + 1, per + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (A[per[i]][j] != B[i][j])
				return puts("-1"), 0;
	print(cAns, '\n');
	for (int i = cAns; i >= 1; i--)
		print(Ans[i], " \n"[i == 1]);
	return 0;
}