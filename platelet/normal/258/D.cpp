#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 1005;
int n, m, p[N], x[N], y[N];
double f[N][N];
struct node { int a, b; double c; };
vector <node> mod;
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m;
	rep(i, 1, n) scanf("%d", &p[i]);
	rep(i, 1, m) scanf("%d%d", &x[i], &y[i]);
	rep(i, 1, n) rep(j, 1, n) f[i][j] = i < j;
	per(i, m, 1) {
		mod.clear();
		rep(j, 1, n) {
			#define add(a, b, c) mod.push_back({a, b, c})
			add(x[i], j, (f[x[i]][j] + f[y[i]][j ^ y[i] ? j : x[i]]) / 2);
			add(j, x[i], (f[j][x[i]] + f[j ^ y[i] ? j : x[i]][y[i]]) / 2);
			add(y[i], j, (f[y[i]][j] + f[x[i]][j ^ x[i] ? j : y[i]]) / 2);
			add(j, y[i], (f[j][y[i]] + f[j ^ x[i] ? j : y[i]][x[i]]) / 2);
		}
		for(auto [a, b, c] : mod) f[a][b] = c;
	}
	double ans = 0;
	rep(i, 1, n) rep(j, 1, i - 1) ans += p[i] > p[j] ? f[i][j] : f[j][i];
	printf("%.9lf", ans);
	return 0;
}