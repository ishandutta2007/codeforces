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
	// cerr << n << endl;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	vector<int> amount(n + 1);
	amount[0] = 1;
	for (int num : arr) {
		vector<int> here;
		for (int j = 1; j * j <= num; ++j) {
			if (num % j == 0) {
				here.push_back(j);
				if (j * j < num) {
					here.push_back(num / j);
				}
			}
		}

		sort(here.begin(), here.end());
		reverse(here.begin(), here.end());
		for (int ind : here) {
			if (ind <= n) {
				add(amount[ind], amount[ind - 1]);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		// cerr << amount[i] << endl;
		add(ans, amount[i]);
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