#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const ld EPS = (ld) 1e-12;
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
    cout << fixed << setprecision(12);
    run();
    return 0;
}

// == SOLUTION == //

const int N = 305;

int n;
int cnt[N];
ll fact[N], rfact[N];
ll dp[N][N];

ll cnk(int n, int k) {
    if (k > n) return 0;
    assert(n >= 0 && k >= 0);
    return mult(fact[n], mult(rfact[n - k], rfact[k]));
}

map<int, int> factorize(int x) {
    map<int, int> res;
    for (int d = 2; d * d <= x; d++) {
        while (x % d == 0) {
            x /= d;
            res[d]++;
        }
    }
    if (x > 1) res[x]++;
    return res;
}

void run() {
    fact[0] = 1;
    rfact[0] = 1;
    rep(i, 1, N) {
        fact[i] = mult(fact[i - 1], i);
        rfact[i] = power(fact[i], MOD - 2);
    }
    
    {
        int k;
        cin >> k;
        map<int, int> q;
        rep(i, 0, k) {
            int x;
            cin >> x;
            auto tmp = factorize(x);
            int y = 1;
            for (auto &it : tmp) {
                if (it.second & 1) y *= it.first;
            }
            q[y]++;
        }
        for (auto &it : q) {
            cnt[n++] = it.second;
        }
    }
    
    dp[0][0] = 1;
    int s = 0;
    rep(i, 0, n) {
        rep(j, 0, s + 1) {
            rep(k, 1, min(s + 1, cnt[i]) + 1) {
                rep(t, 0, min(k, j) + 1) {
                    add(dp[i + 1][j - t + cnt[i] - k], mult(dp[i][j], mult(cnk(cnt[i] - 1, k - 1), mult(cnk(s + 1 - j, k - t), cnk(j, t)))));
                }
            }
        }
        
        s += cnt[i];
    }
    
    ll ans = dp[n][0];
    rep(i, 0, n) ans = mult(ans, fact[cnt[i]]);
    cout << ans << "\n";
}