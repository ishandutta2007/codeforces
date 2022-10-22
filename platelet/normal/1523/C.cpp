#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 1005;

int T, n, fa[N], d[N], stk[N];

int main() {
#ifdef local
	// freopen(".in", "r", stdin);
#endif
	for(cin >> T; T--;) {
		mem(d, 0);
		scanf("%d", &n);
		int tp = 0, x;
		rep(i, 1, n) {
			scanf("%d", &x);
			int u = i - 1;
			while(d[u] + 1 != x) u = fa[u], tp--;
			fa[i] = u, stk[++tp] = ++d[u];
			For(j, 1, tp) printf("%d.", stk[j]);
			printf("%d\n", stk[tp]);
		}
	}
}