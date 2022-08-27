#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int >
#define sz(a) ((int) a.size())
#define double long double 
using namespace std;
const int N = 3003, mod = 1e9 + 7;
int n, a[N], dp[N][N], f[N][N];
vi s[N];
void Main () {
	cin >> n;
	L(i, 1, n) s[i].clear ();
	L(i, 1, n) cin >> a[i], s[a[i]].push_back(i);
	L(i, 1, n) L(j, i, n) dp[i][j] = f[i][j] = 1e9;
	L(i, 1, n) for(int j = i; j <= n && a[j] == a[i]; j += 1) dp[i][j] = f[i][j] = 0;
	L(len, 2, n) L(l, 1, n - len + 1) {
		int r = l + len - 1;
		dp[l][r] = dp[l][r - 1] + (a[r] != a[r - 1]);
		for(const int &t : s[a[r]]) if(l <= t && t < r) 
			f[l][r] = min(f[l][r], f[l][t] + f[t + 1][r]);
		dp[l][r] = min(dp[l][r], f[l][r]);
		f[l][r] = min(f[l][r], dp[l][r - 1] + (a[r] != a[r - 1]));
	}
	cout << dp[1][n] << "\n"; 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie (0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}