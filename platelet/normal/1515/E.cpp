#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define pb push_back

using namespace std;

typedef long long ll;
const int N = 405;

int n;
ll P, g[N], C[N][N], f[N][N], as;

int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> P;
	rep(i, 0, n) {
		C[i][0] = 1;
		rep(j, 1, i) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
	}
	g[1] = 1;
	rep(i, 2, n) g[i] = g[i - 1] * 2 % P;
	rep(i, 1, n) rep(j, 1, i) rep(k, 1, j) if(i - k != 1)
		(f[i][j] += (i - k ? f[i - k - 1][j - k] : 1ll) * g[k] % P * C[j][k]) %= P;
	rep(i, 1, n) (as += f[n][i]) %= P;
	cout << as;
	return 0;
}