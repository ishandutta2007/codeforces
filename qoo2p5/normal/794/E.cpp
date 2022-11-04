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
const ld EPS = (ld) 1e-8;
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

const int N = (int) 3e5 + 123;

int n;
int a[N], b[N], ans[N];

void run() {
    cin >> n;
    read(a, a + n);
    
    if (n == 1) {
        cout << a[0] << "\n";
        return;
    }
    
    rep(i, 1, n - 1) b[i] = min(a[i], max(a[i - 1], a[i + 1]));
    ans[n - 1] = *max_element(a, a + n);
    
    if (n % 2 == 0) {
        int cur = 0;
        for (int i = 0; i < n - 1; i += 2) {
            maxi(cur, max(a[n / 2 - i / 2 - 1], a[n / 2 + i / 2]));
            ans[i] = cur;
        }
        
        cur = 0;
        for (int i = 1; i < n - 1; i += 2) {
            maxi(cur, max(b[n / 2 - i / 2 - 1], b[n / 2 + i / 2]));
            ans[i] = cur;
        }
    } else {
        int cur = 0;
        for (int i = 0; i < n - 1; i += 2) {
            maxi(cur, max(b[n / 2 - i / 2], b[n / 2 + i / 2]));
            ans[i] = cur;
        }
        
        cur = a[n / 2];
        for (int i = 1; i < n - 1; i += 2) {
            maxi(cur, max(a[n / 2 - i / 2 - 1], a[n / 2 + i / 2 + 1]));
            ans[i] = cur;
        }
    }
    
    print(ans, ans + n);
}