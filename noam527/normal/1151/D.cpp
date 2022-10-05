#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int n;
vector<pair<ll, ll>> a;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i.first >> i.second;
	ll ans = 0;
	sort(a.begin(), a.end(), [](const pair<int, int> &aa, const pair<int, int> &bb) {
		return aa.first - aa.second > bb.first - bb.second;
	});
	for (int i = 0; i < n; i++) {
		ans += i * a[i].first + (n - 1 - i) * a[i].second;
	}
	finish(ans);
}