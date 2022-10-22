#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#define endl "\n";
#define int long long
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
int fastpow(int a, int b) {
	if (!b) return 1ll;
	if (b % 2 == 1) return fastpow(a, b - 1) * a;
	int t = fastpow(a, b / 2);
	return t * t;
}

void solve() {
	int n, cur = 1; cin >> n;
	vector<int>a(n), ans(n);
	set <int> ok;
	for (auto& x : a) cin >> x;
	ans[0] = a[0]; ok.insert(a[0]);
	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i - 1]) {
			ans[i] = a[i];
			ok.insert(a[i]);
		}
		else if(a[i] == a[i - 1]){
			while (ok.find(cur) != ok.end()) ++cur;
			if (cur > a[i]) {
				cout << "-1\n"; return;
			}
			ok.insert(cur);
			ans[i] = cur;
		}
		else {
			cout << "-1\n"; return;
		}
	}
	for (auto x : ans) cout << x << " ";
	cout << endl;
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