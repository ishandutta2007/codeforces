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

const int MOD = 1000000007;

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

void solve() {
    int n;
    cin >> n;
    map<int, int> good;
    good.insert({0, 1});
    set<int> have;
    have.insert(0);
    for (int i = 0; i < n; ++i) {
    	string s;
    	cin >> s;
    	int num;
    	cin >> num;
    	if (s == "ADD") {
    		auto it = have.lower_bound(num);
    		--it;
    		if (good.count(*it)) {
    			good.insert({num, good[*it]});
    		}

    		have.insert(num);
    	} else {
    		map<int, int> new_good;
    		auto it = have.lower_bound(num);
    		--it;
    		if (good.count(num)) {
    			//new_good.insert(*it);
    			add(new_good[*it], good[num]);
    		}
    		if (good.count(*it)) {
    			//new_good.insert(*it);
    			add(new_good[*it], good[*it]);
    		}

    		good = new_good;

    		have.erase(num);
    	}
    }

    int ans = 0;
    for (auto p : good) {
    	add(ans, p.ss);
    }

    cout << ans << "\n";
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