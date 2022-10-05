#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
vector<int> a;
vector<pair<int, int>> op;

void add(int i, int j) {
	op.emplace_back(i, j);
}

void work(int i, int j) {
	if (i > j) swap(i, j);
	swap(a[i], a[j]);
	if (j - i >= n / 2) {
		add(i, j);
		return;
	}
	if (j < n / 2) {
		add(i, n - 1);
		add(j, n - 1);
		add(i, n - 1);
		return;
	}
	if (n / 2 <= i) {
		add(0, i);
		add(0, j);
		add(0, i);
		return;
	}
	add(i, n - 1);
	add(0, j);
	add(0, n - 1);
	add(i, n - 1);
	add(0, j);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i, --i;
	for (int i = 0; i < n; i++) {
		while (a[i] != i) {
			work(i, a[i]);
		}
	}
	cout << op.size() << '\n';
	for (const auto &i : op) cout << 1 + i.first << " " << 1 + i.second << '\n';
}