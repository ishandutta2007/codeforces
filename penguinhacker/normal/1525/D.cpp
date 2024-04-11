#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, dp[5000][5000];
vector<int> a, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		int x;
		cin >> x;
		if (x==1)
			a.push_back(i);
		else
			b.push_back(i);
	}
	if (a.empty()) {
		cout << 0;
		return 0;
	}
	memset(dp, 0x3f, sizeof(dp));
	for (int i=0; i<b.size(); ++i) {
		dp[0][i]=abs(a[0]-b[i]);
		if (i)
			dp[0][i]=min(dp[0][i], dp[0][i-1]);
	}
	for (int i=1; i<a.size(); ++i) {
		for (int j=i; j<b.size(); ++j) {
			dp[i][j]=min(dp[i][j-1], dp[i-1][j-1]+abs(a[i]-b[j]));
		}
	}
	cout << dp[a.size()-1][b.size()-1];
	return 0;
}