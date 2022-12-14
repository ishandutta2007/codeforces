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

int main() {
#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n;
	cin >> n;
	vi a(n);
	forn (i, n)
		cin >> a[i];
	ll ans = 0;
	for (int i = 0; i < n; i += 2) {
		ll l = 1, r = a[i], bal = 0;
		for (int j = i + 1; j < n; j++) {
			if (j % 2 == 0)
				bal += a[j];
			else {
				bal -= a[j];
				if (bal < 0 && abs(bal) > l) 
					ans += min(r - l + 1, abs(bal) - l), l = abs(bal);
				if (l > r)
					break;
				if (bal < 0 && abs(bal) == l)
					ans++;
			}
		}
	}
	cout << ans << "\n";
	
	return 0;
}