#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#define int long long
#define endl "\n"
#define debug(x) cout << #x << " actually equals " << x << endl
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}
using namespace std;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(3);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		map <int, int> mods;
		for (auto x : a) {
			mods[x % k]++;
		}
		int ans = 0, cur = 0;
		for (auto x : mods) {
			if (x.first == 0) continue;
			cur = k * x.second - x.first + 1;
			ans = max(cur, ans);
		}
		cout << ans << endl;
	}
	return 0;
}