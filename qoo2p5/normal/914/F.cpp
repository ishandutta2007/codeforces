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
const int A = 'z' - 'a' + 1;

string s;
int n, q;
bitset<N> has[A];

void run() {
	cin >> s >> q;
	n = sz(s);
	rep(i, 0, n) {
		has[s[i] - 'a'][i] = 1;
	}
	bitset<N> full, ans;
	rep(i, 0, n) {
		full[i] = 1;
	}
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int ind;
			char c;
			cin >> ind >> c;
			ind--;
			int from = s[ind] - 'a';
			int to = c - 'a';
			has[from][ind] = 0;
			has[to][ind] = 1;
			s[ind] = c;
		} else {
			int l, r;
			string t;
			cin >> l >> r >> t;
			l--; r--;
			r -= sz(t) - 1;
			if (l > r) {
				cout << "0\n";
				continue;
			}
			ans = full;
			rep(i, 0, sz(t)) {
				ans &= (has[t[i] - 'a'] >> i);
			}
			
			ans >>= l;
			int res = ans.count();
			ans >>= (r - l + 1);
			res -= ans.count();
			cout << res << "\n";
		}
	}
}