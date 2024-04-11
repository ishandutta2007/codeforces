#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
mt19937 tw(9450189);
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
    int n;
    cin >> n;
    vector<pair<pii, pii>> inp;
    vector<pair<pii, pii>> pref = {{{-INF, INF}, {-INF, INF}}};
    for (int i = 0; i < n; ++i) {
    	int x1, y1, x2, y2;
    	cin >> x1 >> y1 >> x2 >> y2;
    	inp.push_back({{x1, x2}, {y1, y2}});
    	pref.push_back({{max(pref.back().ff.ff, x1), min(pref.back().ff.ss, x2)}, {max(pref.back().ss.ff, y1), min(pref.back().ss.ss, y2)}});
    }

    pair<pii, pii> suff = {{-INF, INF}, {-INF, INF}};
    for (int i = n - 1; i >= 0; --i) {
    	pair<pii, pii> cur = {{max(suff.ff.ff, pref[i].ff.ff), min(suff.ff.ss, pref[i].ff.ss)}, {max(suff.ss.ff, pref[i].ss.ff), min(suff.ss.ss, pref[i].ss.ss)}};
    	if (cur.ff.ff <= cur.ff.ss && cur.ss.ff <= cur.ss.ss) {
    		cout << cur.ff.ff << " " << cur.ss.ff << "\n";
    		return;
    	}
    	suff = {{max(suff.ff.ff, inp[i].ff.ff), min(suff.ff.ss, inp[i].ff.ss)}, {max(suff.ss.ff, inp[i].ss.ff), min(suff.ss.ss, inp[i].ss.ss)}};
    }
}


int main() {
#ifdef LOCAL
    auto start_time = clock();
    cerr << setprecision(3) << fixed;
#endif
    cout << setprecision(15) << fixed;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_count = 1;
    // cin >> test_count;
    for (int test = 1; test <= test_count; ++test) {
        solve();
    }
    
#ifdef LOCAL
    auto end_time = clock();
    cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}