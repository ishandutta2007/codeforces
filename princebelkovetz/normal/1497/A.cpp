#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cassert>

using namespace std;
#define int long long 
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
const int mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(3);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		sort(a.begin(), a.end());
		vector <int> b;
		for (int i = 0; i < n; ++i) {
			if (i > 0 and a[i] == a[i - 1]) b.push_back(a[i]);
			else cout << a[i] << ' ';
		}
		for (auto x : b) cout << x << ' ';
		cout << '\n';
	}
}