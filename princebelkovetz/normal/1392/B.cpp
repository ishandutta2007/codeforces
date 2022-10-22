#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(4);
	int tt; cin >> tt;
	while (tt--) {
		int n, k; cin >> n >> k;
		vector <int> a(n);
		int mx = -1e9;
		for (auto& x : a) {
			cin >> x;
			mx = max(x, mx);
		}
		int mx2 = -1e9;
		for (auto& x : a) {
			x = mx - x;
			mx2 = max(mx2, x);
		}
		if (k & 1) {
			for (auto x : a) cout << x << ' ';
		}
		else {
			for (auto& x : a) {
				x = mx2 - x;
				cout << x << ' ';
			}
		}
		cout << '\n';
	}
}