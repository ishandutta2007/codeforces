#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##e = (r); i <= i##e; i++)
#define per(i, r, l) for(int i = (r), i##e = (l); i >= i##e; i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define m c[o]
#define int ll

using namespace std;
using ll = long long;
const int N = 3e5 + 5;

int q, a[N], c[N], fa[19][N];

signed main() {
	cin >> q >> a[1] >> c[1];
	int t, p, b;
	rep(i, 2, q + 1) {
		scanf("%d%d", &t, &p), p++;
		if(t == 1) {
			fa[0][i] = p;
			rep(j, 1, 18) fa[j][i] = fa[j - 1][fa[j - 1][i]];
			scanf("%d%d", &a[i], &c[i]);
		} else {
			scanf("%d", &b);
			int v = 0; ll w = 0;
			while(b && a[p]) {
				int u = p;
				per(j, 18, 0) if(a[fa[j][u]]) u = fa[j][u];
				int t = min(a[u], b);
				b -= t, v += t, w += 1ll * t * c[u], a[u] -= t;
			}
			printf("%d %lld\n", v, w);
		}
		fflush(stdout);
	}
	return 0;
}