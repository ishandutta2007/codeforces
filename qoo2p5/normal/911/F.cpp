#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 2e9 + 123;
const ll LINF = (ll) 1e18 + 123;
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

const int N = (int) 2e5 + 123;

int n;
vector<int> g[N];
bool in_diam[N];

pair<int, int> farest(int v, int from = -1) {
	pair<int, int> res = {0, v};
	for (int u : g[v]) {
		if (u == from) {
			continue;
		}
		auto tmp = farest(u, v);
		tmp.first++;
		maxi(res, tmp);
	}
	return res;
}

int d1, d2;
vector<int> path;

bool dfs(int v, int from = -1) {
	path.pb(v);
	if (v == d2) {
		return 1;
	}
	for (int u : g[v]) {
		if (u == from) {
			continue;
		}
		if (dfs(u, v)) {
			return 1;
		}
	}
	path.pop_back();
	return 0;
}

struct Q {
	int a, b, c;
};
	
ll ans = 0;
vector<Q> res;
int what_diam;

void go(int v, int cur_len, int from = -1) {
	for (int u : g[v]) {
		if (u == from) {
			continue;
		}
		go(u, cur_len + 1, v);
	}
	ans += cur_len;
	res.pb({v, what_diam, v});
}

void run() {
	cin >> n;
	rep(i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	d1 = farest(1).second;
	d2 = farest(d1).second;
	dfs(d1);
	
	for (int v : path) {
		in_diam[v] = 1;
	}
	
	rep(i, 0, sz(path)) {
		int v = path[i];
		int len = max(i, sz(path) - i - 1);
		for (int u : g[v]) {
			if (in_diam[u]) {
				continue;
			}
			if (i > sz(path) - i - 1) {
				what_diam = d1;
			} else {
				what_diam = d2;
			}
			go(u, len + 1, v);
		}
	}
	
	rep(i, 0, sz(path) - 1) {
		ans += sz(path) - 1 - i;
		res.pb({path[i], d2, path[i]});
	}
	
	cout << ans << "\n";
	for (auto &it : res) {
		cout << it.a << " " << it.b << " " << it.c << "\n";
	}
}