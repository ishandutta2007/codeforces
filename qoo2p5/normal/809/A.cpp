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

const int N = (int) 3e5 + 123;

int n;
ll x[N];

void add(ll &x, ll y) {
    x += y;
    if (x >= MOD) x -= MOD;
    if (x < 0) x += MOD;
}

ll sum(ll x, ll y) {
    add(x, y);
    return x;
}

void run() {
    cin >> n;
    read(x, x + n);
    sort(x, x + n);
    if (n == 1) {
        cout << "0\n";
        return;
    }
    
    ll ans = 0;
    ll cur = sum(x[1], -x[0]);
    ll cnt = 1;
    rep(i, 1, n) {
        add(ans, cur);
        add(cnt, cnt);
        add(cnt, 1);
        add(cur, cur);
        if (i < n - 1) add(cur, cnt * sum(x[i + 1], -x[i]) % MOD);
    }
    cout << ans << "\n";
}