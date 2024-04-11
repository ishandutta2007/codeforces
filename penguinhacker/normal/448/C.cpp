#include <bits/stdc++.h>
using namespace std;

int n;

int solve(vector<int> &c) {
	if (c.empty())
		return 0;
	int mn = 2e9;
	for (int i:c)
		mn = min(mn, i);
	int ans = mn;

	vector<int> curr;
	for (int i:c) {
		if (i==mn) {
			ans += solve(curr);
			curr.clear();
		}
		else
			curr.push_back(i-mn);
	}
	ans += solve(curr);
	return min((int)c.size(), ans);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<int> v(n);
	for (int i=0; i<n; ++i)
		cin >> v[i];
	cout << solve(v);
	return 0;
}