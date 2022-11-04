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

int n;

void print(vector<int> &a) {
	for (int x : a) {
		cout << x << " ";
	}
	cout << "\n";
}

bool checkp(vector<int> &a) {
	n = sz(a);
	rep(i, 0, n) {
		if ((a[i] & (i + 1)) != 0 || a[i] == i + 1) {
			return 0;
		}
	}
	return 1;
}

bool checkq(vector<int> &a) {
	n = sz(a);
	rep(i, 0, n) {
		if ((a[i] & (i + 1)) == 0 || a[i] == i + 1) {
			return 0;
		}
	}
	return 1;
}


void solvep(vector<int> &a, vector<int> pos, vector<int> els, int bit) {
	assert(sz(els) == sz(pos));
	if (!sz(els)) {
		return;
	}
	if (sz(els) == 1) {
		a[pos[0] - 1] = els[0];
		return;
	}
	
	vector<int> zero_pos, zero_els;
	vector<int> one_pos, one_els;
	
	for (int x : pos) {
		if (x & (1 << bit)) {
			one_pos.pb(x);
		} else {
			zero_pos.pb(x);
		}
	}
	
	for (int x : els) {
		if (x & (1 << bit)) {
			one_els.pb(x);
		} else {
			zero_els.pb(x);
		}
	}
	
	while (sz(one_pos) < sz(zero_els)) {
		one_pos.pb(zero_pos.back());
		zero_pos.pop_back();
	}
	
	solvep(a, zero_pos, one_els, bit + 1);
	solvep(a, one_pos, zero_els, bit + 1);
};

vector<int> getp(int n) {
	vector<int> a(n);
	rep(i, 0, n) {
		a[i] = i + 1;
	}
	solvep(a, a, a, 0);
	return a;
}

vector<int> getq(int n) {
	if (n <= 7) {
		vector<int> a(n);
		rep(i, 0, n) {
			a[i] = i + 1;
		}
		do {
			if (checkq(a)) {
				return a;
			}
		} while (next_permutation(all(a)));
		assert(0);
		return {};
	} else {
		vector<int> a(7);
		rep(i, 0, 7) {
			a[i] = i + 1;
		}
		do {
			if (checkq(a)) {
				break;
			}
		} while (next_permutation(all(a)));
		
		a.resize(n);
		rep(i, 7, n) {
			a[i] = i + 1;
		}
		int cur = 8;
		int ptr = 7;
		while (ptr < n) {
			int l = ptr;
			int r = min(n, l + cur);
			rotate(a.begin() + l, a.begin() + l + 1, a.begin() + r);
			cur *= 2;
			ptr = r;
		}
		
		return a;
	}
}

void run() {
	cin >> n;
	
	if (n % 2 == 0) {
		auto res = getp(n);
		assert(checkp(res));
		cout << "YES\n";
		print(res);
	} else {
		cout << "NO\n";
	}
	
	int k = 1;
	while (2 * k <= n) {
		k *= 2;
	}
	
	if (n == k || n < 6) {
		cout << "NO\n";
		return;
	}
	
	cout << "YES\n";
	auto res = getq(n);
	assert(checkq(res));
	print(res);
}