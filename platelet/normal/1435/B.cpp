#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 505;
int T, n, m, t, x[N*N], y[N*N], a[N][N]; 
int main() {
	for(cin >> T; T--;) {
		scanf("%d%d", &n, &m);
		rep(i, 1, n) rep(j, 1, m) scanf("%d", &t), y[t] = j;
		rep(i, 1, m) rep(j, 1, n) scanf("%d", &t), x[t] = j;
		rep(i, 1, n * m) a[x[i]][y[i]] = i;
		rep(i, 1, n) {
			rep(j, 1, m) printf("%d ", a[i][j]);
			puts("");
		}
	}
	return 0;
}