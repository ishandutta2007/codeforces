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

const int N = 4e5 + 10;

int T, n, in[N], ans[N];
vector <int> G[N];

int main() {
	for (read(T); T; T--) {
		read(n);
		for (int i = 1; i <= n; i++) in[i] = 0;
		for (int i = 1; i <= n; i++) G[i].clear();
		for (int i = 1; i <= n; i++) {
			int k; read(k);
			for (int j = 1, x; j <= k; j++)
				read(x), G[x].push_back(i), in[i]++;
		}
		for (int i = 1; i <= n; i++) ans[i] = -1;
		queue <int> q;
		for (int i = 1; i <= n; i++)
			if (in[i] == 0) ans[i] = 1, q.push(i);
		int cnt = 0;
		while (q.size()) {
			int u = q.front(); q.pop();
			cnt++;
			for (int v : G[u]) {
				if (u < v) ans[v] = max(ans[u], ans[v]);
				else ans[v] = max(ans[u] + 1, ans[v]);
				in[v]--;
				if (in[v] == 0) q.push(v);
			}
		}
		int flag = 1, out = 0;
		for (int i = 1; i <= n; i++) {
			if (ans[i] == -1) flag = 0;
			out = max(out, ans[i]);
		}
		if (cnt != n) puts("-1");
		else print(out, '\n');
	}
	return 0;
}