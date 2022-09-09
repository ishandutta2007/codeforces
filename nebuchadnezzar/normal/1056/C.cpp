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
	vector<int> arr;
	for (int i = 0; i < n * 2; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	vector<int> pairs(n * 2, -1);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		pairs[a] = b;
		pairs[b] = a;
	}

	set<pii> left;
	for (int i = 0; i < n * 2; ++i) {
		left.insert({arr[i], i});
	}

	int t;
	cin >> t;
	--t;

	vector<bool> used(n * 2);
	
	function<void(int)> make_turn = [&](int ind) {
		cout << ind + 1 << endl;
		used[ind] = true;
		assert(left.count({arr[ind], ind}));
		left.erase({arr[ind], ind});
	};

	int prev = -1;

	function<void()> jury_turn = [&]() {
		int ind;
		cin >> ind;
		--ind;
		used[ind] = true;
		left.erase({arr[ind], ind});
		prev = ind;
	};

	for (int i = 0; i < n * 2; ++i) {
		if (t == 0) {
			if (prev != -1 && pairs[prev] != -1 && !used[pairs[prev]]) {
				make_turn(pairs[prev]);
			} else {
				bool fl = false;
				for (int j = 0; j < n * 2; ++j) {
					if (!used[j] && pairs[j] != -1) {
						int a = j, b = pairs[j];
						if (arr[a] < arr[b]) {
							swap(a, b);
						}
						make_turn(a);
						fl = true;
						break;
					}
				}
				if (!fl) {
					// cerr << (--left.end())->ff << " " << (--left.end())->ss << endl;
					int ind = (--left.end())->ss;
					make_turn(ind);
				}
			}
		} else {
			jury_turn();
		}

		t = 1 - t;
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