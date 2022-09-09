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
	map<string, int> cnt;
	map<string, string> any;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		set<string> was;
		for (int j = 0; j < szof(s); ++j) {
			string cur = "";
			for (int k = j; k < szof(s); ++k) {
				cur += s[k];
				if (!was.count(cur)) {
					was.insert(cur);
					cnt[cur]++;
					any[cur] = s;
				}
			}
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		if (cnt.count(s)) {
			cout << cnt[s] << " " << any[s] << "\n";
		} else {
			cout << "0 -\n";
		}
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