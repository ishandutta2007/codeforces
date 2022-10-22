#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const ll INF=1e18;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int& i : a)
			cin >> i;
		vector<vector<ll>> dp(n, vector<ll>(31, -INF));
		dp[0][0]=-k;
		dp[0][1]=0;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<=30; ++j) {
				dp[i][j]+=a[i]/(1<<j);
				if (i+1<n) {
					dp[i+1][j]=max(dp[i+1][j], dp[i][j]-(j<30?k:0));
					if (j+1<=30)
						dp[i+1][j+1]=max(dp[i+1][j+1], dp[i][j]);
				}
			}
		}
		cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << "\n";
	}
	return 0;
}