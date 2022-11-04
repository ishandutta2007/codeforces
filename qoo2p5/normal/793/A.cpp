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
    cout << fixed << setprecision(12);
#endif
    run();
    return 0;
}

// == SOLUTION == //

const int N = (int) 1e5 + 123;

int n, k;
int a[N];

void run() {
    cin >> n >> k;
    read(a, a + n);
    for (int i = 0; i < n - 1; i++) {
        if (a[i] % k != a[i + 1] % k) {
            cout << "-1\n";
            return;
        }
    }
    int t = *min_element(a, a + n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (a[i] - t) / k;
    }
    cout << ans << "\n";
}