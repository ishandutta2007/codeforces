#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <iomanip>

using namespace std;

#define int long long
#define debug(x) cout << #x << " is " << x << '\n';
const int mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector <int> a(n), b(n);
		map <int, int> cnt1, cnt2;
		for (auto& x : a) cin >> x, cnt1[x]++;
		for (auto& x : b) cin >> x, cnt2[x]++;
		bool ok = true;
		while (!cnt1.empty()) {
			auto it = cnt1.begin();
			int x = it->first;
			int y = min(cnt1[x], cnt2[x]);
			cnt1[x] -= y, cnt2[x] -= y;
			if (cnt1[x] == 0) {
				if (cnt2[x]) {
					ok = false;
					break;
				}
				else {
					cnt1.erase(cnt1.begin());
				}
			}
			else {
				if (cnt2[x + 1] < cnt1[x]) {
					ok = false;
					break;
				}
				else {
					cnt2[x + 1] -= cnt1[x];
					cnt1.erase(cnt1.begin());
				}
			}
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
}