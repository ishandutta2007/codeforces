#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))

using namespace std;



int main() {
#ifdef HOME
	ifstream cin("A.in");
	ofstream cout("A.out");
#endif
	int i, n;
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	vector <int> a(n + 1);
	for(i = 1; i <= n; i++) {
		cin >> a[i];
	}

	vector <vector <int>> dp(n + 1, vector <int>(n + 1));
	vector <vector <int>> val(n + 1, vector <int>(n + 1, -1));
	
	for(i = 1; i <= n; i++) {
		dp[i][i] = 1, val[i][i] = a[i];
	}
	for(int len = 1; len < n; len++) {
		for(int l = 1; l + len <= n; l++) {
			int r = l + len;
			dp[l][r] = n + 1;
			for(int k = l; k < r; k++) {
				int x = val[l][k], y = val[k + 1][r];
				if(min(x, y) > -1) {
					if(x == y) {
						val[l][r] = x + 1;
						dp[l][r] = 1;
					}	
				}
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
			}
		}
	}
	cout << dp[1][n];
	
	return 0;
}