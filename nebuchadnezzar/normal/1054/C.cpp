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
	int n;
	cin >> n;
	vector<int> l, r;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		l.push_back(num);
	}
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		r.push_back(num);
	}

	vector<pii> arr;
	for (int i = 0; i < n; ++i) {
		arr.push_back({l[i] + r[i], i});
	}

	sort(arr.begin(), arr.end());
	int cnt = n;
	int prev = 0;
	vector<int> res(n);
	for (int i = 0; i < szof(arr); ++i) {
		if (arr[i].ff != prev) {
			--cnt;
			prev = arr[i].ff;
		}
		res[arr[i].ss] = cnt;
	}

	int bpv = 1;
	while (bpv < n) {
		bpv *= 2;
	}

	vector<int> segtree(bpv * 2);

	function<void(int, int)> add = [&](int pos, int val) {
		pos += bpv;
		while (pos) {
			segtree[pos] += val;
			pos /= 2;
		}
	};

	function<int(int, int, int, int, int)> get_sum = [&](int v, int vl, int vr, int l, int r) {
		if (vr <= l || r <= vl) {
			return 0;
		}
		if (l <= vl && vr <= r) {
			return segtree[v];
		}
		int vm = (vl + vr) / 2;
		return get_sum(v * 2, vl, vm, l, r) + get_sum(v * 2 + 1, vm, vr, l, r);
	};

	for (int i = 0; i < n; ++i) {
		if (get_sum(1, 0, bpv, res[i], bpv) != l[i]) {
			cout << "NO\n";
			return;
		}
		add(res[i] - 1, 1);
	}

	segtree = vector<int>(bpv * 2);

	for (int i = n - 1; i >= 0; --i) {
		if (get_sum(1, 0, bpv, res[i], bpv) != r[i]) {
			cout << "NO\n";
			return;
		}
		add(res[i] - 1, 1);
	}	

	cout << "YES\n";
	for (int num : res) {
		cout << num << " ";
	}
	cout << "\n";


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