#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <cassert>
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector <int> a(n);
		int sum = 0;
		for (auto& x : a) 
			cin >> x, sum += x;
		if (sum % n) {
			cout << "-1\n";
			continue;
		}
		vector <vector <int>> ans;
		for (int i = 1; i < n; ++i) {
			if (a[i] % (i + 1)) {
				int x = a[i] % (i + 1);
				ans.push_back({ 1, i + 1, i + 1 - x });
				a[0] -= 1 * (i + 1 - x);
				a[i] += 1 * (i + 1 - x);
			}
			ans.push_back({ i + 1, 1, a[i] / (i + 1) });
			a[0] += (i + 1) * a[i] / (i + 1);
			a[i] -= (i + 1) * a[i] / (i + 1);
		}
		assert(a[0] == sum);
		for (int i = 1; i < n; ++i) {
			ans.push_back({ 1, i + 1, sum / n });
		}
		cout << ans.size() << '\n';
		for (auto x : ans) {
			for (auto y : x) cout << y << ' ';
			cout << '\n';
		}
	}

}