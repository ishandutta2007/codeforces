#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, a, b;
void solve() {
	cin >> n >> m >> a >> b;
	vector<int> v(m); for (int& i : v) cin >> i;
	sort(v.begin(), v.end());
	v.resize(min(m, abs(a - b) - 1));
	int d = a < b ? b - 1 : n - b;
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i) v[i] += i;
	for (int i = (int)v.size() - 2; i >= 0; --i) v[i] = max(v[i], v[i + 1]);
	for (int i = 0; i < v.size(); ++i) {
		int x = v[i] - i + 1;
		if (x <= d) {
			cout << v.size() - i << "\n";
			return;
		}
	}
	cout << "0\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}