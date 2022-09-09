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

vector<vector<int>> tree;

const int MAXN = 1e4 + 5;
bitset<MAXN> lvls[20];
bitset<MAXN> res;
int n, q;

void dfs(int v, int vl, int vr, int d) {
	if (n <= vl) {
		return;
	}
	lvls[d + 1] = lvls[d];
	for (int num : tree[v]) {
		lvls[d + 1] = (lvls[d + 1] << num) | lvls[d + 1];
	}
	if (vl == vr - 1) {
		res |= lvls[d + 1];
		return;
	}

	int vm = (vl + vr) / 2;
	dfs(v * 2, vl, vm, d + 1);
	dfs(v * 2 + 1, vm, vr, d + 1);
}

void solve() {
	cin >> n >> q;
	int bpv = 1;
	while (bpv < n) {
		bpv *= 2;
	}
	tree = vector<vector<int>>(bpv * 2);
	for (int i = 0; i < q; ++i) {
		int l, r, x;
		cin >> l >> r >> x;
		--l;
		l += bpv;
		r += bpv;
		while (l < r) {
			if (l & 1) {
				tree[l++].push_back(x);
			}
			if (r & 1) {
				tree[--r].push_back(x);
			}
			l /= 2;
			r /= 2;
		}
	}

	lvls[0][0] = 1;
	dfs(1, 0, bpv, 0);

	vector<int> ans;
	for (int i = 1; i <= n; ++i) {
		if (res[i]) {
			ans.push_back(i);
		}
	}

	cout << szof(ans) << "\n";
	for (int num : ans) {
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