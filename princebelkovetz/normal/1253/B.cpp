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
	int n, cou = 0, num = 0;
	cin >> n;
	vector <int> a(n), ans; map <int, bool> b;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	if (n % 2 == 1) {
		cout << "-1";
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] > 0 and (b.find(a[i]) == b.end())) {
			b[a[i]] = true; ++cou; ++num;
		}
		else if (a[i] < 0 and b[-a[i]]) {
			b[-a[i]] = false; cou--;
			num++;
			if (!cou) {
				ans.push_back(num); num = 0;
				b.erase(b.begin(), b.end());
			}
		}
		else {
			cout << -1; return;
		}
		//cout << i;
	}
	if (b.size()) { cout << "-1"; return; }
	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << i << " ";
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