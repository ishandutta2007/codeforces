#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 2e6, P = 1e9 + 7;
int t, n, f[N+5][2], g[N+5]; // g[i] = f[i][1] - f[i][0]
long long F(int i) { return f[i][g[i] > 0]; }
int main() {
	rep(i, 3, N) {
		f[i][0] = (F(i-1) + F(i-2) * 2) % P;
		f[i][1] = (f[i-1][0] + f[i-2][0] * 2LL + 1) % P;
		g[i] = -max(g[i-1], 0) - max(g[i-2], 0) * 2 + 1;
	}
	for(cin >> t; t--;) scanf("%d", &n), printf("%lld\n", 4LL * F(n) % P);
	return 0;
}