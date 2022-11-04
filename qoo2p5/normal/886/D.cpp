#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
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
const int C = 30;

int n;
string s[N];
unordered_map<char, int> cnt;
vector<int> g[C], h[C];
string ans;
bool used[C];
bool pres[C];

void dfs(int v) {
	used[v] = 1;
	for (int u : g[v]) {
		dfs(u);
	}
	ans += (char) (v + 'a');
}

void run() {
	cin >> n;
	cnt.reserve(100);
	rep(i, 0, n) {
		cin >> s[i];
		cnt.clear();
		for (char c : s[i]) cnt[c]++;
		for (auto &it : cnt) {
			if (it.second > 1) {
				cout << "NO\n";
				return;
			}
		}
		rep(j, 0, sz(s[i]) - 1) {
			g[s[i][j] - 'a'].pb(s[i][j + 1] - 'a');
			h[s[i][j + 1] - 'a'].pb(s[i][j] - 'a');
		}
		for (char c : s[i]) pres[c - 'a'] = 1;
	}
	rep(i, 0, C) {
		sort(all(g[i]));
		g[i].resize(unique(all(g[i])) - g[i].begin());
		sort(all(h[i]));
		h[i].resize(unique(all(h[i])) - h[i].begin());
		if (sz(g[i]) >= 2 || sz(h[i]) >= 2) {
			cout << "NO\n";
			return;
		}
	}
	vector<string> parts;
	rep(i, 0, C) {
		if (used[i] || !pres[i]) {
			continue;
		}
		int steps = 0;
		int v = i;
		while (sz(h[v])) {
			v = h[v][0];
			steps++;
			if (steps > 200) {
				cout << "NO\n";
				return;
			}
		}
		string cur;
		while (1) {
			used[v] = 1;
			cur += (char) (v + 'a');
			if (sz(g[v]) == 0) {
				break;
			}
			v = g[v][0];
			steps++;
			if (steps > 200) {
				cout << "NO\n";
				return;
			}
		}
		parts.pb(cur);
	}
	string ans;
	sort(all(parts));
	for (string t : parts) ans += t;
	cout << ans << "\n";
}