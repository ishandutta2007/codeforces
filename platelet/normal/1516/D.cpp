#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
const int N = 1e5 + 5;
int n, q, a[N], lst[N], mi[17][N], p[17][N];
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> q;
	rep(i, 1, n) scanf("%d", &a[i]), mi[0][i] = n + 1;
	rep(i, 1, 100000) lst[i] = n + 1;
	per(i, n, 1) {
		int t = a[i], &k = mi[0][i];
		for(int j = 2; j * j <= t; j++) if(t % j == 0) {
			k = min(k, lst[j]), lst[j] = i;
			while(t % j == 0) t /= j;
		}
		if(t > 1) k = min(k, lst[t]), lst[t] = i;
	}
	rep(i, 1, 16) rep(j, 1, n - (1 << i) + 1)
		mi[i][j] = min(mi[i - 1][j], mi[i - 1][j + (1 << (i - 1))]);
	rep(i, 1, n) {
		int nw = n + 1;
		int& k = p[0][i] = i;
		per(j, 16, 0) if(k + (1 << j) <= n + 1 && min(nw, mi[j][k]) >= k + (1 << j))
			nw = min(nw, mi[j][k]), k += 1 << j;
	}
	p[0][n + 1] = n + 1;
	rep(i, 1, 16) rep(j, 1, n + 1) p[i][j] = p[i - 1][p[i - 1][j]];
	int l, r;
	while(q--) {
		scanf("%d%d", &l, &r);
		int as = 0;
		per(i, 16, 0) if(p[i][l] <= r) as += 1 << i, l = p[i][l];
		printf("%d\n", as + 1);
	}
	return 0;
}