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
	int d, s;
	cin >> d >> s;
	vector<vector<pair<pii, pii>>> from(d, vector<pair<pii, pii>>(s + 1, {{INF, INF}, {-1, -1}}));
	set<pair<pii, pii>> st;
	st.insert({{-1, -1}, {0, 0}});
	int cnt = 0;
	while (szof(st)) {
		int rest, sum;
		tie(rest, sum) = st.begin()->ss;
		st.erase(st.begin());
		int fromd = 0;
		if (sum == 0) {
			fromd = 1;
		}
		for (int dig = fromd; dig < 10; ++dig) {
			int nrest = (rest * 10 + dig) % d;
			int nsum = sum + dig;
			pii cost = {cnt, dig};
			if (nsum <= s && from[nrest][nsum].ff > cost) {
				st.erase({from[nrest][nsum].ff, {nrest, nsum}});
				from[nrest][nsum] = {cost, {rest, dig}};
				st.insert({from[nrest][nsum].ff, {nrest, nsum}});
			}
		}
		++cnt;
	}

	if (from[0][s].ff.ff == INF) {
		cout << "-1\n";
	} else {
		string ans = "";
		int sum = s;
		int rest = 0;
		while (sum > 0) {
			auto tmp = from[rest][sum].ss;
			ans += '0' + tmp.ss;
			rest = tmp.ff;
			sum -= tmp.ss;
		}
		reverse(ans.begin(), ans.end());

		cout << ans << "\n";
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