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

const int N = 1005;

ll dp[N][N][2];
string s;
int k;

bool ok(int bits) {
	if (k == 1) {
		return bits == 1;
	}
	
	rep(i, 0, k - 1) {
		if (bits == 1) {
			return 0;
		}
		bits = __builtin_popcount(bits);
	}
	return bits == 1;
}

void run() {
	cin >> s >> k;
	if (k == 0) {
		cout << "1\n";
		return;
	}
	dp[0][0][1] = 1;
	rep(i, 0, sz(s)) {
		rep(j, 0, N) {
			add(dp[i + 1][j + (s[i] == '1')][1], dp[i][j][1]);
			if (s[i] == '1') {
				add(dp[i + 1][j][0], dp[i][j][1]);
			}
			rep(t, 0, 2) {
				add(dp[i + 1][j + t][0], dp[i][j][0]);
			}
		}
	}
	ll ans = 0;
	rep(cnt, 0, N) {
		if (!ok(cnt)) continue;
		add(ans, dp[sz(s)][cnt][0]);
		add(ans, dp[sz(s)][cnt][1]);
	}
	if (k == 1) add(ans, -1);
	cout << ans << "\n";
}