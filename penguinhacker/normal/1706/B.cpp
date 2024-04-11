#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<vector<int>> oc(n);
		for (int i=0; i<n; ++i) {
			int c;
			cin >> c, --c;
			oc[c].push_back(i%2);
		}
		for (int i=0; i<n; ++i) {
			int dp[2]={};
			for (int j : oc[i])
				dp[j]=dp[j^1]+1;
			cout << max(dp[0], dp[1]) << " ";
		}
		cout << "\n";
	}
	return 0;
}