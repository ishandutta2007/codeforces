#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int n, a[mxN], b[mxN];
ll dp[mxN][3];

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i] >> b[i];
	for (int i=0; i<3; ++i)
		dp[0][i]=i*b[0];
	for (int i=1; i<n; ++i) {
		for (int j=0; j<3; ++j) {
			dp[i][j]=1e18;
			for (int k=0; k<3; ++k)
				if (a[i-1]+k^a[i]+j)
					dp[i][j]=min(dp[i][j], dp[i-1][k]+j*b[i]);
		}
	}
	cout << *min_element(dp[n-1], dp[n-1]+3) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}