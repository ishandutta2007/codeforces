#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 1e6 + 7, inf = 1e9;
int n, dp[N][2], w[N][2], lst[N][2], a[N], ns[N];
void Main () {
	cin >> n;
	L(i, 1, n) cin >> a[i], w[i][0] = a[i], w[i][1] = -a[i];
	L(i, 0, n) dp[i][0] = dp[i][1] = inf;
	w[0][0] = w[0][1] = -inf;
	dp[0][0] = dp[0][1] = -inf;
	L(i, 1, n) {
		L(a, 0, 1) L(b, 0, 1) if(w[i][a] > w[i - 1][b] && dp[i][a] > dp[i - 1][b]) 
				dp[i][a] = dp[i - 1][b], lst[i][a] = b;
		L(a, 0, 1) L(b, 0, 1) if(w[i][a] > dp[i - 1][b] && dp[i][a] > w[i - 1][b]) 
				dp[i][a] = w[i - 1][b], lst[i][a] = b;
//		cout << dp[i][0] << ' ' << dp[i][1] << '\n';
	}
	if(dp[n][0] == inf && dp[n][1] == inf) 
		cout << "NO\n";
	else {
		cout << "YES\n";
		int o = dp[n][0] == inf ? 1 : 0;
		R(i, n, 1) ns[i] = w[i][o], o = lst[i][o];
		L(i, 1, n) cout << ns[i] << ' ';
		cout << '\n';
	}
}
int main() {
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	int t;
	cin >> t;
	while (t--) Main ();
	return 0;
}