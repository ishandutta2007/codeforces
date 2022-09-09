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
const int MAXN = 20005;

pii d[MAXN];

void solve() {
	int n, l, r;
	cin >> n >> l >> r;
	vector<int> inp, good;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		inp.push_back(a);
	}
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		good.push_back(num);
	}
	fill(d, d + MAXN, make_pair(-INF, 0));
	d[0].ff = 0;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		if (!good[i]) {
			for (int j = sum; j >= 0; --j) {
				d[j + inp[i]] = max(d[j + inp[i]], d[j]);
			}
			sum += inp[i];
		}
	}
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		if (good[i]) {
			arr.push_back(inp[i]);
		}
	}
	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());
	for (int val : arr) {
		for (int j = sum; j >= 0; --j) {
			if (l <= j && j <= r) {
				d[j + val] = max(d[j + val], {d[j].ff + 1, d[j].ss - 1});
			} else {
				d[j + val] = max(d[j + val], {d[j].ff, d[j].ss - 1});
			}
		}
		sum += val;
	}
	int ans = 0;
	for (int i = 0; i <= sum; ++i) {
		int cur = d[i].ff;
		if (-d[i].ss < szof(arr) && l <= i && i <= r) {
			++cur;
		}
		ans = max(ans, cur);
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