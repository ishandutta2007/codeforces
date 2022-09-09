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

struct node {
	int l, r;
	int cnt;
	node() : l(-1), r(-1), cnt(0) {}
	node(int _l, int _r) : l(_l), r(_r), cnt(0) {}

	int operator[](int ind) {
		if (ind == 0) {
			return l;
		}
		return r;
	}

	void set(int ind, int val) {
		if (ind == 0) {
			l = val;
		} else {
			r = val;
		}
	}
};

vector<node> tree;

int add_node() {
	tree.push_back(node());
	return szof(tree) - 1;
}

void solve() {
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	vector<int> arrp;
	int root = add_node();
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arrp.push_back(num);
		int cur = 0;
		for (int j = 29; j >= 0; --j) {
			//cerr << cur << endl;
			tree[cur].cnt++;
			int d = (bool) (num & (1 << j));
			if (tree[cur][d] == -1) {
				tree[cur].set(d, add_node());
			}
			cur = tree[cur][d];
		}
		tree[cur].cnt++;
	}
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		//cerr << i << endl;
		int cur = 0;
		int res = 0;
		tree[cur].cnt--;
		for (int j = 29; j >= 0; --j) {
			int d = (bool) (arr[i] & (1 << j));
			int nd = d;
			if (tree[cur][d] == -1) {
				nd = 1 - d;
			}

			res |= (d ^ nd) << j;
			d = nd;

			int tmp = tree[cur][d];
			tree[tmp].cnt--;
			if (!tree[tmp].cnt) {
				tree[cur].set(d, -1);
			}
			cur = tmp;
		}

		ans.push_back(res);
	}

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