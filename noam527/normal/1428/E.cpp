#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

ll cost(ll len, int parts) {
	ll mn = len / parts;
	ll mx = (len + parts - 1) / parts;

	ll cntmx = len % parts;
	ll cntmn = parts - cntmx;
	return mn * mn * cntmn + mx * mx * cntmx;
}

int n, k;
vector<ll> a;

void solve() {
	cin >> n >> k;
	k -= n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	vector<int> parts(n, 1);
	priority_queue<pair<ll, int>> q;
	for (int i = 0; i < n; i++) {
		if (a[i] >= 2) {
			q.push(make_pair(cost(a[i], 1) - cost(a[i], 2), i));
		}
	}
	while (k--) {
		auto x = q.top();
		q.pop();
		parts[x.second]++;
		if (parts[x.second] < a[x.second]) {
			q.push(make_pair(cost(a[x.second], parts[x.second]) - cost(a[x.second], parts[x.second] + 1), x.second));
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans += cost(a[i], parts[i]);
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}