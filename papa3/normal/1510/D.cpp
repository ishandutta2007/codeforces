#include <bits/stdc++.h>

using namespace std;

pair<long double, int> dp[100002][12];
long double eps = 0.000000001;
int tab[1000002];

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k, jed = 0;
	cin >> n >> k;
	
	for (int i=0; i<10; i++) {
		dp[0][i] = {-1000000000, -1};
	}
	dp[0][1] = {-1, 0};
	
	for (int i=1; i<=n; i++) {
		for (int j=0; j<10; j++) {
			dp[i][j] = {dp[i-1][j].first, j};
		}
	
		int a;
		cin >> a;
		tab[i] = a;
		if (a == 1) {
			jed++;
			continue;
		}
		long double lg = log(a);
		
		for (int j=0; j<10; j++) {
			int r = j * a % 10;
			//cout << i << " " << r << " " << j << "\n";
			dp[i][r] = max({dp[i-1][j].first + lg, j}, dp[i][r]);
		}
		
	}
	
	if ((dp[n][k].first < eps && jed == 0) || dp[n][k].first < -2) {
		cout << -1;
		return 0;
	}
	//cout << dp[n][k].first << " " << dp[n][k].second << "\n";
	
	vector<int> res;
	int akt = n, cyf = k;
	while (akt > 0) {
		//cout << akt << " " << cyf << " " << dp[akt][cyf].first << "\n";
		if (dp[akt][cyf].first > dp[akt-1][dp[akt][cyf].second].first + eps) {
			res.push_back(tab[akt]);
		}
		cyf = dp[akt][cyf].second;
		akt = akt - 1;
	}
	
	for (int i=0; i<jed; i++) {
		res.push_back(1);
	}
	
	cout << res.size() << "\n";
	for (auto el : res) {
		cout << el << " ";
	}
}