#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (ll) x.size()
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

#ifdef DEBUG
	#define debug(x) cerr << "\033[31m" << x << "\033[39m" << endl;
#else
	#define debug(x)
#endif

const ll INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const ld PI = 3.141592653589;
const ll MOD = 1e9 + 7;

#define TASKNAME ""

const int N = 4e5 + 123;

int n;
int ans[N];
int l[N];
int r[N];
int tree[N];

void add(int i, int v) {
	for (; i <= 2 * n; i += i & (-i)) {
		tree[i] += v;
	}
}

int get(int r) {
	int res = 0;
	for (; r > 0; r -= r & (-r)) {
		res += tree[r];
	}
	return res;
}

int get(int l, int r) {
	return get(r) - get(l - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
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

	cin >> n;
	vector<pair<int, int>> a;
	for (int i = 1; i <= n; i++) {
		int l, r;
		cin >> l >> r;
		a.pb(mp(l, -i));
		a.pb(mp(r, i));
	}
	sort(a.begin(), a.end());

	for (int i = 1; i <= 2 * n; i++) {
		if (a[i - 1].second < 0) {
			l[-a[i - 1].second] = i;
		} else {
			r[a[i - 1].second] = i;
		}
	}

	vector<pair<int, int>> events;

	for (int i = 1; i <= n; i++) {
		events.pb(mp(l[i], i));
	}

	sort(events.begin(), events.end());

	for (int i = 1; i <= n; i++) {
		add(r[i], 1);
	}

	int cnt = n;

	for (auto &e : events) {
		int i = e.second;
		add(r[i], -1);
		cnt--;
		debug(cnt << " " << get(r[i], 2 * n));
		ans[i] = cnt - get(r[i], 2 * n);
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << "\n";
	}

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}