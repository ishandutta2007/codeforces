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

void add(ll &x, ll y, ll mod = MOD) {
    x += y;
    if (x >= mod) x -= mod;
    if (x < 0) x += mod;
}

ll sum(ll x, ll y, ll mod = MOD) {
    add(x, y, mod);
    return x;
}

ll mult(ll x, ll y, ll mod = MOD) {
    return (x * y) % mod;
}

ll div(ll x, ll y, ll mod) {
    return x * power(y, mod - 2, mod);
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

template<typename T> void read(T first, T last) {
    while (first != last) {
        cin >> *(first++);
    }
}

template<typename T> void print(T first, T last) {
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
    cout << fixed << setprecision(10);
    run();
    return 0;
}

// == SOLUTION == //

const int N = (int) 1e6 + 123;

struct {
	ll best = LINF;
	ll a, b, x;
} ans;

void run() {
	ll n, k;
	cin >> n >> k;
	
	for (ll x = 1; x <= n; x++) {
		for (ll a = 0; a * x <= n - 1; a++) {
			ll rest = n - 1 - a * x;
			if (rest % (x + 1) != 0) continue;
			ll b = rest / (x + 1);
			if (a + b != k) {
				continue;
			}
			ll cur = 0;
			if (a >= 1) {
				maxi(cur, x);
			}
			if (b >= 1) {
				maxi(cur, x + 1);
			}
			if (a >= 2) {
				maxi(cur, 2 * x);
			}
			if (b >= 2) {
				maxi(cur, 2 * (x + 1));
			}
			if (a >= 1 && b >= 1) {
				maxi(cur, x + (x + 1));
			}
			
			if (mini(ans.best, cur)) {
				ans.a = a;
				ans.b = b;
				ans.x = x;
			}
		}
	}
	
	assert(ans.best != LINF);
	cout << ans.best << "\n";
	ll v = 2;
	rep(i, 0, ans.a) {
		cout << 1 << " " << v << "\n";
		rep(j, 0, ans.x - 1) {
			cout << v + j << " " << v + j + 1 << "\n";
		}
		v += ans.x;
	}
	rep(i, 0, ans.b) {
		cout << 1 << " " << v << "\n";
		rep(j, 0, ans.x) {
			cout << v + j << " " << v + j + 1 << "\n";
		}
		v += ans.x + 1;
	}
	assert(v == n + 1);
}