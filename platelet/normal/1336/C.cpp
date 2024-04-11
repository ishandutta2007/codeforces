#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 3005, P = 998244353;
int n, m; char s[N], t[N]; long long f[N][N], ans;
int main() {
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1), m = strlen(t + 1);
	rep(i, 1, n) f[i][i] = 2 * (i <= m ? s[1] == t[i] : 1);
	rep(c, 1, n - 1) rep(l, 1, n - c) {
		int r = l + c;
		if(l > m || s[r-l+1] == t[l]) (f[l][r] += f[l+1][r]) %= P;
		if(r > m || s[r-l+1] == t[r]) (f[l][r] += f[l][r-1]) %= P; 
	}
	rep(i, m, n) ans = (ans + f[1][i]) % P;
	cout << ans;
	return 0;
}