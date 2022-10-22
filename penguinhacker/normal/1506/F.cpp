#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int cmp(int a, int b, int c, int d) {
	if (a == c && b == d)
		return 0;
	if ((a + b) % 2 == 0 && a - b == c - d)
		return c - a;
	if ((a + b) % 2 == 0)
		++a;
	a += d - b;
	return (c - a + 1) / 2;
}

int n;
ar<int, 2> a[200001];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i][0];
	for (int i = 1; i <= n; ++i)
		cin >> a[i][1];
	a[0] = {1, 1};
	++n;
	sort(a, a + n);
	int ans = 0;
	for (int i = 1; i < n; ++i) {
		ans += cmp(a[i - 1][0], a[i - 1][1], a[i][0], a[i][1]);
		//cout << ans << "\n";
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}