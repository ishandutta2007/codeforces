#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const ld EPS = (ld) 1e-8;
const ll MOD = (ll) 1e9 + 7;

#define sz(x) (int) (x).size()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lb(s, t, x) (int) (lower_bound(s, t, x) - s)
#define ub(s, t, x) (int) (upper_bound(s, t, x) - s)
#define rep(i, f, t) for (auto i = f; i < t; i++)
#define per(i, f, t) for (auto i = f; i >= t; i--)

ll power(ll x, ll y, ll mod) {
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

inline void add(ll &x, ll y, ll mod) {
    x += y;
    if (x >= mod) x -= mod;
    if (x < 0) x += mod;
}

inline ll sum(ll x, ll y, ll mod) {
    add(x, y, mod);
    return x;
}

template<typename A, typename B> inline bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> inline bool maxi(A &x, const B &y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

template<typename T> inline void read(T first, T last) {
    while (first != last) {
        cin >> *(first++);
    }
}

template<typename T> inline void print(T first, T last) {
    while (first != last) {
        cout << *(first++) << " ";
    }
    cout << "\n";
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
    cout << fixed << setprecision(15);
    run();
    return 0;
}

// == SOLUTION == //

const int N = 128;

int k, n;
ld win[N][N];
ld prob[N][N][N], dp[N][N][N];

void calc(int l, int r, int lev) {
    if (l == r - 1) {
        prob[l][r][l] = 1;
        return;
    }
    int m = (l + r) / 2;
    calc(l, m, lev - 1);
    calc(m, r, lev - 1);
    
    rep(i, l, m) {
        rep(j, m, r) {
            prob[l][r][i] += prob[l][m][i] * prob[m][r][j] * win[i][j];
        }
    }
    rep(i, m, r) {
        rep(j, l, m) {
            prob[l][r][i] += prob[m][r][i] * prob[l][m][j] * win[i][j];
        }
    }
    rep(i, l, m) {
		rep(j, m, r) {
			maxi(dp[l][r][i], dp[m][r][j]);
		}
		dp[l][r][i] += dp[l][m][i] + prob[l][r][i] * (1 << lev);
	}
	rep(i, m, r) {
		rep(j, l, m) {
			maxi(dp[l][r][i], dp[l][m][j]);
		}
		dp[l][r][i] += dp[m][r][i] + prob[l][r][i] * (1 << lev);
	}
}

void run() {
    cin >> k;
    n = (1 << k);
    rep(i, 0, n) {
        rep(j, 0, n) {
            cin >> win[i][j];
            win[i][j] /= 100;
        }
    }
    calc(0, n, k - 1);
    ld ans = 0;
    rep(i, 0, n) maxi(ans, dp[0][n][i]);
    cout << ans << "\n";
}