#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 5007;
int n, a[N], dp[N][N], f[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n ;
	L(i, 1, n) cin >> a[i];
	memset(dp, 0x3f, sizeof(dp));
	memset(f, 0x3f, sizeof(f));
	dp[0][0] = f[0] = 0;
	L(i, 1, n) {
		L(j, 1, n) {
			if(i >= 3) dp[i][j] = dp[i - 2][j - 1] + max(a[i - 1] - min(a[i - 2], a[i]) + 1, 0) - max(a[i - 1] - a[i - 2] + 1, 0) + max(a[i + 1] - a[i] + 1, 0);
			dp[i][j] = min(dp[i][j], f[j - 1] + max(a[i - 1] - a[i] + 1, 0) + max(a[i + 1] - a[i] + 1, 0));
		}
		L(j, 1, n) 
			f[j] = min(f[j], dp[i - 1][j]);
	}
	// cout << dp[2][1] << '\n';
	L(j, 1, n) f[j] = min(f[j], dp[n][j]);
	L(j, 1, (n + 1) / 2) 
		cout << f[j] << ' ';
	cout << '\n';
	return 0;
}