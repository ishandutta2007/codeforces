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
    int n, m;
    cin >> n >> m;
    int minx = INF, maxx = -INF, miny = INF, maxy = -INF;
    for (int i = 0; i < n; ++i) {
    	string s;
    	cin >> s;
    	for (int j = 0; j < m; ++j) {
    		if (s[j] == 'B') {
    			minx = min(minx, i);
    			maxx = max(maxx, i);
    			miny = min(miny, j);
    			maxy = max(maxy, j);
    		}
    	}
    }
    cout << (maxx + minx) / 2 + 1 << " " << (maxy + miny) / 2 + 1 << "\n";
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