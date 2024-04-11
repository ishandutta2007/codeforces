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
	
	int tn;
	cin >> tn;
	forn (tt, tn) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		vi a(n), sat(n);
		forn (i, n)
			a[i] = s[i] - '0' + t[i] - '0';
		int ans = 0;
		forn (i, n) {
			if (a[i] == 1)
				ans += 2;
			if (a[i] == 0)
				ans += 1;
			if (a[i] == 2) {
				int last = n;
				forab (j, i, n) {
					if (a[j] != 2) {
						last = j;
						break;
					}
				}
				bool isPresent = 1;
				if (i != 0 && a[i - 1] == 0 && !sat[i - 1]) {
					sat[i - 1] = 1;
					ans++;
					isPresent = 0;
				}
				if (last != i + 1)
					isPresent = 1;
				if (isPresent && last != n && a[last] == 0) {
					sat[last] = 1;
					ans++;
				}
				i = last - 1;
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}