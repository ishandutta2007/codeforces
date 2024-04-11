#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end()

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)
#endif

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using vi = vector<int>;
using pii = pair<int, int>;

const int N = 1e5 + 5;

pair<ll, ll> t[4 * N];

pair<ll, ll> get(int l, int r) {
	ll minn = 1e18, maxx = -1e18;
	while (l <= r) {
		if (l & 1)
			minn = min(minn, t[l].first), maxx = max(maxx, t[l].second), l++;
		if ((r & 1) == 0)
			minn = min(minn, t[r].first), maxx = max(maxx, t[r].second), r--;
		l /= 2, r /= 2;
	}
	return {minn, maxx};
}

int main() {
#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n, q;
	cin >> n >> q;
	vi a(n), b(n);
	vector<ll> sumA(n + 1);
	forn (i, n) {
		cin >> a[i];
		sumA[i + 1] = sumA[i] + a[i];
	}
	vector<ll> sumB(n + 1);
	forn (i, n) {
		cin >> b[i];
		sumB[i + 1] = sumB[i] + b[i];
	}
	ll cur = 0;
	vector<ll> v;
	v.pb(0);
	forn (i, n) {
		cur += b[i] - a[i];
		v.pb(cur);
	}
	int tSize = 1;
	while (tSize <= n)
		tSize *= 2;
	forn (i, n + 1)
		t[tSize + i] = mp(v[i], v[i]);
	for (int i = tSize - 1; i > 0; i--) {
		t[i].first = min(t[2 * i].first, t[2 * i + 1].first);
		t[i].second = max(t[2 * i].second, t[2 * i + 1].second);
	}

	forn (qq, q) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		if (sumA[r + 1] - sumA[l] != sumB[r + 1] - sumB[l]) {
			cout << "-1\n";
			continue;
		}
		ll k = v[l];
		auto np = get(tSize + l, tSize + r);
		if (np.first < k)
			cout << "-1\n";
		else
			cout << np.second - k << "\n";
	}
	
	return 0;
}