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
	int n, x1, x2;
	cin >> n >> x1 >> x2;
	vector<pii> arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back({num, i});
	}

	sort(arr.begin(), arr.end());

	int best2 = INF;
	int from2 = -1, to2 = -1;
	int best1 = INF;
	int from1 = -1, to1 = -1;
	for (int i = 0; i < n; ++i) {
		int l1 = (x1 + arr[i].ff - 1) / arr[i].ff;
		int l2 = (x2 + arr[i].ff - 1) / arr[i].ff;
		if (i + l1 <= n && best2 <= i) {
			cout << "Yes\n";
			cout << l1 << " " << to2 - from2 << "\n";
			for (int j = 0; j < l1; ++j) {
				cout << arr[i + j].ss + 1 << " ";
			}
			cout << "\n";
			for (int j = from2; j < to2; ++j) {
				cout << arr[j].ss + 1 << " ";
			}
			cout << "\n";
			return;
		}

		if (i + l2 <= n && best1 <= i) {
			cout << "Yes\n";
			cout << to1 - from1 << " " << l2 << "\n";
			for (int j = from1; j < to1; ++j) {
				cout << arr[j].ss + 1 << " ";
			}
			cout << "\n";
			for (int j = 0; j < l2; ++j) {
				cout << arr[i + j].ss + 1 << " ";
			}
			cout << "\n";
			return;
		}
		
		if (i + l2 < best2) {
			best2 = i + l2;
			from2 = i;
			to2 = i + l2;
		}
		if (i + l1 < best1) {
			best1 = i + l1;
			from1 = i;
			to1 = i + l1;
		}
	}

	cout << "No\n";
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