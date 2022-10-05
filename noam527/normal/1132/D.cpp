#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e13;
const int OO = 1;
using namespace std;

struct comp {
	ll a, b;
	comp(ll aa = 0, ll bb = 0) {
		a = aa;
		b = bb;
	}
	bool operator < (const comp &c) const {
		return a / b > c.a / c.b;
	}
};

int n, k;
vector<ll> a, b;
vector<comp> S[200005];

bool can(ll t) {
	for (int i = 0; i < k; i++) S[i].clear();
	for (int i = 0; i < n; i++)
		if (a[i] / b[i] < k) S[a[i] / b[i]].push_back(comp(a[i], b[i]));
	int nxt = 0;
	for (int i = 0; i < k; i++) {
		while (nxt < k && S[nxt].size() == 0) nxt++;
		//if (OO && t == 5) cout << i << " " << nxt << '\n';
		if (nxt == k) return true;
		if (nxt < i) return false;
		comp x = S[nxt].back();
		S[nxt].pop_back();
		x.a += t;
		if (x.a / x.b < k)
			S[x.a / x.b].push_back(comp(x.a, x.b));
	}
	while (nxt < k && S[nxt].size() == 0) nxt++;
	return nxt >= k - 1;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	a.resize(n);
	b.resize(n);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;

	ll lo = 0, hi = inf, mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		if (can(mid)) hi = mid;
		else lo = mid + 1;
	}
	if (lo == inf) finish(-1);
	finish(lo);
}