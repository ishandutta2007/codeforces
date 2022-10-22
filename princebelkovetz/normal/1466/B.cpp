#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cassert>
#include <map>
#include <set>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int testcases; cin >> testcases;
	while (testcases --> 0) {
		int n; cin >> n;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		map <int, int> cnt, v2;
		for (auto x : a)
			cnt[x]++;
		for (auto &x : cnt) {
			if (x.second > 1) {
				v2[x.first + 1] += x.second - 1;
				x.second = 1;
			}
			else if (x.second == 1 and v2.find(x.first) != v2.end() and v2[x.first] > 0) {
				x.second = 0;
				v2[x.first + 1]++;
			}
		}
		set <int> b;
		for (auto x : v2) b.insert(x.first);
		for (auto x : cnt) b.insert(x.first);
		cout << b.size() << '\n';
	}
}