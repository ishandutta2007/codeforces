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

const int N = 305;

int was[N][N];

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
		int n, m;
		cin >> n >> m;
		forn (i, n)
			forn (j, m)
				was[i][j] = 0;
		vector<pii> a(n * m);
		forn (i, n * m) {
			cin >> a[i].fst;
			a[i].snd = i;
		}
		sort(all(a));
		int r = 0, c = 0;
		vi v;
		vector<pii> res(n * m);
		forn (i, n * m) {
			v.clear();
			int last = n * m;
			forab (j, i, n * m) {
				if (a[j].fst != a[i].fst) {
					last = j;
					break;
				}
				v.pb(a[j].snd);
			}
			sort(all(v));
			if (c + sz(v) <= m) {
				fornr (j, sz(v))
					res[v[j]] = mp(r, c), c++;
				if (c == m)
					r++, c = 0;
			} else {
				int k = m - c;
				int l = sz(v);
				fornr (j, k)
					res[v[j]] = mp(r, c), c++;
				r++, c = 0;
				l -= k;
				int rDelta = l / m;
				r += rDelta;
				forab (j, k, k + rDelta * m)
					res[v[j]] = mp(-1, -1);
				l %= m;
				for (int j = sz(v) - 1; j >= sz(v) - l; j--) {
					res[v[j]] = mp(r, c), c++;
				}
			}
			i = last - 1;
		}
		int ans = 0;
		forn (i, n * m) {
			if (res[i].fst == -1)
				continue;
			forn (j, res[i].snd)
				if (was[res[i].fst][j])
					ans++;
			was[res[i].fst][res[i].snd] = 1;
		}

		cout << ans << "\n";
	}
	
	return 0;
}