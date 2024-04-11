#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=250;
int n, c[2*mxN][2*mxN];
ll pr[2*mxN+1][2*mxN+1], pc[2*mxN+1][2*mxN+1];
bool vis[2*mxN][2*mxN];

void solve() {
	cin >> n;
	ll ans=0, mn=1e18;
	for (int i=0; i<2*n; ++i)
		for (int j=0; j<2*n; ++j) {
			cin >> c[i][j];
			if (i>=n&&j>=n) {
				ans+=c[i][j];
				c[i][j]=0;
			} else if (i>=n||j>=n)
				if ((i==0||i==n-1||i==n||i==2*n-1)&&(j==0||j==n-1||j==n||j==2*n-1))
					mn=min(mn, (ll)c[i][j]);
		}
	cout << ans+mn << "\n";
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