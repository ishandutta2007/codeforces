#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#define endl "\n";
//define int long long
using namespace std;

void solve() {
	int n, k, d, cursum = 0, ans, f = 1;
	cin >> n >> k >> d;
	vector <int> a(n);
	unordered_map <int, int> ok;
	for (auto& x : a) {
		cin >> x;
		ok[x] = 0;
	}
	for (int i = 0; i < d; ++i) {
		if (!ok[a[i]]) cursum++;
		ok[a[i]]++;
	}
	ans = cursum;
	for (int i = d; i < n; ++i) {
		if (a[i] == a[i - d])continue;
		if (ok[a[i - d]] == 1) cursum--;
		if (!ok[a[i]])cursum++;
		ok[a[i]]++;
		ok[a[i - d]]--;
		ans = min(ans, cursum);
	}
	cout << ans << endl;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}