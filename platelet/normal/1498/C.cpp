#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
typedef long long ll;
const ll P = 1e9 + 7;
const int N = 1005;
int T, n, K; ll f[N][N];

int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		scanf("%d%d", &n, &K);
		rep(i, 0, n) f[1][i] = 1;
		rep(i, 2, K) {
			f[i][0] = 1;
			rep(j, 1, n) f[i][j] = (f[i][j - 1] + f[i - 1][n - j]) % P;
		}
		printf("%lld\n", f[K][n]);
	}
	return 0;
}