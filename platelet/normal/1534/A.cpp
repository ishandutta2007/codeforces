#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 55;

char s[N][N];

int n, m;

void solve() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%s", s[i] + 1);
	int x = 0, y = 0;
	rep(i, 1, n) rep(j, 1, m) if(s[i][j] != '.') x = i, y = j;
	rep(i, 1, n) rep(j, 1, m) if((i ^ j ^ x ^ y) & 1) {
		if(s[i][j] != '.' && s[i][j] == s[x][y]) { puts("NO"); return; }
		s[i][j] = s[x][y] == 'R' ? 'W' : 'R';
	} else {
		if(s[i][j] != '.' && s[i][j] != s[x][y]) { puts("NO"); return; }
		s[i][j] = s[x][y];
	}
	puts("YES");
	rep(i, 1, n) puts(s[i] + 1);
}

int main() {
#ifdef local
	freopen(".in", "r", stdin);
#endif
	s[0][0] = 'R';
	int T; for(cin >> T; T--;)
	solve();
	return 0;
}