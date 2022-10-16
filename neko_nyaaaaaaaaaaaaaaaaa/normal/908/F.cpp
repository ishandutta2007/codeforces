#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans = 0;
int n;
char c;
vector<pair<ll, ll>> a;
ll inf = 1e18;

ll calc(ll start, ll end) {
	if (start + 1 == end) {return a[start].first - a[end].first;}

	ll l[2] = {a[start].first, a[start].first};
	ll ma[2] = {-inf, -inf};
	for (ll i = start + 1; i < end; i++) {
		ma[a[i].second] = max(ma[a[i].second], a[i].first - l[a[i].second]);
		l[a[i].second] = a[i].first;
	}
	ma[0] = max(ma[0], a[end].first - l[0]);
	ma[1] = max(ma[1], a[end].first - l[1]);
	return a[end].first - a[start].first - ma[0] - ma[1];
}

int main() {
      ios::sync_with_stdio(0);

	cin >> n;
	if (n == 1) {cout << 0; return 0;}
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> c;

		if (c == 'G') a[i].second = -1;
		else if (c == 'B') a[i].second = 0;
		else a[i].second = 1;
	}

	ll mi[2] = {inf, inf}, ma[2] = {-inf, -inf};

	for (int i = 0; i < n; i++) {
		if (a[i].second == -1) {
			for (int j = 0; j < 2; j++) {
				mi[j] = min(mi[j], a[i].first), ma[j] = max(ma[j], a[i].first);
			}
		}
		else {
			mi[a[i].second] = min(mi[a[i].second], a[i].first);
			ma[a[i].second] = max(ma[a[i].second], a[i].first);
		}
	}

	if (ma[0] != -inf) ans += ma[0] - mi[0];
	if (ma[1] != -inf) ans += ma[1] - mi[1];

	ll j = -1;
	while (++j < n && a[j].second != -1);
	for (int i = j + 1; i < n; i++) {
		if (a[i].second == -1) {
			ll tmp = calc(j, i);
			if (tmp < 0) ans += tmp;
			j = i;
		}
	}
	cout << ans;
}