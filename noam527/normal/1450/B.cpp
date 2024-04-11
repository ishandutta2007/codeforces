#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n, k;
vector<int> x, y;

void solve() {
	cin >> n >> k;
	x.resize(n);
	y.resize(n);
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	for (int i = 0; i < n; i++) {
		bool good = true;
		for (int j = 0; j < n; j++) {
			if (abs(x[i] - x[j]) + abs(y[i] - y[j]) > k)
				good = false;
		}
		if (good) {
			cout << "1\n";
			return;
		}
	}
	cout << "-1\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}