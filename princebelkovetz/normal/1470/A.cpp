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
#define int long long
#define debug(x) cout << #x << " is " << x << '\n';

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int testcases; cin >> testcases;
	while (testcases --> 0) {
		int n, m; cin >> n >> m;
		vector <int> a(n), b(m), cnt(m);
		for (auto& x : a) {
			cin >> x;
			cnt[x - 1]++;
		}
		for (auto& x : b) cin >> x;
		int ans = 0;
		vector <int> buy, pay;
		for (int i = 0; i < m; ++i) {
			pay.push_back(b[i]);
			for (int j = 0; j < cnt[i]; ++j)
				buy.push_back(b[i]);
			if (pay.size() + buy.size() >= n) {
				int cur = 0;
				int s1 = 0, s2 = 0;
				while (cur != n) {
					if (s1 == pay.size() or (s2 != buy.size() and pay[s1] > buy[s2])) {
						ans += buy[s2++];
					}
					else ans += pay[s1++];
					cur++;
				}
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}