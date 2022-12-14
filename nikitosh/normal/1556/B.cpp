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

ll dif(const vi& v, const vi& u) {
	int n = sz(v);
	ll ans = 0;
	forn (i, n)
		ans += abs(v[i] - u[i]);
	return ans;
}

int main() {
#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int tn;
	cin >> tn;
	forn (tt, tn) {
		int n;
		cin >> n;
		vi a(n);
		vi t1, t2;
		forn (i, n) {
			cin >> a[i];
			if (a[i] % 2 == 0)
				t1.pb(i);
			else
				t2.pb(i);
		}
		vi pos;
		for (int i = 0; i < n; i += 2)
			pos.pb(i);
		if (abs(sz(t1) - sz(t2)) > 1) {
			cout << "-1\n";
		} else if (abs(sz(t1) - sz(t2)) == 1) {
			vi v;
			if (sz(t1) > sz(t2))
				v = t1;
			else
				v = t2;
			cout << dif(pos, v) << "\n";
		} else if (sz(t1) == sz(t2)) {
			cout << min(dif(pos, t1), dif(pos, t2)) << "\n";
		}
	}
	
	return 0;
}