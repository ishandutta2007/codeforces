#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const int mxN=200000;

vector<int> x, y, z, dp[3];
int n, k, t[mxN], a[mxN], b[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> t[i] >> a[i] >> b[i];
		if (a[i]&&!b[i])
			x.push_back(t[i]);
		if (!a[i]&&b[i])
			y.push_back(t[i]);
		if (a[i]&&b[i])
			z.push_back(t[i]);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());
	int ans=2e9+10;
	dp[0].push_back(0), dp[1].push_back(0), dp[2].push_back(0);
	for (int i : x)
		dp[0].push_back(dp[0].back()+i);
	for (int i : y)
		dp[1].push_back(dp[1].back()+i);
	for (int i : z)
		dp[2].push_back(dp[2].back()+i);
	for (int i=min(k, (int)dp[2].size()-1); i>=0; --i) {
		int c=dp[2][i];
		int j=k-i;
		if (j>dp[0].size()-1||j>dp[1].size()-1) break;
		c+=dp[0][j]+dp[1][j];
		ans=min(ans, c);
	}
	cout << (ans==2e9+10?-1:ans);
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/