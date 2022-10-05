#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
vector<int> a, b;

bool check(int k) {
	int total = n + k;
	total -= (total / 4);
	int first = 0, second = 0;
	
	if (total <= k) first = 100 * total;
	else {
		first = 100 * k;
		int left = total - k;
		first += a[n - left];
	}
	if (total < n) second = b[n - total];
	else second = b[0];
	return first >= second;
}

void solve() {
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = n - 2; i >= 0; i--) {
		a[i] += a[i + 1];
		b[i] += b[i + 1];
	}
	int lo = 0, hi = 1000000, mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		if (check(mid)) hi = mid;
		else lo = mid + 1;
	}
	cout << lo << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}