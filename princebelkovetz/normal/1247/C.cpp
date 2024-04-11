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
using namespace std;

void solve() {
	int n, p;
	cin >> n >> p;
	for (int i = 1; i <= 1e7; ++i) {
		if (n - p * i >= 0 and __builtin_popcount(n - p * i) <= i and n - p * i >= i) {
			cout << i; return;
		}
	}
	cout << -1;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t;
	t = 1;
	while (t--) {
		solve();
	}
	return 0;
}