#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, M=1e9+7;
int n, m;
ar<int, 3> a[mxN];

void solve() {
	cin >> n >> m;
	ll x=0;
	for (int i=0; i<m; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2], --a[i][0], --a[i][1];
		x|=a[i][2];
	}
	x%=M;
	for (int i=1; i<n; ++i)
		x=2*x%M;
	cout << x << "\n";
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