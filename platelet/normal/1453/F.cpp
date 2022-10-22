#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
const int N = 3005;
int T, n, a[N], f[N][N];
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	for(cin >> T; T--;) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 2, n) {
			rep(j, i, n) f[i][j] = 1e9;
			int cnt =  0;
			per(j, i - 1, 1) if(j + a[j] >= i)
				f[i][j + a[j]] = min(f[i][j + a[j]], f[j][i - 1] + cnt++);
			rep(j, i + 1, n) f[i][j] = min(f[i][j], f[i][j - 1]);
		}
		printf("%d\n", f[n][n]);
	}
	return 0;
}