#pragma GCC optimize("Ofast")
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

const int N = 1e5 + 10, M = 35000000;
const int B = 350;

int n, a[N], ans = 0, fa[N], s[N], mpa[M * 2 + N * 2], cct[2 * N];

inline int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}

struct Node {int x, y, w;};
Node v[35000010];
int ed;

inline int cmp(Node a, Node b) {
	return a.w < b.w;
}

void calc(int l, int r) {
	for (int i = l; i <= r; i++) {
		int a = v[i].x, b = v[i].y;
		a = find(a), b = find(b);
		if (a != b) {
			ans = max(ans, s[a] + s[b]);
			s[b] += s[a], fa[a] = b;
		}
	}
	for (int i = l; i <= r; i++) {
		int a = v[i].x, b = v[i].y;
		fa[a] = a, s[a] = 1;
		fa[b] = b, s[b] = 1;
	}
}

int main() {
	//freopen("1.in", "r", stdin);
	//clock_t st = clock();
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = -350; i <= 350; i++) {
		for (int j = 1; j <= n; j++) {
			ans = max(ans, (++mpa[a[j] + i * j + M]));
		}
		for (int j = 1; j <= n; j++)
			mpa[a[j] + i * j + M]--;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= i + B && j <= n; j++)
			if ((a[j] - a[i]) % (j - i) == 0) {
				int temp = (a[j] - a[i]) / (j - i);
				if (-350 <= temp && temp <= 350) continue;
				int ttc = temp + 100000;
				if (cct[ttc] > 0) {
					cct[ttc]++;
					continue;
				}
				v[++ed] = (Node){i, j, ttc};
				cct[ttc]++;
			}
		for (int j = i + 1; j <= i + B && j <= n; j++)
			if ((a[j] - a[i]) % (j - i) == 0) {
				int temp = (a[j] - a[i]) / (j - i);
				if (-350 <= temp && temp <= 350) continue;
				int ttc = temp + 100000;
				cct[ttc]--;
			}
	}
	sort (v + 1, v + ed + 1, cmp);
	for (int i = 1; i <= n; i++) fa[i] = i, s[i] = 1;
	int l = 1;
	for (int i = 1; i <= ed; i++)
		if (v[l].w != v[i].w) calc(l, i - 1), l = i;
	calc(l, n);
	//cerr << (double)(clock() - st) / CLOCKS_PER_SEC << endl;
	printf("%d\n", n - ans);
	return 0;
}