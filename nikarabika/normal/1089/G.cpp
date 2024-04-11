//sobskdrbhvk...
//remember... ):(
#include <bits/stdc++.h>

using namespace std;

#define smin(x, y) x = min(x, y)
#define PB push_back
#define sz(x) ((int)(x).size())

void solve() {
	int k;
	cin >> k;
	vector<int> can;
	for (int i = 0; i < 7; i++) {
		int x;
		cin >> x;
		if (x)
			can.PB(i);
	}
	int ans = 1e9;
	for (int i = 0; i < sz(can); i++) {
		int end = sz(can) - i;
		if (end >= k)
			smin(ans, can[i + k - 1] - can[i] + 1);
		else {
			int cur = 7 - can[i];
			int rem = k - end - 1;
			cur += rem / sz(can) * 7;
			rem %= sz(can);
			rem++;
			cur += can[rem - 1] + 1;
			smin(ans, cur);
		}
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}