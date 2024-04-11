#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
vector<ll> p;
int x, A, y, B;
ll k;

vector<ll> w;

ll calc(int cnt) {
	vector<ll> ws(cnt);
	for (int i = 0; i < cnt; i++)
		ws[i] = w[i];
	sort(ws.rbegin(), ws.rend());
	ll ans = 0;
	for (int i = 0; i < cnt; i++)
		ans = min(inf, ans + p[i] * ws[i]);
	return ans;
}

ll solve() {
	cin >> n;
	p.resize(n);
	for (auto &i : p) cin >> i, i /= 100;
	cin >> x >> A >> y >> B >> k;

	sort(p.rbegin(), p.rend());

	w.clear();
	w.resize(n, 0);
	for (int i = 0; i < n; i++) {
		if ((i + 1) % A == 0) w[i] += x;
		if ((i + 1) % B == 0) w[i] += y;
	}

	int lo = 1, hi = n, mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		if (calc(mid) < k) lo = mid + 1;
		else hi = mid;
	}
	if (lo == n && calc(n) < k) return -1;
	return lo;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst;
	cin >> tst;
	while (tst--) cout << solve() << '\n';
}