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
#define pb(x) push_back((x))
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

const int N = 85;

int n, k, m;
vector<pair<int, int>> g[N];
int dp[N][N][N][2]; // (l; r; k; type)

void run() {
    cin >> n >> k >> m;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        g[u].pb(mp(v, c));
    }
    
    rep(i, 0, N) rep(j, 0, N) rep(t, 0, N) dp[i][j][t][0] = dp[i][j][t][1] = INF;
    
    for (int len = 1; len <= n; len++) {
        for (int l = 0; l < n - len + 1; l++) {
            int r = l + len;
            dp[l][r][1][0] = dp[l][r][1][1] = 0;
            
            for (int k = 2; k < N; k++) {
                for (auto &e : g[l]) {
                    int to = e.first;
                    int cost = e.second;
                    if (l < to && to < r) {
                        mini(dp[l][r][k][0], dp[to][r][k - 1][0] + cost);
                        mini(dp[l][r][k][0], dp[l + 1][to + 1][k - 1][1] + cost);
                    }
                }
                for (auto &e : g[r - 1]) {
                    int to = e.first;
                    int cost = e.second;
                    if (l <= to && to < r - 1) {
                        mini(dp[l][r][k][1], dp[l][to + 1][k - 1][1] + cost);
                        mini(dp[l][r][k][1], dp[to][r - 1][k - 1][0] + cost);
                    }
                }
            }
        }
    }
    
    int ans = INF;
    rep(l, 0, n) rep(r, l + 1, n + 1) mini(ans, min(dp[l][r][k][0], dp[l][r][k][1]));
    cout << (ans == INF ? -1 : ans) << "\n";
}