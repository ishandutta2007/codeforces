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

const int N = 3e5 + 123;

int n, m;
int pos[N];
vector<int> to[N];

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

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pos[x] = i;
	}

	set<pair<int, int>> q;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		int p1 = pos[a];
		int p2 = pos[b];
		if (p1 > p2) swap(p1, p2);
		to[p1].pb(p2);
	}

	int j = 0;
	ll ans = 0;
	for (int k : to[0]) {
		q.insert(mp(k, 0));
	}
	int cur_min = sz(q) ? q.begin()->first : INF;
	for (int i = 0; i < n; i++) {
		for (int k : to[i]) {
			q.insert(mp(k, i));
		}
		cur_min = sz(q) ? q.begin()->first : INF;

		j = max(j, i);
		while (j + 1 < n && j + 1 < cur_min) {
			for (int k : to[j + 1]) {
				q.insert(mp(k, j + 1));
			}
			cur_min = sz(q) ? q.begin()->first : INF;
			j++;
		}

		debug(i << "  "<< j << " " << cur_min);

		ans += j - i + 1;

		for (int k : to[i]) {
			auto el = mp(k, i);
			if (q.count(el)) {
				q.erase(el);
			}
		}

		cur_min = sz(q) ? q.begin()->first : INF;
	}

	cout << ans << endl;

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}