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
	ll ans = 0;
	vector<vector<int>> type(4);
	for (int i = 0; i < n; ++i) {
		string s;
		int num;
		cin >> s >> num;
		int t = 0;
		for (char c : s) {
			t = t * 2 + c - '0';
		}
		type[t].push_back(num);
	}

	for (auto& v : type) {
		sort(v.begin(), v.end());
	}

	for (int num : type[3]) {
		ans += num;
	}

	while (szof(type[1]) && szof(type[2])) {
		ans += type[1].back() + type[2].back();
		type[1].pop_back();
		type[2].pop_back();
	}

	vector<int> arr;
	for (int i = 0; i < 3; ++i) {
		for (int num : type[i]) {
			arr.push_back(num);
		}
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < szof(type[3]) && szof(arr); ++i) {
		ans += arr.back();
		arr.pop_back();
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