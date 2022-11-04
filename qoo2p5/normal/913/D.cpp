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

const int N = (int) 2e5 + 123;

int n, havet;
vector<pair<int, int>> t[N];
int can[N];

void run() {
	cin >> n >> havet;
	rep(i, 0, n) {
		int a, ti;
		cin >> a >> ti;
		t[a].pb({ti, i});
	}
	int curs = 0;
	multiset<pair<int, int>> have;
	per(i, n, 1) {
		for (const auto &it : t[i]) {
			int x = it.first;
			if (x + curs <= havet) {
				have.insert(it);
				curs += x;
			} else if (sz(have) && have.rbegin()->first	 > x) {
				curs -= have.rbegin()->first;
				have.erase(have.find(*have.rbegin()));
				curs += x;
				have.insert(it);
			}
		}
		can[i] = sz(have);
	}
	
	int ans = -1;
	int best = -1;
	rep(k, 1, n + 1) {
		if (maxi(ans, min(k, can[k]))) best = k;
	}
	cout << ans << "\n";
	multiset<pair<int, int>> take;
	{
		
		int curs = 0;
		multiset<pair<int, int>> have;
		per(i, n, 1) {
			for (const auto &it : t[i]) {
				int x = it.first;
				if (x + curs <= havet) {
					have.insert(it);
					curs += x;
				} else if (sz(have) && have.rbegin()->first > x) {
					curs -= have.rbegin()->first;
					have.erase(have.find(*have.rbegin()));
					curs += x;
					have.insert(it);
				}
			}
			can[i] = sz(have);
			if (i == best) {
				take = have;
				break;
			}
		}
	
	}
	while (sz(take) > best) take.erase(take.begin());
	cout << sz(take) << "\n";
	for (auto &it : take) {
		cout << it.second + 1 << " ";
	}
	cout << "\n";
}