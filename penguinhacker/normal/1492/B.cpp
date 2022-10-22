#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, p[100000], pos[100000];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		pos[i] = i;
		if (i && p[pos[i - 1]] > p[i]) pos[i] = pos[i - 1];
	}
	vector<int> ans;
	while(ans.size() < n) {
		int x = n - ans.size() - 1;
		int start = pos[x];
		for (int i = start; i <= x; ++i) ans.push_back(p[i]);
	}
	assert(ans.size() == n);
	for (int i : ans) cout << i << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}