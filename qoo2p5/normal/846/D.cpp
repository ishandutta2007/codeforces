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

inline void add(ll &x, ll y, ll mod = MOD) {
    x += y;
    if (x >= mod) x -= mod;
    if (x < 0) x += mod;
}

inline ll sum(ll x, ll y, ll mod = MOD) {
    add(x, y, mod);
    return x;
}

inline ll mult(ll x, ll y, ll mod = MOD) {
    return (x * y) % mod;
}

inline ll div(ll x, ll y, ll mod) {
    return x * power(y, mod - 2, mod);
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

const int N = 505;
const int M = N * N;

int n, m, k, cnt_q;
struct Q {
    int x, y, t;
    bool operator<(const Q &o) const {
        return t < o.t;
    }
};
Q q[M];
int p[N][N];

int get(int x1, int y1, int x2, int y2) {
    return p[x2][y2] - p[x2][y1 - 1] - p[x1 - 1][y2] + p[x1 - 1][y1 - 1];
}

bool check(int cnt) {
    memset(p, 0, sizeof p);
    rep(i, 0, cnt) {
        p[q[i].x][q[i].y]++;
    }
    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
            p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
        }
    }
    rep(i, k, n + 1) {
        rep(j, k, m + 1) {
            if (get(i - k + 1, j - k + 1, i, j) == k * k) {
                return 1;
            }
        }
    }
    return 0;
}

void run() {
    cin >> n >> m >> k >> cnt_q;
    rep(i, 0, cnt_q) {
        cin >> q[i].x >> q[i].y >> q[i].t;
    }
    sort(q, q + cnt_q);
    int left = 0;
    int right = cnt_q + 1;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << (right == cnt_q + 1 ? -1 : q[right - 1].t) << "\n";
}