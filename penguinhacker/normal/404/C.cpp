#include <bits/stdc++.h>
using namespace std;

#define ar array

const int mxN=1e5;
int n, k, deg[mxN];
vector<int> v[mxN];
vector<ar<int, 2>> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		int d;
		cin >> d;
		v[d].push_back(i);
	}
	if (v[0].size()!=1) {
		cout << -1;
		return 0;
	}
	for (int d=1; d<n; ++d) {
		if (v[d].empty())
			continue;
		if (v[d-1].empty()) {
			cout << -1;
			return 0;
		}
		for (int i=0; i<v[d].size(); ++i) {
			int p=v[d-1][i%v[d-1].size()];
			++deg[p], ++deg[v[d][i]];
			ans.push_back({p, v[d][i]});
		}
	}
	for (int i=0; i<n; ++i)
		if (deg[i]>k) {
			cout << -1;
			return 0;
		}
	cout << ans.size() << "\n";
	for (ar<int, 2> a : ans)
		cout << a[0]+1 << " " << a[1]+1 << "\n";
	return 0;
}