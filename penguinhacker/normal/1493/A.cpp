#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k;

void solve() {
	cin >> n >> k;
	vector<int> ans;
	for (int i = k + 1; i <= n; ++i)
		ans.push_back(i);
	for (int i = (k + 1) / 2; i < k; ++i)
		ans.push_back(i);
	cout << ans.size() << "\n";
	for (int i : ans)
		cout << i << " ";
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