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
struct op {
	int l, r, d;
};
void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector <int> a(n);
	for (auto& x : a) cin >> x;
	vector <op> opers(m);
	for (int i = 0; i < m; ++i) {
		cin >> opers[i].l >> opers[i].r >> opers[i].d;
	}
	vector <int> temp(n), ok(m);
	for (int i = 0; i < k; ++i) {
		int x, y; cin >> x >> y;
		ok[x - 1]++;
		if (y < m) ok[y]--;
	}
	int cur = 0;
	for (int i = 0; i < m; ++i) {
		cur += ok[i];
		ok[i] = cur;
	}
	for (int i = 0; i < m; ++i) {
		temp[opers[i].l - 1] += opers[i].d * ok[i];
		if (opers[i].r < n) temp[opers[i].r] -= opers[i].d * ok[i];
	}
	cur = 0;
	for (int i = 0; i < n; ++i) {
		cur += temp[i];
		a[i] += cur;
		cout << a[i] << " ";
	}
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