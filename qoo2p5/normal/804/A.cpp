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

const int N = (int) 1e5 + 123;

int p[N], rnk[N];

int get(int v) {
    if (p[v] == v) return v;
    return (p[v] = get(p[v]));
}

bool unite(int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v) return 0;
    if (rnk[u] < rnk[v]) swap(u, v);
    if (rnk[u] == rnk[v]) rnk[u]++;
    p[v] = u;
    return 1;
}

int n;

void run() {
    rep(i, 0, N) p[i] = i;
    cin >> n;
    
    int cnt = n;
    int ans = 0;
    
    rep(cost, 0, n + 1) {
        rep(i, 1, n + 1) { 
            int j = n + 1 + cost - i;
            if (1 <= j && j <= n && i != j) {
                if (unite(i, j)) {
                    ans += cost;
                    cnt--;
                }
            }
            j = 2 * (n + 1) + cost - i;
            if (1 <= j && j <= n && i != j) {
                if (unite(i, j)) {
                    ans += cost;
                    cnt--;
                }
            }
        }
        assert(cnt >= 1);
        if (cnt == 1) break;
    }
    
    cout << ans << "\n";
}