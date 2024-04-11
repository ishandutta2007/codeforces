#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[200000], b[200000];
vector<ll> v[200000];
ll ans[200001];

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		v[i].clear(), ans[i+1]=0;
	for (int i=0; i<n; ++i)
		cin >> a[i], --a[i];
	for (int i=0; i<n; ++i)
		cin >> b[i];
	for (int i=0; i<n; ++i)
		v[a[i]].push_back(b[i]);
	for (int i=0; i<n; ++i) {
		sort(v[i].rbegin(), v[i].rend());
		for (int j=1; j<v[i].size(); ++j)
			v[i][j]+=v[i][j-1];
		for (int j=0; j<v[i].size(); ++j) {
			int k=v[i].size()/(j+1)*(j+1);
			ans[j+1]+=v[i][k-1];
		}
	}
	for (int i=1; i<=n; ++i)
		cout << ans[i] << " ";
	cout << "\n";
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