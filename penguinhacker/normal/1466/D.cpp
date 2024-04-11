#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 100000;
int n, w[mxN];
vector<int> adj[mxN];
void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
		adj[i].clear();
	}
	for (int i = 1; i < n; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> v;
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < adj[i].size(); ++j) {
			v.push_back(w[i]);
		}
	}
	assert(v.size() == n - 2);
	sort(v.begin(), v.end());

	ll ans = accumulate(w, w + n, 0ll);
	cout << ans << " ";
	for (int i = 2; i < n; ++i) {
		ans += v.back();
		v.pop_back();
		cout << ans << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}