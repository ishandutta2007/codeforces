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
	int m, k, n, s;
	cin >> m >> k >> n >> s;
	vector<int> arr;
	for (int i = 0; i < m; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	map<int, int> need;

	for (int i = 0; i < s; ++i) {
		int num;
		cin >> num;
		need[num]++;
	}

	map<int, int> have;
	int c = 0;
	int cnt_bad = szof(need);
	for (int i = 0; i < m; ++i) {
		while (c < m && cnt_bad > 0) {
			have[arr[c]]++;
			if (need.count(arr[c]) && have[arr[c]] == need[arr[c]]) {
				// cerr << c << " " << arr[c] << endl;
				--cnt_bad;
			}
			++c;
		}
		if (!cnt_bad) {
			if (i / k + 1 + (m - max(i + k, c)) / k >= n && i % k + k * (i / k - min(i / k, n - 1)) + max(0, c - i - k) <= m - n * k) {
				// cerr << i << " " << c << endl;
				have.clear();
				cout << i % k + max(0, c - i - k) << "\n";
				for (int j = 0; j < i % k + k * (i / k - min(i / k, n - 1)); ++j) {
					cout << j + 1 << " ";
				}
				int rm = max(0, c - i - k);
				for (int j = i; j < c; ++j) {
					if (have[arr[j]] >= need[arr[j]] && rm) {
						cout << j + 1 << " ";
						--rm;
					}
					have[arr[j]]++;
				}
				cout << "\n";
				return;
			}
		}
		if (need.count(arr[i]) && have[arr[i]] == need[arr[i]]) {
			++cnt_bad;
		}
		have[arr[i]]--;
	}
	cout << "-1\n";
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