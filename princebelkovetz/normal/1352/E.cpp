#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#define int long long
#define endl "\n";
using namespace std;
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}
void solve(){
	int n, cs, ans = 0; cin >> n;
	unordered_map <int, bool> m;
	vector <int> a(n);
	for (auto& x : a) {
		cin >> x;
	}
	for (int i = 0; i < n - 1; ++i) {
		cs = a[i];
		for (int j = i + 1; j < n; ++j) {
			cs += a[j];
			if (cs > n) break;
			m[cs] = true;
		}
	}
	for (auto x : a) {
		if (m.find(x) != m.end()) {
			++ans;
		}
	}
	cout << ans << endl;



}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}