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

const int N = 3000;

int n, m;
int a[N], b[N];
ll sa, sb;

ll best_v;
vector<pair<int, int>> ans_i;

void better(int i, int j, pair<ll, pair<int, int>> el) {
	ll s = a[i] + a[j];
	ll v = abs((sa - s + el.first) - (sb + s - el.first));
	if (v < best_v) {
		best_v = v;
		ans_i.clear();
		ans_i.pb(mp(i, el.second.first));
		ans_i.pb(mp(j, el.second.second));
	}
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

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sa += a[i];
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		sb += b[i];
	}

	best_v = abs(sa - sb);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ll v = abs((sa - a[i] + b[j]) - (sb - b[j] + a[i]));
			if (v < best_v) {
				best_v = v;
				ans_i.clear();
				ans_i.pb(mp(i, j));
			}
		}
	}

	vector<pair<ll, pair<int, int>>> q;

	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			q.pb(mp(b[i] + b[j], mp(i, j)));
		}
	}

	sort(q.begin(), q.end());

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ll s = a[i] + a[j];
			ll t = (sb - sa + 2 * s) / 2;

			{
				int k = lower_bound(q.begin(), q.end(), mp(t, mp(-1, -1))) - q.begin();

				if (k < sz(q)) {
					better(i, j, q[k]);
				}

				if (k > 0) {
					better(i, j, q[k - 1]);
				}
			}

			{
				int k = lower_bound(q.begin(), q.end(), mp(t + 1, mp(-1, -1))) - q.begin();

				if (k < sz(q)) {
					better(i, j, q[k]);
				}
			}
		}
	}

	cout << best_v << "\n";
	cout << sz(ans_i) << "\n";
	for (auto it : ans_i) {
		cout << it.first + 1 << " " << it.second + 1 << "\n";
	}

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}