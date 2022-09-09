#include "bits/stdc++.h"
#define ff first
#define ss second
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }


void solve() {
	int n, k;
	cin >> k >> n;
	vector<int> all;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		all.push_back(t);
	}
	sort(all.begin(), all.end());
	vector<int> diffs;
	for (int i = 0; i < n - 1; ++i) {
		diffs.push_back(all[i + 1] - all[i]);
	}

	vector<int> rest;
	auto tmp = diffs;
	int sz = min(k * 2 + 5, n - 1);
	nth_element(tmp.begin(), tmp.begin() + sz - 1, tmp.end());
	int val = tmp[sz - 1];
	
	int cnt = 0;
	int prev = -1;
	for (int i = 0; i < n - 1; ++i) {
		if (diffs[i] < val || (diffs[i] == val && cnt < sz)) {
			cnt += (diffs[i] == val);
			if (prev != -1 && prev < i - 1) {
				rest.push_back(diffs[i - 1]);
			}
			rest.push_back(diffs[i]);
			prev = i;
		}
	}

	vector<int> d1(k + 1, INF);
	vector<int> d2(k + 1, INF);
	d1[0] = 0;
	d2[0] = 0;
	for (int num : rest) {
		vector<int> next(k + 1, INF);
		for (int i = 0; i <= k; ++i) {
			next[i] = min(next[i], d2[i]);
			if (i < k) {
				next[i + 1] = min(next[i + 1], d1[i] + num);
			}
		}
		swap(d1, d2);
		swap(d2, next);
	}
	cout << d2[k] << "\n";
}


int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);
	cerr << fixed << setprecision(15);
	cout << fixed << setprecision(15);
	ios::sync_with_stdio(false);

	int tests = 1;
	// cin >> tests;
	for (int it = 1; it <= tests; ++it) {
		solve();
	}
	
	#ifdef LOCAL
		cerr << "time: " << clock() << " ms\n";
	#endif
	return 0;
}