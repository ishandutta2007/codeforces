#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[5000], p[5000];

int find(int i) {
	if (i >= n || i == p[i]) return i;
	return p[i] = find(p[i]);
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		p[i] = i + (a[i] == 1);
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 1) continue;
		if (i + a[i] >= n) {
			ans += i + a[i] - n;
			a[i] = n - i;
		}
		while(a[i] > 1) {
			++ans;
			for (int j = i; j < n;) {
				if (a[j] == 1) {
					j = p[j] = find(j + 1);
				}
				else {
					--a[j];
					j += a[j] + 1;
				}
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}