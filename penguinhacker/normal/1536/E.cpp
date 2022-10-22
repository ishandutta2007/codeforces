#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int M=1e9+7;
int n, m;
string g[2000];

void solve() {
	cin >> n >> m;
	int cnt=0, ans=1;
	for (int i=0; i<n; ++i) {
		cin >> g[i];
		for (int j=0; j<m; ++j) {
			if (g[i][j]=='#') {
				ans=ans*2%M;
				++cnt;
			}
		}
	}
	cout << ans-(n*m==cnt) << "\n";
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