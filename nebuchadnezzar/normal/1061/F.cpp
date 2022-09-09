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

map<tuple<int, int, int>, int> mem;

bool ask(int a, int b, int c) {
	if (a > c) {
		swap(a, c);
	}
	if (mem.count({a, b, c})) {
		return mem[{a, b, c}];
	}
	cout << "? " << a + 1 << " " << b + 1 << " " << c + 1 << endl;
	string s;
	cin >> s;
	if (s == "No") {
		return mem[{a, b, c}] = 0;
	}
	return mem[{a, b, c}] = 1;
}

void solve() {
	int n, k;
	cin >> n >> k;
	int depth = 0;
	int cur = 1;
	int sum = 1;
	while (sum < n) {
		cur *= k;
		sum += cur;
		++depth;
	}
	int len = depth * 2 + 1;
	while (true) {
		int a = rnd(0, n - 1);
		int b = rnd(0, n - 1);
		if (a == b) {
			continue;
		}
		vector<int> arr;
		for (int i = 0; i < n; ++i) {
			if (i == a || i == b) {
				arr.push_back(i);
				continue;
			}
			if (ask(a, i, b)) {
				arr.push_back(i);
			}
		}
		if (szof(arr) == len) {
			sort(arr.begin(), arr.end(), [&](int c, int d) {
				if (c == a) {
					return true;
				}
				if (d == a) {
					return false;
				}
				if (c == b) {
					return false;
				}
				if (d == b) {
					return true;
				}
				return ask(a, c, d);
			});

			cout << "! " << arr[len / 2] + 1 << "\n";
			return;
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