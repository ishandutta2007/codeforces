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

const int N = 1000010;

int n, m, rk[N];
char s[N], ans[N];

struct Node {
	int x, y, w;
};

int cmp(Node a, Node b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

vector <Node> v;


int main() {
	scanf("%d", &n), m = 1 << n;
	scanf("%s", s);
	for (int i = 0; i < m; i++) rk[i] = s[i] - 'a' + 1;
	for (int i = 1; i < m; i <<= 1) {
		for (int j = 0; j < m; j += (i << 1)) {
			for (int k = 0; k < i; k++) {
				v.pb((Node){rk[j + k], rk[i + j + k], j + k});
				v.pb((Node){rk[i + j + k], rk[j + k], i + j + k});
			}
		}
		sort (v.begin(), v.end(), cmp); int cnt = 1;
		for (int j = 0; j < m; j++) {
			if (j > 0 && (v[j].x != v[j - 1].x || v[j].y != v[j - 1].y)) cnt++;
			rk[v[j].w] = cnt;
		}
		v.clear();
	}
	int j = 0;
	for (int i = 0; i < m; i++) if (rk[i] == 1) j = i;
	for (int i = 0; i < m; i++) ans[i ^ j] = s[i];
	printf("%s\n", ans);
	return 0;
}