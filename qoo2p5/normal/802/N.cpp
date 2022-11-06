/*

      #     #     #####  #####  #           #  #
     # #   # #    #      #   #  #     #     #  #
    #   # #   #   #####  #   #   #   # #   #   #
   #     #     #  #      #   #    # #   # #     
   #           #  #####  #####     #     #     @

*/

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

const int N = 2202;

int n, k;
int a[N], b[N];

pair<ld, int> dp[N][N];
pair<ld, int> ma[N][N];

pair<ld, int> calc(ld lambda) {
    rep(i, 0, n + 1) rep(j, 0, n + 1) dp[i][j] = {0, 0};
    pair<ld, int> best = {0, 0};
    
    rep(i, 1, n + 1) {
        rep(j, i, n + 1) {
            dp[i][j] = ma[i - 1][j - 1];
            ld tmp = lambda - (a[i] + b[j]);
            if (tmp > 0) {
                dp[i][j].first += tmp;
                dp[i][j].second++;
            }
            maxi(best, dp[i][j]);
            ma[i][j] = dp[i][j];
            maxi(ma[i][j], max(ma[i - 1][j], ma[i][j - 1]));
        }
    }
    
    return best;
}

void run() {
    cin >> n >> k;
    read(a + 1, a + n + 1);
    read(b + 1, b + n + 1);
    
    ld left = 0;
    ld right = 2e9 + 1;
    
    rep(i, 0, 50) {
        ld mid = (left + right) / 2;
        if (calc(mid).second >= k) {
            right = mid;
        } else {
            left = mid;
        }
    }
    
    auto res = calc(right);
    ll cost = (ll) (roundl(-res.first + k * right) + 0.1);
    cout << cost << "\n";
}