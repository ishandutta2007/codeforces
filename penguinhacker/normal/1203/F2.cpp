#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, cur, ans, dp[101][60001];
vector<ar<int, 2>> pos, neg;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> cur;
	for (int i=0; i<n; ++i) {
		int a, b;
		cin >> a >> b;
		if (b>=0)
			pos.push_back({a, b});
		else
			neg.push_back({max(a, -b), -b});
	}
	sort(pos.begin(), pos.end());
	for (ar<int, 2> a : pos)
		if (cur>=a[0])
			cur+=a[1], ++ans;
	//cout << ans << "\n";
	sort(neg.begin(), neg.end(), [&](ar<int, 2> x, ar<int, 2> y) {
			return x[1]-x[0]<y[1]-y[0];
		});
	fill(dp[0], dp[0]+60001, -6969);
	dp[0][cur]=ans;
	for (int i=1; i<=neg.size(); ++i) {
		memcpy(dp[i], dp[i-1], sizeof(dp[i]));
		int a=neg[i-1][0], b=neg[i-1][1];
		for (int j=a; j<=60000; ++j)
			dp[i][j-b]=max(dp[i][j-b], dp[i-1][j]+1);
	}
	cout << *max_element(dp[neg.size()], dp[neg.size()]+60001);
	return 0;
}