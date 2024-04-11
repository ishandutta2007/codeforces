#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

const int M = 5e6 + 10;

int n;
vector<pair<int, int>> a;
vector<pair<int, int>> b[M];

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i.first;
	for (int i = 0; i < n; i++) a[i].second = i;
	sort(a.begin(), a.end());
	int first = -1;
	for (int i = 0; i + 1 < n; i++) {
		if (a[i].first == a[i + 1].first) {
			if (first > -1 && first + 1 < i) {
				cout << "YES\n";
				cout << a[first].second + 1 << " " << a[i].second + 1 << " " << a[first + 1].second + 1 << " " << a[i + 1].second + 1 << '\n';
				return;
			}
			else if (first == -1) first = i;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int s = a[i].first + a[j].first;
			int ii = a[i].second, jj = a[j].second;
			for (const auto &x : b[s]) {
				int p = x.first, q = x.second;
				if (p != ii && p != jj && q != ii && q != jj) {
					cout << "YES\n";
					cout << ii + 1 << " " << jj + 1 << " " << p + 1 << " " << q + 1 << '\n';
					return;
				}
			}
			b[s].emplace_back(ii, jj);
		}
	}
	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	srand(time(NULL));
	int tst = 1;
//	cin >> tst;
	while (tst--) solve();
}