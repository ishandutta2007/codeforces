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

void add(ll &x, ll y) {
	x += y;
	if (x >= MOD) x -= MOD;
	if (x < 0) x += MOD;
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

int n, k;
ll fact[N];
ll rfact[N];

ll cnk(int n, int k) {
	if (k > n) {
		return 0;
	}
	return fact[n] * rfact[k] % MOD * rfact[n - k] % MOD;
}

ll dp[N], us[N];
//ll pref[N];

void run() {
	fact[0] = 1;
	rep(i, 1, N) {
		fact[i] = fact[i - 1] * i % MOD;
	}
	rep(i, 0, N) {
		rfact[i] = power(fact[i], MOD - 2);
	}
	
	cin >> n >> k;
	
	rep(i, k + 1, n + 1) {
		us[i] = fact[i - 1];
		add(us[i], -(dp[i - k - 1] * cnk(i - 1, k) % MOD * fact[k] % MOD));
		dp[i] = us[i];
		add(dp[i], dp[i - 1] * i % MOD);
	}
	
	ll ans = 0;
	rep(i, 1, n + 1) {
		add(ans, dp[i - 1] * cnk(n - 1, i - 1) % MOD * fact[n - i] % MOD);
	}
	
	cout << ans << "\n";
}