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

const int N = 5e5 + 10;

int n, m, p[N], per[N], c[N];
vector <int> G[N];

int cmp(int x, int y) {
	return p[x] < p[y];
}

int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		int a, b; read(a), read(b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		read(p[i]), per[i] = i;
	sort (per + 1, per + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		int x = per[i];
		vector <int> tmp;
		for (int v : G[x]) if (c[v]) tmp.push_back(c[v]);
		sort (tmp.begin(), tmp.end());
		int cnt = 1;
		for (int v : tmp) if (v == cnt) cnt++;
		if (cnt != p[x]) return puts("-1") * 0;
		c[x] = cnt;
	}
	for (int i = 1; i <= n; i++) print(per[i], " \n"[i == n]);
	return 0;
}