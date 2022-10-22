#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <cassert>
#include <map>
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const ld eps = 1e-7;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt--) {
		int n, k; cin >> n >> k;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		set <int> b;
		for (auto x : a) b.insert(x);
		if (k == 1 and b.size() > 1) cout << -1;
		else {
			if (b.size() > k) cout << (b.size() - 2) / (k - 1) + 1;
			else cout << 1;
		}
		cout << '\n';
	}
}