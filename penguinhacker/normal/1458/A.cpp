#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m;
ll a[200000], b[200000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	if (n == 1) {
		for (int i = 0; i < m; ++i) {
			cout << a[0] + b[i] << " ";
		}
		return 0;
	}
	ll base = abs(a[1] - a[0]);
	for (int i = 2; i < n; ++i) {
		base = __gcd(base, abs(a[i] - a[i - 1]));
	}
	for (int i = 0; i < m; ++i) {
		cout << __gcd(base, a[0] + b[i]) << " ";
	}
	return 0;
}