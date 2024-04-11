#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 1e6 + 123;
const ll LINF = (ll) 1e18 + 1e9 + 123;
const ld EPS = (ld) 1e-7;
const ll MOD = (ll) 1e9 + 7;

#define sz(x) (int) (x).size()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lb(s, t, x) (int) (lower_bound(s, t, x) - s)
#define ub(s, t, x) (int) (upper_bound(s, t, x) - s)
#define rep(i, f, t) for (int i = f; i < t; i++)
#define per(i, f, t) for (int i = f; i >= t; i--)

ll power(ll x, ll y, ll mod = MOD) {
    if (y == 0) {
        return 1;
    }
    if (y & 1) {
        return power(x, y - 1, mod) * x % mod;
    } else {
        ll tmp = power(x, y / 2, mod);
        return tmp * tmp % mod;
    }
}

template<typename A, typename B> bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> bool maxi(A &x, const B &y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

void add(ll &x, ll y) {
	x += y;
	if (x >= MOD) x -= MOD;
	if (x < 0) x += MOD;
}

ll mult(ll x, ll y) {
	return x * y % MOD;
}

void run();

#define TASK ""

int main() {
#ifdef LOCAL
    if (strlen(TASK) > 0) {
        cerr << "Reminder: you are using file i/o, filename: " TASK "!" << endl << endl;
    }
#endif
#ifndef LOCAL
    if (strlen(TASK)) {
        freopen(TASK ".in", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    cout << fixed << setprecision(12);
    run();
    return 0;
}

// == SOLUTION == //

const int N = (int) 1e5 + 123;

int n, m;
ll c[N], w[N];
vector<pair<int, int>> g[N];
int col[N];
int st = -1;
vector<pair<int, int>> cycle;

int dfs(int v, int cur = 1) {
	col[v] = cur;
	for (auto &it : g[v]) {
		int u = it.first;
		int nxt = 3 - cur;
		if (!col[u]) {
			int t = dfs(u, nxt);
			if (t == 1) {
				cycle.pb({v, it.second});
				return (v == st ? 2 : 1);
			} else if (t == 2) {
				return 2;
			}
		} else if (col[u] != nxt) {
			st = u;
			cycle.pb({v, it.second});
			return 1;
		}
	}
	
	return 0;
}

void NO() {
	cout << "NO\n";
	exit(0);
}

bool used[N];

void solve(int v, int f = -1) {
	used[v] = 1;
	
	ll have = 0;
	
	for (auto &it : g[v]) {
		int u = it.first;
		int eid = it.second;
		if (used[u]) {
			continue;
		}
		solve(u, eid);
		have += w[eid];
	}
	
	if (f != -1) {
		w[f] = c[v] - have;
	}
}

void run() {
	cin >> n >> m;
	rep(i, 1, n + 1) {
		cin >> c[i];
	}
	rep(i, 0, m) {
		int u, v;
		cin >> u >> v;
		g[u].pb({v, i});
		g[v].pb({u, i});
	}
	
	if (dfs(1)) {
		assert(sz(cycle) >= 2);
		int root = cycle[0].first;
		solve(root);
		ll have = 0;
		for (auto &it : g[root]) {
			have += w[it.second];
		}
		ll x = (c[root] - have) / 2;
		rotate(cycle.begin(), cycle.begin() + 1, cycle.end());
		for (auto &it : cycle) {
			w[it.second] += x;
			x = -x;
		}
		
	} else {
		ll sum[2] = {0, 0};
		rep(i, 1, n + 1) {
			sum[col[i] - 1] += c[i];
		}
		if (sum[0] != sum[1]) {
			NO();
		}
		solve(1);
	}
	
	cout << "YES\n";
	rep(i, 0, m) {
		cout << w[i] << "\n";
	}
}