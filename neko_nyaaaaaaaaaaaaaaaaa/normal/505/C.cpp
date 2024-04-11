#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// offset = 250
int n, d;
int a[30001];
vector<vector<int>> dp(30001, vector<int>(600, -1));

int solve(int i, int j) {
	int k = j - (d - 250);
	if (i > 30000) return 0;
	
	if (dp[i][k] != -1) return dp[i][k];
	
	int ans;
	if (j == 1) {
		ans = a[i] + max(solve(i+j, j), solve(i+j+1, j+1));
	} else {
		ans = a[i] + max(solve(i+j-1, j-1), max(solve(i+j, j), solve(i+j+1, j+1)));
	}
	dp[i][k] = ans;
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> d;
	while (n--) {
		int x; cin >> x;
		a[x]++;
	}
	
	cout << solve(d, d);
	
	return 0;
}