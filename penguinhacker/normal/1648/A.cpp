#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, m;
vector<int> x[mxN], y[mxN];
ll ans;

void solve(vector<int> v) {
	sort(v.begin(), v.end());
	for (int i=0; i<v.size(); ++i)
		ans+=(ll)(i-((int)v.size()-i-1))*v[i];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j) {
			int c;
			cin >> c, --c;
			x[c].push_back(i);
			y[c].push_back(j);
		}
	for (int i=0; i<mxN; ++i) {
		solve(x[i]);
		solve(y[i]);
	}
	cout << ans;
	return 0;
}