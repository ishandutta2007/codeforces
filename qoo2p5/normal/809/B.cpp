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

int n, k;

bool ask(int x, int y) {
    cout << "1 " << x << " " << y << endl;
    string res;
    cin >> res;
    return res == "TAK";
}

int solve(int l, int r) {
    if (l > r) {
        return -1;
    }
    if (l == r) {
        return l;
    }
    
    int m = (l + r) / 2;
    if (ask(m, m + 1)) {
        return solve(l, m);
    } else {
        return solve(m + 1, r);
    }
}

bool check(int pos) {
    if (pos == -1) {
        return 0;
    }
    if (pos == 1) {
        return ask(1, 2);
    } else if (pos == n) {
        return ask(n, n - 1);
    } else {
        return ask(pos, pos - 1) && ask(pos, pos + 1);
    }
}

void run() {
    cin >> n >> k;
    int a = solve(1, n);
    int b = solve(1, a - 1);
    int c = solve(a + 1, n);
    bool ok_b = check(b);
    bool ok_c = check(c);
    assert(ok_b || ok_c);
    if (ok_b) {
        cout << "2 " << a << " " << b << endl;
    } else {
        cout << "2 " << a << " " << c << endl;
    }
}