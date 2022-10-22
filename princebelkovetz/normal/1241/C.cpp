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
	int n, x, a, y, b, k, cur, ans = 0, have; cin >> n;
	vector <int> ticks(n), prefix(n + 1, 0);
	vector <vector <int>> save(3, vector <int>(n + 1, 0));
	for (auto& x : ticks) {
		cin >> x;
		x /= 100;
	}
	sort(ticks.rbegin(), ticks.rend());
	for (int i = 1; i <= n; ++i) {
		prefix[i] = prefix[i - 1] + ticks[i - 1];
	}
	cin >> x >> a >> y >> b >> k;
	if (x < y) { swap(x, y); swap(a, b); }
	for (int i = 1; i <= n; ++i) {
		if (i % a == 0 and i % b == 0)save[0][i]++;
		else if (i % a == 0) save[1][i]++;
		else if (i % b == 0) save[2][i]++;
		save[0][i] += save[0][i - 1];
		save[1][i] += save[1][i - 1];
		save[2][i] += save[2][i - 1];
	}
	for (int i = 1; i <= n; ++i) {
		cur = 0;
		//cout << save[0][i] << " " << save[1][i] << " " << save[2][i] << endl;
		cur += prefix[save[0][i]] * (x + y);
		cur += (prefix[save[0][i] + save[1][i]] - prefix[save[0][i]]) * x;
		cur += (prefix[save[0][i] + save[1][i] + save[2][i]] - prefix[save[0][i] + save[1][i]]) * y;
		//cout << "cur " << cur << endl;
		if (cur >= k) {
			cout << i << endl; return;
		}
	}
	cout << "-1\n";



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