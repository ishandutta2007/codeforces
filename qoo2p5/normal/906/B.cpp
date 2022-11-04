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

mt19937 rnd(42);

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int a[20][20];
set<int> w[100];

void stupid(int n, int m) {
	int ptr = 1;
	rep(i, 0, n) {
		rep(j, 0, m) {
			a[i][j] = ptr++;
		}
	}
	
	rep(i, 0, n) {
		rep(j, 0, m) {
			rep(dir, 0, 4) {
				int ni = i + dx[dir];
				int nj = j + dy[dir];
				if (min(ni, nj) >= 0 && ni < n && nj < m) {
					w[a[i][j]].insert(a[ni][nj]);
				}
			}
		}
	}
	
	auto check = [&] () {
		rep(i, 0, n) {
			rep(j, 0, m) {
				rep(dir, 0, 4) {
					int ni = i + dx[dir];
					int nj = j + dy[dir];
					if (min(ni, nj) >= 0 && ni < n && nj < m) {
						if (w[a[i][j]].count(a[ni][nj])) {
							return 0;
						}
					}
				}
			}
		}
		return 1;
	};
	
	vector<int> nums(n * m);
	rep(i, 0, n * m) {
		nums[i] = i + 1;
	}
	
	rep(iter, 0, 500000) {
		shuffle(all(nums), rnd);
		int ptr = 0;
		rep(i, 0, n) {
			rep(j, 0, m) {
				a[i][j] = nums[ptr++];
			}
		}
		if (check()) {
			cout << "YES\n";
			rep(i, 0, n) {
				rep(j, 0, m) {
					cout << a[i][j] << " ";
				}
				cout << "\n";
			}
			return;
		}
	}
	
	cout << "NO\n";
}

void construct(int n, int m) {
	cout << "YES\n";	
	if (n >= 5) {
		int ptr = 1;
		vector<vector<int>> res(n, vector<int>(m));
		rep(i, 0, n) {
			rep(j, 0, m) {
				res[i][j] = ptr++;
			}
		}
		rep(i, 0, m) {
			vector<int> a, b;
			rep(j, 0, n) {
				int cur = res[j][i];
				if (j & 1) {
					a.pb(cur);
				} else {
					b.pb(cur);
				}
			}
			if (i & 1) {
				swap(a, b);
			}
			for (int x : b) a.pb(x);
			rep(j, 0, n) {
				res[j][i] = a[j];
			}
		}
		rep(i, 0, n) {
			rep(j, 0, m) {
				cout << res[i][j] << " ";
			}
			cout << "\n";
		}
	} else if (m >= 5) {
		int ptr = 1;
		rep(i, 0, n) {
			vector<int> a, b;
			rep(j, 0, m) {
				int cur = ptr++;
				if (j & 1) {
					a.pb(cur);
				} else {
					b.pb(cur);
				}
			}
			if (i & 1) {
				swap(a, b);
			}
			for (int x : a) {
				cout << x << " ";
			}
			for (int x : b) {
				cout << x << " ";
			}
			cout << "\n";
		}
	} else {
		assert(0);
	}
}

void run() {
	int n, m;
	cin >> n >> m;
	if (max(n, m) <= 4) {
		stupid(n, m);
	} else {
		construct(n, m);
	}
}