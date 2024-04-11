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

const int N = (int) 1e6 + 123;
const int A = 'z' - 'a' + 1;

int n;
string s[N];

int ptr = 1;
int go[N][A];

void add(const string &s) {
	int v = 0;
	for (char c : s) {
		if (!go[v][c - 'a']) {
			go[v][c - 'a'] = ptr++;
		}
		v = go[v][c - 'a'];
	}
}

vector<int> g[N];
bool vis[N];
int par[N];

pair<int, bool> dfs(int v) {
	vis[v] = 1;
	int res = 0;
	bool take = 1;
	for (int u : g[v]) {
		assert(!vis[u]);
		auto tmp = dfs(u);
		res += tmp.first;
		take &= !tmp.second;
	}
	if (take) {
		return {res + 1, true};
	} else {
		return {res, false};
	}
}

void solve() {
	cin >> n;
	rep(i, 0, n) {
		cin >> s[i];
		add(s[i]);
	}
	
	rep(i, 0, n) {
		string t = s[i].substr(1);
		int u = go[0][s[i][0] - 'a'];
		int v = 0;
		for (char c : t) {
			if (!go[v][c - 'a']) {
				break;
			}
			v = go[v][c - 'a'];
			u = go[u][c - 'a'];
			g[v].pb(u);
			par[u] = v;
		}
	}
	
	rep(i, 0, ptr) {
		sort(all(g[i]));
		g[i].resize(unique(all(g[i])) - g[i].begin());
	}
	
	int ans = 0;
	
	rep(i, 1, ptr) {
		if (!vis[i]) {
			int v = i;
			while (par[v]) v = par[v];
			ans += dfs(v).first;
		}
	}
	
	cout << ans << "\n";
	
	rep(i, 0, ptr) {
		fill(go[i], go[i] + A, 0);
		g[i].clear();
		vis[i] = 0;
		par[i] = 0;
	}
	ptr = 1;
}

void run() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}