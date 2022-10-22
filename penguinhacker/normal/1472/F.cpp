#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
int n, m;
bool blocked[1000000][2];
void solve() {
	cin >> n >> m;
	vector<pair<int, int>> v(m);
	for (pair<int, int>& p : v) cin >> p.second >> p.first, --p.first, --p.second;
	if (m % 2 == 1) {cout << "NO\n"; return;}
	sort(v.begin(), v.end());
	vector<pair<int, int>> a = v;
	a[0].first %= 2;
	for (int i = 1; i < m; ++i) {
		if (v[i].first == v[i - 1].first) {
			a[i].first = a[i - 1].first;
		}
		else if (a[i].first >= a[i - 1].first + 3) {
			int x = (a[i].first - a[i - 1].first) % 2;
			a[i].first = a[i - 1].first + x + 2 * (1 - x);
		}
	}
	n = a.back().first + 1;
	assert(n <= 900000);
	memset(blocked, 0, 2 * n);
	for (pair<int, int> p : a) blocked[p.first][p.second] = 1;
	for (int i = 0; i < n - 1; ++i) {
		if (blocked[i][0] ^ blocked[i][1]) {
			int x = blocked[i][0] ? 1 : 0;
			assert(!blocked[i][x] && blocked[i][x ^ 1]);
			if (blocked[i + 1][x]) {cout << "NO\n"; return;}
			else blocked[i + 1][x] = 1;
		}
	}
	assert(!(blocked[n - 1][0] ^ blocked[n - 1][1]));
	cout << "YES\n";
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}