#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 55;
char s1[N], s2[N];
int n1, n2, n; vector <int> A[26], B[26]; 
int ok1[N][N][26], ok2[N][N][26], f[N][N];
void slv(int& n, char s[], int ok[N][N][26]) {
	rep(i, 1, n) ok[i][i][s[i]-97] = 1;
	rep(i, 2, n) rep(l, 1, n - i + 1) {
		int r = l + i - 1;
		rep(k, l, r - 1) rep(c, 0, 26) rep(j, 0, (int)A[c].size() - 1) 
			ok[l][r][c] |= ok[l][k][A[c][j]] & ok[k+1][r][B[c][j]]; 
	}
}
int main() {
	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif
	scanf("%s", s1 + 1), n1 = strlen(s1 + 1);
	scanf("%s", s2 + 1), n2 = strlen(s2 + 1);
	cin >> n; rep(i, 1, n) {
		char c, a, b; scanf("\n%c->%c%c", &c, &a, &b);
		A[c-97].push_back(a - 97), B[c-97].push_back(b - 97);
	}
	slv(n1, s1, ok1), slv(n2, s2, ok2);
	mem(f, 0x3f), f[0][0] = 0;
	rep(i, 1, n1) rep(j, 1, n2) rep(ii, 1, i) rep(jj, 1, j) rep(c, 0, 26)
	if(ok1[ii][i][c] & ok2[jj][j][c]) f[i][j] = min(f[i][j], f[ii-1][jj-1] + 1);
	return !(cout << (f[n1][n2] < 0x3f3f3f3f ? f[n1][n2] : -1));
}