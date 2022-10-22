#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
#include <queue>

using namespace std;
const int mod = 1e9 + 7, root = 325;
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n; cin >> n;
		vector <int> ans(n);
		int id = n - 1;
		for (int i = 0; i < n - 1; i += 2) {
			cout << "? 2 " << i + 1 << ' ' << i + 2 << " 1" << endl;
			int x; cin >> x;
			if (x > 2) continue;
			if (x == 1) {
				id = i; break;
			}
			cout << "? 2 " << i + 2 << ' ' << i + 1 << " 1" << endl;
			cin >> x;
			if (x == 1) {
				id = i + 1;
				break;
			}
		}
		ans[id] = 1;
		for (int i = 0; i < n; ++i) {
			if (i == id) continue;
			cout << "? 1 " << id + 1 << ' ' << i + 1 << ' ' << n - 1 << endl;
			int x; cin >> x;
			ans[i] = x;
		}
		cout << "! ";
		for (auto x : ans) cout << x << ' ';
		cout << endl;
	}
	return 0;
}