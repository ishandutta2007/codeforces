#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 1005;
int n, s[8], a[N], mi[N][8][N], f[256], ans;
int chk(int mid) {
	mem(f, 63), f[0] = 0;
	rep(S, 0, 255) rep(i, 0, 7) if(S >> i & 1)
	if(f[S^1<<i] <= n) f[S] = min(f[S], mi[f[S^1<<i]][i][mid+s[i]]);
	return f[255] <= n;
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	rep(i, 1, n) scanf("%d", &a[i]), a[i]--;
	rep(i, 0, 7) {
		mi[n][i][0] = n;
		rep(j, 1, max(n, 8)) mi[n][i][j] = n + 1;
	}
	per(i, n - 1, 0) rep(k, 0, max(n, 8)) {
		rep(j, 0, 7) mi[i][j][k] = k ? mi[i+1][j][k] : i;
		mi[i][a[i+1]][k] = k ? mi[i+1][a[i+1]][k-1] : i;
	}
	rep(S, 0, 511) {
		int su = 0;
		rep(i, 0, 7) su += s[i] = S >> i & 1;
		if(!chk(0)) continue;
		int l = 0, r = n, mid;
		while(l <= r) {
			mid = (l + r) >> 1;
			if(chk(mid)) l = mid + 1;
			else r = mid - 1;
		}
		ans = max(ans, r * 8 + su);
	}
	cout << ans;
	return 0;
}