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
#define int long long
#define endl "\n";
using namespace std;
long long md(long long x, long long mod) {
	return ((x % mod) + mod) % mod;
}
long long sub(long long x, long long y, long long mod) {
	return md(md(x, mod) - md(y, mod), mod);
}
int power(int n, int x, int m) {
	if (x % 2 == 1) return (n * power(n, x - 1, m)) % m;
	if (x == 0) return 1;
	int t = power(n, x / 2, m) % m;
	return(t * t) % m;
}
long long add(long long x, long long y, long long mod) {
	return md(md(x, mod) + md(y, mod), mod);
}
void solve(){
	int n, m, k, cur;
	cin >> n >> m >> k;
	vector <int> a(n), b(m), at, bt, ma(n + 1), mb(m + 1);
	at.push_back(-1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (!a[i]) {
			at.push_back(i);
		}
	}
	at.push_back(n);
	bt.push_back(-1);
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
		if (!b[i]) {
			bt.push_back(i);
		}
	}
	bt.push_back(m);
	for (int i = 1; i < at.size(); ++i) {
		cur = at[i] - at[i - 1] - 1;
		for (int j = 1; j <= cur; ++j) {
			ma[j] += cur - j + 1;
		}
	}
	for (int i = 1; i < bt.size(); ++i) {
		cur = bt[i] - bt[i - 1] - 1;
		for (int j = 1; j <= cur; ++j) {
			mb[j] += cur - j + 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= min(k, n); ++i) {
		if (k % i == 0 and i <= n and k / i <= m) {
			ans += ma[i] * mb[k / i];
		}
	}
	cout << ans;


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