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

const int N = 2e5 + 5;
const ll INF = 1e18;

ll dp[N][2];

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
		vector<ll> a(n);
		vector<pair<ll, pii>> events;
		forn (i, n) {
			cin >> a[i];
			events.pb(mp(a[i], mp(0, i)));
		}
		sort(all(a));
		vector<pair<ll, ll>> b(m);
		vi was(m);
		forn (i, m) {
			cin >> b[i].fst >> b[i].snd;
			events.pb(mp(b[i].fst, mp(-1, i)));
			events.pb(mp(b[i].snd, mp(1, i)));
		}
		sort(all(events));
		set<int> s;
		for (auto ev : events) {
			int typ = ev.snd.fst;
			int ind = ev.snd.snd;
			if (typ == 0) {
				for (int seg : s) 
					was[seg] = 1;
			} else if (typ == -1) {
				s.insert(ind);
			} else if (typ == 1) {
				s.erase(ind);
			}
		}
		vector<pair<ll, ll>> segs;
		forn (i, m)
			if (!was[i])
				segs.pb(b[i]);
		sort(all(segs));
		int cur = 0;
		vector<pair<ll, ll>> tmp;
		forn (i, n) {
			dp[i][0] = dp[i][1] = INF;
			tmp.clear();
			while (cur != sz(segs) && segs[cur].snd < a[i]) {
				tmp.pb(segs[cur++]);
			}
			if (i == 0) {
				ll minR = INF;
				for (auto np : tmp)
					minR = min(minR, np.snd);
				
				if (minR == INF)
					dp[i][0] = dp[i][1] = 0;
				else {
					dp[i][0] = (a[i] - minR);
					dp[i][1] = (a[i] - minR) * 2;
				}
			} else {
				if (tmp.empty()) {
					dp[i][0] =dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
				} else {
					ll curR = a[i];
					for (int j = sz(tmp) - 1; j >= 0; j--) {
						ll dL = tmp[j].fst - a[i - 1];
						ll dR = a[i] - curR;
						curR = min(curR, tmp[j].snd);
						ll x = min(dp[i - 1][0] + 2 * dL, dp[i - 1][1] + dL);
						dp[i][0] = min(dp[i][0], x + dR);
						dp[i][1] = min(dp[i][1], x + 2 * dR);
					}
					dp[i][0] = min(dp[i][0], min(dp[i - 1][0], dp[i - 1][1]) + a[i] - curR);
					dp[i][1] = min(dp[i][1], min(dp[i - 1][0], dp[i - 1][1]) + 2 * (a[i] - curR));
				}
			}
			//cout << dp[i][0] << " " << dp[i][1] << "\n";
		}
		ll ans = min(dp[n - 1][0], dp[n - 1][1]);
		if (cur != sz(segs)) {
			ll d = segs.back().fst - a[n - 1];
			ans = min(dp[n - 1][1] + d, dp[n - 1][0] + 2 * d);
		}
		cout << ans << "\n";
	}
	
	return 0;
}