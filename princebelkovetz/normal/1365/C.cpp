#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <iomanip>
#define int long long
#define endl "\n";
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}
void solve() {
	int n, ok = 0;
	cin >> n;
	vector <int> a(n), b(n), pos(n), ans(n);
	
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		pos[a[i] - 1] = i;
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		ans[(i - pos[b[i] - 1] + n) % n]++;
	}
	for (auto x : ans) {
		ok = max(ok, x);
	}
	cout << ok;
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