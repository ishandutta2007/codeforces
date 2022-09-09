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
	vector<int> inp;
	map<int, vector<int>> have;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		inp.push_back(num);
		have[num].push_back(i);
	}

	vector<int> ans(n);
	int cnt = 0;

	for (auto& p : have) {
		int val = p.ff;
		int other = n - szof(p.ss);
		if (other > val) {
			cout << "Impossible\n";
			return;
		}
		int part = n - val;
		if (szof(p.ss) % part) {
			cout << "Impossible\n";
			return;
		}

		for (int i = 0; i < szof(p.ss); i += part) {
			for (int j = 0; j < part; ++j) {
				ans[p.ss[i + j]] = cnt;
			}
			++cnt;
		}
	}

	cout << "Possible\n";
	for (int num : ans) {
		cout << num + 1 << " ";
	}
	cout << "\n";
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