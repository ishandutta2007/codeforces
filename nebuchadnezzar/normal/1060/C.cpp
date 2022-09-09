#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#  define _GLIBCXX_DEBUG_PEDANTIC
#endif

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
	int n, m;
	cin >> n >> m;
	vector<int> arra, arrb;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arra.push_back(num);
	}

	for (int i = 0; i < m; ++i) {
		int num;
		cin >> num;
		arrb.push_back(num);
	}

	int x;
	cin >> x;
	vector<int> min_val_a(n + 1, INF);
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = i; j < n; ++j) {
			sum += arra[j];
			min_val_a[j - i + 1] = min(min_val_a[j - i + 1], sum);
		}
	}

	for (int i = n; i > 0; --i) {
		min_val_a[i - 1] = min(min_val_a[i - 1], min_val_a[i]);
	}

	vector<int> min_val_b(m + 1, INF);
	for (int i = 0; i < m; ++i) {
		int sum = 0;
		for (int j = i; j < m; ++j) {
			sum += arrb[j];
			min_val_b[j - i + 1] = min(min_val_b[j - i + 1], sum);
		}
	}

	for (int i = m; i > 0; --i) {
		min_val_b[i - 1] = min(min_val_b[i - 1], min_val_b[i]);
	}

	// for (int num : min_val_a) {
	// 	cerr << num << " ";
	// }
	// cerr << endl;


	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int l = 0, r = m + 1;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if ((ll) min_val_a[i] * min_val_b[mid] <= x) {
				l = mid;
			} else {
				r = mid;
			}
		}
		ans = max(ans, i * l);
	}

	cout << ans << "\n";
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