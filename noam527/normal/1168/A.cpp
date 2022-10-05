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

int n, m;
vector<int> a;

bool can(int x) {
	int lst;
	if (a[0] + x >= m) lst = 0;
	else lst = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] + x < m) {
			if (lst > a[i] + x) return false;
			lst = max(lst, a[i]);
		}
		else {
			int y = (a[i] + x) % m;
			if (lst > y) lst = max(lst, a[i]);
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	a.resize(n);
	for (auto &i : a) cin >> i;
	int lo = 0, hi = m - 1, mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		if (can(mid)) hi = mid;
		else lo = mid + 1;
	}
	finish(lo);
}