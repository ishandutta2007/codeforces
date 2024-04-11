#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <string>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

constexpr int mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(8);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n; cin >> n;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		vector <vector <int>> ans;
		for (int i = 0; i < n; i += 2) {
			ans.push_back({ 2, i, i + 1 });
			ans.push_back({ 2, i, i + 1 });
			ans.push_back({ 1, i, i + 1 });
			ans.push_back({ 2, i, i + 1 });
			ans.push_back({ 2, i, i + 1 });
			ans.push_back({ 1, i, i + 1 });
		}
		cout << ans.size() << '\n';
		for (auto& x : ans) {
			cout << x[0] << ' ' << x[1] + 1 << ' ' << x[2] + 1 << '\n';
		}
	}
}