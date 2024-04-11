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
	vector<ll> ans;
	ll lowest = 1;
	for (int i = 1; i < n; i += 2) {
		int num;
		cin >> num;
		ll next = INFL;
		ll cur = -1;
		for (int p = 1; p * p <= num; ++p) {
			if (num % p == 0) {
				int q = num / p;
				if ((p + q) % 2 == 0) {
					int j = (p + q) / 2;
					int was = j - p;
					if (lowest <= was) {
						if (next > j) {
							next = j;
							cur = was;
						}
					}
				}
			}
		}
		if (next == INFL) {
			cout << "No\n";
			return;
		}
		ans.push_back(cur);
		ans.push_back(next);
		lowest = next + 1;
	}

	cout << "Yes\n";
	ll prev = 0;
	for (auto num : ans) {
		cout << num * num - prev << " ";
		prev = num * num;
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