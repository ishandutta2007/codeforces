// Created by Nikolay Budin

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
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> arr;
	int tot = 0;
	for (int i = 0; i < m; ++i) {
		int num;
		cin >> num;
		tot += num;
		arr.push_back(num);
	}

	vector<bool> split(n + 1);
	// split[0] = true;
	split[n] = true;
	int cnt = 0;
	int pref = 0;
	for (int i = 0; i < tot; i += n) {
		int next = i + n;
		while (cnt < szof(arr) - 1 && pref + arr[cnt] <= next) {
			split[(pref + arr[cnt]) - i] = true;
			pref += arr[cnt];
			++cnt;
		}
	}

	cnt = 0;

	for (int i = 0; i < n; ++i) {
		if (split[i + 1]) {
			++cnt;
		}
	}

	for (int i = 1; i <= n && cnt < m; ++i) {
		if (!split[i]) {
			split[i] = true;
			++cnt;
		}
	}

	vector<int> lens;
	int from = 0;
	for (int i = 0; i <= n; ++i) {
		if (split[i]) {
			lens.push_back(i - from);
			from = i;
		}
	}

	assert(szof(lens) == m);

	pref = 0;
	cnt = 0;
	vector<vector<int>> ans(m);
	for (int i = 0; i < m; ++i) {
		int cur = 0;
		while (cur < arr[i]) {
			cur += lens[cnt];
			ans[cnt].push_back(i);
			cnt = (cnt + 1) % m;
		}

		assert(cur >= arr[i]);
	}

	for (int i = 0; i < m; ++i) {
		assert(szof(ans[i]) <= (tot + n - 1) / n);
	}

	cout << (tot + n - 1) / n << "\n";
	for (int num : lens) {
		cout << num << " ";
	}
	cout << "\n";
	vector<int> sum(m);
	for (int i = 0; i < (tot + n - 1) / n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (szof(ans[j]) <= i) {
				cout << "1 ";
				sum[0] += lens[j];
			} else {
				cout << ans[j][i] + 1 << " ";
				sum[ans[j][i]] += lens[j];
			}
		}
		cout << "\n";
	}

	for (int i = 0; i < m; ++i) {
		assert(sum[i] >= arr[i]);
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