#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define vL1(x) ((x) - L1[x] + 1)
#define vR1(x) (R1[x] - (x) + 1)
#define vL2(x) ((x) - L2[x] + 1)
#define vR2(x) (R2[x] - (x) + 1)

using namespace std;
const int N = 505;
char s[N][N];
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	int T, n, m;
	for(cin >> T; T--;) {
		cin >> n >> m;
		rep(i, 1, n) scanf("%s", s[i] + 1);
		rep(i, 1, n) if(i % 3 == 1) {
			rep(j, 1, m) s[i][j] = 'X';
			if(i > 1) {
				int f = 0;
				rep(j, 1, m) {
					if(s[i - 1][j] == 'X') { s[i - 2][j] = 'X'; f = 1; break; }
					if(s[i - 2][j] == 'X') { s[i - 1][j] = 'X'; f = 1; break; }
				}
				if(!f) s[i - 2][1] = s[i - 1][1] = 'X';
			}
		}
		if(n % 3 == 0) rep(i, 1, m) if(s[n][i] == 'X') s[n - 1][i] = 'X';
		rep(i, 1, n) puts(s[i] + 1);
	}
	return 0;
}