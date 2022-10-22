#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1000;
int n;
double p[mxN][mxN], dp[mxN], ev[mxN], rem[mxN];
bool vis[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j) {
			int x;
			cin >> x;
			p[i][j]=x/100.0;
		}
	fill(dp, dp+n-1, 1e9);
	fill(rem, rem+n-1, 1);
	for (int rep=0; rep<n; ++rep) {
		int mn=-1;
		for (int i=0; i<n; ++i)
			if (!vis[i]&&(mn==-1||dp[i]<dp[mn]))
				mn=i;
		vis[mn]=1;
		for (int i=0; i<n; ++i)
			if (!vis[i]&&p[i][mn]) {
				ev[i]+=rem[i]*p[i][mn]*dp[mn];
				rem[i]*=1-p[i][mn];
				//cout << i << " " << ev[i] << " " << rem[i] << endl;
				dp[i]=min(dp[i], (ev[i]+1)/(1-rem[i]));
			}
	}
	cout << fixed << setprecision(6) << dp[0];
	return 0;
}