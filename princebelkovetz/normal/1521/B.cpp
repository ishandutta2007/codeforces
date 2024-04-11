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
int gcd(int a, int b) {
	return (b ? gcd(b, a % b) : a);
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n; cin >> n;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		int id = 0;
		for (int i = 1; i < n; ++i)
			if (a[i] < a[id]) id = i;
		vector <vector <int>> ans;
		for (int i = 0; i < n; ++i) {
			if (i == id) continue;
			if ((i - id) % 2)
				ans.push_back({ id, i, a[id], a[id] + 1 });
			else
				ans.push_back({ id, i, a[id], a[id] });
		}
		cout << ans.size() << '\n';
		for (auto x : ans) {
			cout << x[0] + 1 << ' ' << x[1] + 1 << ' ' << x[2] << ' ' << x[3] << '\n';
		}
	}
	return 0;
}