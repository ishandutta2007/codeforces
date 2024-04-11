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

const int N = 1 << 19;

int n, q;
int tree[2 * N];

int leftmost(int i, int tl, int tr, int l, int r, int x) {
	if (tr <= l || tl >= r) {
		return N;
	}
	int tm = (tl + tr) / 2;
	if (l <= tl && tr <= r) {
		if (tree[i] % x == 0) {
			return N;
		}
		if (tl == tr - 1) {
			return tl;
		}
		if (tree[2 * i] % x == 0) {
			return leftmost(2 * i + 1, tm, tr, l, r, x);
		} else {
			return leftmost(2 * i, tl, tm, l, r, x);
		}
	}
	
	int q = leftmost(2 * i, tl, tm, l, r, x);
	if (q != N) {
		return q;
	}
	return leftmost(2 * i + 1, tm, tr, l, r, x);
}

int leftmost(int l, int r, int x) {
	return leftmost(1, 0, N, l, r + 1, x);
}

int rightmost(int i, int tl, int tr, int l, int r, int x) {
	if (tr <= l || tl >= r) {
		return -1;
	}
	int tm = (tl + tr) / 2;
	if (l <= tl && tr <= r) {
		if (tree[i] % x == 0) {
			return -1;
		}
		if (tl == tr - 1) {
			return tl;
		}
		if (tree[2 * i + 1] % x == 0) {
			return rightmost(2 * i, tl, tm, l, r, x);
		} else {
			return rightmost(2 * i + 1, tm, tr, l, r, x);
		}
	}
	
	int q = rightmost(2 * i + 1, tm, tr, l, r, x);
	if (q != -1) {
		return q;
	}
	return rightmost(2 * i, tl, tm, l, r, x);
}

int rightmost(int l, int r, int x) {
	return rightmost(1, 0, N, l, r + 1, x);
}

void run() {
	cin >> n;
	rep(i, 0, n) {
		cin >> tree[N + i];
	}
	per(i, N - 1, 1) {
		tree[i] = __gcd(tree[2 * i], tree[2 * i + 1]);
	}
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			l--; r--;
			int L = leftmost(l, r, x);
			int R = rightmost(l, r, x);
			cout << (L >= R ? "YES\n" : "NO\n");
		} else {
			int ind, y;
			cin >> ind >> y;
			ind--;
			tree[N + ind] = y;
			int v = (N + ind) / 2;
			while (v > 0) {
				tree[v] = __gcd(tree[2 * v], tree[2 * v + 1]);
				v /= 2;
			}
		}
	}
}