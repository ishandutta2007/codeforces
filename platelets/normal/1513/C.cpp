#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
const int N = 2e5 + 5, P = 1e9 + 7;

int T, n, m, f[N][10];

int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	rep(i, 0, 9) f[0][i] = 1;
	rep(i, 1, 200000) {
		rep(j, 0, 8) f[i][j] = f[i - 1][j + 1];
		f[i][9] = (f[i - 1][1] + f[i - 1][0]) % P;
	}
	for(cin >> T; T--;) {
		scanf("%d%d", &n, &m);
		int as = 0;
		while(n) (as += f[m][n % 10]) %= P, n /= 10;
		printf("%d\n", as);
	}
	return 0;
}