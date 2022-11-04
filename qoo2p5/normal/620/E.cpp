#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

#ifdef DEBUG
	#define debug(x) cerr << "\033[31m" << x << "\033[39m" << endl;
#else
	#define debug(x)
#endif

const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-10;
const ld PI = 3.141592653589;

#define TASKNAME ""

const int N = 4e5;

class SegmentTree {
private:
	int n;
	vector<ll> tree;
	vector<ll> flag;

	int round_p2(int x) {
		int y = 1;
		while (y < x) {
			y *= 2;
		}

		return y;
	}

	void push(int i) {
		if (flag[i]) {
			if (i * 2 + 2 < 2 * n) {
				flag[2 * i + 1] = flag[i];
				flag[2 * i + 2] = flag[i];
			}

			tree[i] = flag[i];
			flag[i] = 0;
		}
	}

	ll get(int i, int tl, int tr, int l, int r) {
		push(i);
		if (tl >= r || tr <= l) {
			return 0;
		}

		if (l <= tl && tr <= r) {
			return tree[i];
		}

		int tm = (tl + tr) / 2;
		return get(2 * i + 1, tl, tm, l, r) | get(2 * i + 2, tm, tr, l, r);
	}

	void set(int i, int tl, int tr, int l, int r, ll value) {
		push(i);
		if (tl >= r || tr <= l) {
			return;
		}

		if (l <= tl && tr <= r) {
			flag[i] = value;
			push(i);
			return;
		}

		int tm = (tl + tr) / 2;
		set(2 * i + 1, tl, tm, l, r, value);
		set(2 * i + 2, tm, tr, l, r, value);
		tree[i] = tree[2 * i + 1] | tree[2 * i + 2];
	}

public:
	SegmentTree(const vector<ll> &arr) {
		n = round_p2(sz(arr));
		tree.resize(2 * n);
		flag.resize(2 * n);

		for (int i = n - 1; i < n - 1 + sz(arr); i++) {
			int j = i - (n - 1);
			tree[i] = arr[j];
		}

		for (int i = n - 2; i >= 0; i--) {
			tree[i] = tree[2 * i + 1] | tree[2 * i + 2];
		}
	}

	ll get(int l, int r) {
		return get(0, 0, n, l, r + 1);
	}

	void set(int l, int r, ll value) {
		set(0, 0, n, l, r + 1, value);
	}
};

int n, m;
int color[N];
vector<int> g[N];
int ind[N][2];
vector<ll> arr;

void dfs(int v, int root = -1) {
	ind[v][0] = sz(arr);
	arr.pb(color[v]);

	for (int to : g[v]) {
		if (to == root) {
			continue;
		}

		dfs(to, v);
	}

	ind[v][1] = sz(arr) - 1;
}

int main() {
	ios::sync_with_stdio(false);
	float tbegin = clock();
	srand(42);

#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#else
	if (TASKNAME != "") {
		freopen(TASKNAME ".in", "r", stdin);
		freopen(TASKNAME ".out", "w", stdout);
	}
#endif

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> color[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x].pb(y);
		g[y].pb(x);
	}

	arr.reserve(n);

	dfs(0);
	for (ll &i : arr) {
		i = 1LL << i;
	}

	SegmentTree tree(arr);

	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;

		if (t == 1) {
			int v, c;
			cin >> v >> c;
			v--;

			tree.set(ind[v][0], ind[v][1], 1LL << c);
		} else if (t == 2) {
			int v;
			cin >> v;
			v--;

			ll mask = tree.get(ind[v][0], ind[v][1]);
			int ans = 0;
			for (int bit = 0; bit <= 63; bit++) {
				if (mask & (1LL << bit)) {
					ans++;
				}
			}

			cout << ans << "\n";
		}
	}

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}