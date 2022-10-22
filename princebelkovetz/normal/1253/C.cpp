#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define endl "\n";
#define int long long
using namespace std;

void solve() {
	int n, m, d = 0;
	cin >> n >> m;
	vector <int> a(n), ans(n + 1); ans[0] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; ++i) {
		d += a[i];
		ans[i + 1] = d + ans[max(0LL, i + 1 - m)];
		cout << ans[i + 1] << " ";
	}

}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t;
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}