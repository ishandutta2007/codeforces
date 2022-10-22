#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
int a[300000], mx[300000], ans[300001];
vector<int> oc[300000];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		oc[i] = {-1};
		mx[i] = -1;
		ans[i] = -1;
	}
	for (int i = 0; i < n; ++i) {
		cin >> a[i], --a[i];
		oc[a[i]].push_back(i);
	}
	int last = n + 1;
	for (int i = 0; i < n; ++i) {
		oc[i].push_back(n);
		for (int j = 1; j < oc[i].size(); ++j) {
			mx[i] = max(mx[i], oc[i][j] - oc[i][j - 1]);
		}
		for (int j = mx[i]; j < last; ++j) {
			ans[j] = i + 1;
		}
		last = min(last, mx[i]);
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}