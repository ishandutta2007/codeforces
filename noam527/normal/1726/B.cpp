#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

int n, m;

void solve() {
	cin >> n >> m;
	vector<int> result;
	if (n % 2 == 0) {
		if (m & 1) {
			cout << "No\n";
			return;
		}
		if (n == 2) {
			result = { m / 2, m / 2 };
		}
		else {
			if (m / 2 - n / 2 + 1 < 1) {
				cout << "No\n";
				return;
			}
			result = { m / 2 - n / 2 + 1, m / 2 - n / 2 + 1 };
			for (int i = 0; i < n - 2; i++) result.push_back(1);
		}
	}
	else {
		if (m <= n - 1) {
			cout << "No\n";
			return;
		}
		result.push_back(m - (n - 1));
		for (int i = 0; i < n - 1; i++)
			result.push_back(1);
	}
	cout << "Yes\n";
	for (const auto &i : result) cout << i << " "; cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}