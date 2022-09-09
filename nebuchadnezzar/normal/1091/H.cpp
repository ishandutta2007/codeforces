#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
// #  define cerr __get_ce
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

const int SZ = 2e5 + 5;
int arr[SZ];
bool step[SZ];

void solve() {
	int n, f;
	cin >> n >> f;

	vector<int> vars;

	for (int i = 2; i < SZ; ++i) {
		if (i == f) {
			continue;
		}
		int tmp = i;
		int cnt = 0;
		for (int j = 2; j * j <= tmp; ++j) {
			while (tmp % j == 0) {
				tmp /= j;
				cnt++;
			}
		}
		if (tmp > 1) {
			++cnt;
		}
		if (cnt <= 2) {
			vars.push_back(i);
			step[i] = true;
		}
	}


	// vector<vector<int>> where(SZ + 1);

	// where[0].push_back(0);

	// for (int i = 1; i < SZ; ++i) {
	// 	if (i % 10000 == 0) {
	// 		cerr << i << endl;
	// 		cerr << accumulate(arr, arr + i, 0ll) << endl;
	// 	}
		
	// 	vector<int> all;
	// 	for (int shift : vars) {
	// 		if (shift > i) {
	// 			break;
	// 		}
	// 		all.push_back(arr[i - shift]);
	// 	}
	// 	sort(all.begin(), all.end());
	// 	all.erase(unique(all.begin(), all.end()), all.end());
	// 	for (int j = 0; j <= szof(all); ++j) {
	// 		if (j == szof(all) || all[j] != j) {
	// 			arr[i] = j;
	// 			break;
	// 		}
	// 	}
		
	// 	for (int j = 0; ; ++j) {
	// 		bool found = false;
	// 		for (int pos : where[j]) {
	// 			if (vars.count(i - pos)) {
	// 				found = true;
	// 				break;
	// 			}
	// 		}
	// 		if (!found) {
	// 			arr[i] = j;
	// 			break;
	// 		}
	// 	}

	// 	where[arr[i]].push_back(i);
	// }

	vector<int> left(SZ);
	iota(left.begin(), left.end(), 0);

	for (int i = 0; i < SZ; ++i) {
		if (!szof(left)) {
			break;
		}
		// if (i % 1 == 0) {
		// 	cerr << i << " " << szof(left) << endl;
		// }
		vector<int> next;
		vector<int> cur;
		for (int j : left) {
			// if (j % 10000 == 0) {
			// 	cerr << j << endl;
			// }
			for (int prev : cur) {
				if (step[j - prev]) {
					arr[j]++;
					break;
				}
			}
			if (arr[j] > i) {
				next.push_back(j);
			} else {
				cur.push_back(j);
			}
		}
		swap(next, left);
	}

	// for (int i = 0; i < 100; ++i) {
	// 	cerr << arr[i] << endl;
	// }

	// cerr << accumulate(arr, arr + SZ, 0ll) << endl;

	int res = 0;
	for (int i = 0; i < n; ++i) {
		int b, w, r;
		cin >> b >> w >> r;
		res ^= arr[w - b - 1] ^ arr[r - w - 1];
	}

	if (res) {
		cout << "Alice\nBob\n";
	} else {
		cout << "Bob\nAlice\n";
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