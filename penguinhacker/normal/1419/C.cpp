#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, x, a[1000];
void solve() {
	cin >> n >> x;
	bool can0 = 1;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		can0 &= a[i] == x;
	}
	if (can0) {
		cout << "0\n";
		return;
	}
	int cnt = count(a, a + n, x);
	int sum = accumulate(a, a + n, 0);
	bool can1 = sum == x * n || cnt >= 2;
	if (cnt == 1) {
		for (int i = 0; i < n; ++i) {
			can1 |= (sum - i * x) % (n - i) == 0;
		}
	}
	if (can1) {
		cout << "1\n";
	}
	else {
		cout << "2\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}