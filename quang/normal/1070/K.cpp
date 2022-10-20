#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[100010];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		tot += a[i];
	}
	if (tot % k) {
		cout << "No\n";
		return 0;
	}
	tot /= k;
	vector<int> res;
	int cur = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cur += a[i];
		cnt++;
		// cout << cur << " " << cnt << endl;
		if (cur > tot) {
			cout << "No\n";
			return 0;
		}
		if (cur == tot) {
			res.push_back(cnt);
			cnt = cur = 0;
		}
	}
	if (cur) {
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
	for (int u : res) cout << u << ' ';
		cout << endl;
	return 0;	
}