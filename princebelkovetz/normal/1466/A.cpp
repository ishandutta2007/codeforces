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
		set <int> all;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				all.insert(a[j] - a[i]);
			}
		}
		cout << all.size() << '\n';
	}
}