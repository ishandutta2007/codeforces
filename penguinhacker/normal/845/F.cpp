#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int M=1e9+7;
int n, m, dp[2][1<<15][2][2]; // {last or new, profile, covered down?, uncovered cells}
string g[250], g2[250];

void add(int& a, int b) {
	a=(a+b)%M;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> g[i];
	if (n>m) {
		for (int i=0; i<m; ++i)
			g2[i].resize(n);
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				g2[j][i]=g[i][j];
		swap(n, m);
		for (int i=0; i<n; ++i)
			swap(g[i], g2[i]);
	}
	//for (int i=0; i<n; ++i)
	//	cout << g[i] << "\n";
	dp[0][0][0][0]=1;
	for (int j=0; j<m; ++j) {
		for (int i=0; i<n; ++i) {
			for (int mask=0; mask<1<<n; ++mask) {
				for (int down : {0, 1}) {
					for (int un : {0, 1}) {
						int x=dp[0][mask][down][un];
						if (!x)
							continue;
						if (g[i][j]=='x') {
							int nmask=mask;
							if (mask&1<<i)
								nmask^=1<<i;
							add(dp[1][nmask][0][un], x);
						} else {
							// dont cover
							int nun=un;
							if (!(mask&1<<i)&&(!down||i==0))
								++nun;
							if (nun<2)
								add(dp[1][mask][down&&i>0][nun], x);
							// cover (i, j)
							add(dp[1][mask|1<<i][1][un], x);
						}
					}
				}
			}
			memcpy(dp[0], dp[1], sizeof(dp[0]));
			memset(dp[1], 0, sizeof(dp[1]));
		}
	}
	int ans=0;
	for (int i=0; i<1<<n; ++i)
		for (int j : {0, 1})
			for (int k : {0, 1})
				add(ans, dp[0][i][j][k]);
	cout << ans;
	return 0;
}