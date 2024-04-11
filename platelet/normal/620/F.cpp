#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 5e4 + 5, M = 5e3 + 5, P = 1e9 + 7;
typedef long long ll;
int n, q, f[(1<<20)+5], a[N], l[N], r[N], ma[N], ans[N];
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	rep(i, 1, 1 << 20) f[i] = f[i-1] ^ i;
	cin >> n >> q;
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, q) scanf("%d%d", &l[i], &r[i]);
	rep(i, 1, n) {
		ma[i-1] = 0;
		rep(j, i, n) ma[j] = max(ma[j-1], f[a[i]] ^ f[a[j]] ^ min(a[i], a[j]));
		rep(j, 1, q) if(l[j] <= i) ans[j] = max(ans[j], ma[r[j]]);
	}
	rep(i, 1, q) printf("%d\n", ans[i]);
	return 0;
}