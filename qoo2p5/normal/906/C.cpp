#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const int INF = (int) 1e9 + 1e6;
const ll LINF = (ll) 1e18 + 1e9;
const ld EPS = (ld) 1e-10;
const ll MOD = (ll) 1e9 + 7;

#define sz(x) (int) (x).size()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lb(s, t, x) (int) (lower_bound(s, t, x) - s)
#define ub(s, t, x) (int) (upper_bound(s, t, x) - s)
#define rep(i, f, t) for (auto i = f; i < t; ++(i))
#define per(i, f, t) for (auto i = (f); i >= (t); --(i))

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

const int N = 23;

int n, m;
int know[N];
int dp[1 << N];
int from[1 << N];

void run() {
    cin >> n >> m;
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        know[u] |= (1 << v);
        know[v] |= (1 << u);
    }
    
    bool ok = 1;
    
    rep(i, 0, n) {
        know[i] |= (1 << i);
        ok &= (know[i] == ((1 << n) - 1));
    }
    
    if (ok) {
        cout << "0\n";
        return;
    }
    
    int ans = INF;
    int best = -1;
    rep(i, 0, n) {
        dp[1 << i] = know[i];
        from[1 << i] = i;
    }
    rep(mask, 0, 1 << n) {
        if (!dp[mask]) continue;
        int cnt = 0;
        rep(bit, 0, n) if (mask & (1 << bit)) cnt++;
        if (cnt == 0) {
            continue;
        }
        rep(to, 0, n) {
            if (mask & (1 << to)) {
                continue;
            }
            if (!(know[to] & mask)) {
                continue;
            }
            
            if (dp[mask ^ (1 << to)] == 0) {
                dp[mask ^ (1 << to)] = dp[mask] | know[to];
                from[mask ^ (1 << to)] = to;
            }
        }
        
        if (dp[mask] == (1 << n) - 1) {
            if (mini(ans, cnt)) {
                best = mask;
            }
        }
    }
    
    assert(best != -1);
    cout << ans << "\n";
    vector<int> what;
    while (best > 0) {
        what.pb(from[best]);
        assert(best & (1 << from[best]));
        best ^= (1 << from[best]);
    }
    reverse(all(what));
    for (int v : what) {
        cout << v + 1 << " ";
    }
    cout << "\n";
}