#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
vector<int> a;

int work(int l, int r, int bit) {
	if (bit == -1) return 1;
	int first = -1;
	for (int i = l; i <= r; i++)
		if (a[i] & (1 << bit)) {
			first = i;
			break;
		}
	if (first == l || first == -1)
		return work(l, r, bit - 1);
	return max(work(l, first - 1, bit - 1), work(first, r, bit - 1)) + 1;
}

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	sort(a.begin(), a.end());
	cout << n - work(0, n - 1, 29) << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}