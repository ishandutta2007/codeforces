#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n[3];
vector<int> a[3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i=0; i<3; ++i) {
		cin >> n[i];
		a[i].resize(n[i]);
	}
	for (int i=0; i<3; ++i) {
		for (int &j: a[i])
			cin >> j;
		sort(a[i].rbegin(), a[i].rend());
	}
	ll ans=0;
	vector<vector<vector<ll>>> dp(n[0]+1, vector<vector<ll>>(n[1]+1, vector<ll>(n[2]+1, 0)));
	for (int i=0; i<=n[0]; ++i) for (int j=0; j<=n[1]; ++j) for (int k=0; k<=n[2]; ++k) {
		if ((i+j+k)&1) continue;
		ans=max(ans, dp[i][j][k]);
		if (i<n[0]&&j<n[1])
			dp[i+1][j+1][k]=max(dp[i+1][j+1][k], dp[i][j][k]+a[0][i]*a[1][j]);
		if (i<n[0]&&k<n[2])
			dp[i+1][j][k+1]=max(dp[i+1][j][k+1], dp[i][j][k]+a[0][i]*a[2][k]);
		if (j<n[1]&&k<n[2])
			dp[i][j+1][k+1]=max(dp[i][j+1][k+1], dp[i][j][k]+a[1][j]*a[2][k]);
	}
	/*while(1) {
		sort(a, a+3, [](const vector<int> &x, const vector<int> &y) {return x.size()>y.size();});
		if (a[1].size()==0) break;
		bool b=0;
		if (a[0].size()>=a[1].size()+a[2].size()&&a[2].size()) {
			if (a[0].back()*a[1].back()+a[0][a[0].size()-2]*a[2].back()>a[1].back()*a[2].back()) {
				
			}
		}
		if (!b) {
			ar<int, 3> best={-1, -1, -1};
			for (int i=0; i<3; ++i) for (int j=i+1; j<3; ++j) {
				if (a[j].empty()) continue;
				if (a[i].back()*a[j].back()>best[0])
					best={a[i].back()*a[j].back(), i, j};
			}
			assert(best[0]!=-1);
			ans+=best[0];
			a[best[1]].pop_back();
			a[best[2]].pop_back();
		}
	}*/
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/