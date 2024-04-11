#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const int OO = 1;
using namespace std;

int n, k;
vector<int> a;

void solve() {
	cin >> n >> k;
	a.resize(n);
	for (auto &i : a) cin >> i;
	ll ans = 0;
	for (auto &i : a) ans += i;
	for (int i = 0; i < n; i++) a[i] += i;
	for (int i = 1; i <= k; i++)
		ans += n - i;

	sort(a.rbegin(), a.rend());
	for (int i = 0; i < k; i++)
		ans -= a[i];
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}