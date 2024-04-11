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
	int n, k, u, v, temp, cou = 0, ans= 0, mod = 1e9 + 7;
	cin >> n >> k;
	vector <vector <int>> a(n + 1);
	for (int i = 0; i < n - 1; ++i) {
		cin >> u >> v >> temp;
		if (!temp) {
			a[u].push_back(v);
			a[v].push_back(u);
		}
	}
	queue <int> q;
	vector <bool> used(n + 1, false);
	for (int i = 1; i <= n; ++i) {
		cou = 0;
		if (!used[i]) {
			q.push(i);
			used[i] = true;
			while (q.size()) {
				++cou;
				v = q.front();
				//cout << v << " ";
				q.pop();
				for (auto u : a[v]) {
					if (used[u]) continue;
					used[u] = true;
					q.push(u);
				}
			}
			ans = add(ans, power(cou, k, mod), mod);
			//cout << ans << " " << cou << endl;
		}
	}
	cout << sub(power(n, k, mod), ans, mod);
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