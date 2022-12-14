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
		string s;
		cin >> s;
		int cnt0 = 0, cnt1 = 0;
		int f = -1, l = -1;
		forn (i, sz(s)) {
			if (s[i] == '0') {
				cnt0++;
				if (f == -1)
					f = i;
				l = i;
			}
			else
				cnt1++;
		}
		if (cnt0 == 0) {
			cout << "0\n";
			continue;
		}
		if (cnt1 == 0) {
			cout << "1\n";
			continue;
		}
		bool ok = 1;
		forab (i, f, l + 1)
			if (s[i] == '1')
				ok = 0;
		cout << (ok ? "1\n" : "2\n");
	}
	
	return 0;
}