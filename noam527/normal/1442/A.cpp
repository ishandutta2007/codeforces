#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define finish(X) return cout << (X) << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

int n;
vector<ll> a;

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	for (int i = n - 1; i >= 1; i--)
		a[i] -= a[i - 1];
	ll sum = 0;
	for (auto &i : a)
		if (i < 0)
			sum += -i;
	if (a[0] < sum) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	return;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) {
		solve();
	}
}