#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define int long long
#define endl "\n";
using namespace std;

void solve(){
	int n, ans = 0;
	cin >> n;
	vector <int> a(n);
	for (auto& x : a) {
		cin >> x;
	}
	ans += a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		ans += min(a[i + 1] - 1, a[i]);
		a[i] = min(a[i + 1] - 1, a[i]);
		if (!a[i]) break;
	}
	cout << ans;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t = 1;
	while (t--) {
		solve();
	}
	return 0;
}