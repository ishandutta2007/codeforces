#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<char>> a(n+2, vector<char>(n+2));
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	
	vector<vector<int>> dp(n+2, vector<int>(n+2));
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == '#') continue;
			
			int tmp = 0;
			for (int k = j; k <= min(n, j+m); k++) {
				if (a[i][k] == '#') break;
				tmp++;
				if (tmp == m) break;
			}
			
			if (tmp == m) {
				for (int k = j; k < j+m; k++) {
					dp[i][k]++;
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == '#') continue;
			
			int tmp = 0;
			for (int k = i; k <= min(n, i+m); k++) {
				if (a[k][j] == '#') break;
				tmp++;
				if (tmp == m) break;
			}
			
			if (tmp == m) {
				for (int k = i; k < i+m; k++) {
					dp[k][j]++;
				}
			}
		}
	}
	
	int ans = 0, x = 1, y = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] > ans) {
				x = i;
				y = j;
				ans = dp[i][j];
			}
		}
	}
	
	cout << x << " " << y;
	
	return 0;
}