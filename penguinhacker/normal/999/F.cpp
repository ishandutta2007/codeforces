#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, ans=0, h[11];
int cntCard[100001], cntPlay[100001];

void solve(int n, int m) {
	m=min(m, n*k);
	//cout << n << ' ' << m << '\n';
	vector<vector<int>> dp(n, vector<int>(m+1, -1e9));
	int res=0;
	for (int i=0; i<=min(k, m); ++i)
		dp[0][i]=h[i], res=max(res, h[i]);
	for (int i=1; i<n; ++i) for (int j=0; j<=m; ++j) {
		for (int dif=0; dif<=k&&j-dif>=0; ++dif)
			dp[i][j]=max(dp[i][j], dp[i-1][j-dif]+h[dif]);
		res=max(res, dp[i][j]);
	}
	ans+=res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<n*k; ++i) {
		int a; cin >> a;
		++cntCard[a];
	}
	for (int i=0; i<n; ++i) {
		int a; cin >> a;
		++cntPlay[a];
	}
	for (int i=1; i<=k; ++i)
		cin >> h[i];
	for (int i=1; i<=100000; ++i) {
		if (cntPlay[i]==0||cntCard[i]==0) continue;
		//dp[person][cards used up to and including person]
		solve(cntPlay[i], cntCard[i]);
	}
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/