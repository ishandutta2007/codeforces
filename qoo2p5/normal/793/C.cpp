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

const int N = (int) 1e5 + 123;

int n;

void NO() {
    cout << "-1\n";
    exit(0);
}

void run() {
    ll x1, y1, x2, y2;
    ld left = 0;
    ld right = LINF;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    for (int i = 0; i < n; i++) {
        ll rx, ry, vx, vy;
        cin >> rx >> ry >> vx >> vy;
        
        {
            if (vx == 0) {
                if (!(x1 < rx && rx < x2)) NO();
            } else {
                if (rx <= x1) {
                    if (vx < 0) {
                        NO();
                    } else {
                        ld dx = x1 - rx;
                        left = max(left, abs(dx / vx));
                    }
                } else {
                    if (vx < 0) {
                        ld dx = rx - x1;
                        right = min(right, abs(dx / vx));
                    }
                }
            }
        }
        
        {
            if (vx == 0) {
                if (!(x1 < rx && rx < x2)) NO();
            } else {
                if (rx >= x2) {
                    if (vx > 0) {
                        NO();
                    } else {
                        ld dx = x2 - rx;
                        left = max(left, abs(dx / vx));
                    }
                } else {
                    if (vx > 0) {
                        ld dx = x2 - rx;
                        right = min(right, abs(dx / vx));
                    }
                }
            }
        }
        
        {
            if (vy == 0) {
                if (!(y1 < ry && ry < y2)) NO();
            } else {
                if (ry <= y1) {
                    if (vy < 0) {
                        NO();
                    } else {
                        ld dy = y1 - ry;
                        left = max(left, abs(dy / vy));
                    }
                } else {
                    if (vy < 0) {
                        ld dy = ry - y1;
                        right = min(right, abs(dy / vy));
                    }
                }
            }
        }
        
        {
            if (vy == 0) {
                if (!(y1 < ry && ry < y2)) NO();
            } else {
                if (ry >= y2) {
                    if (vy > 0) {
                        NO();
                    } else {
                        ld dy = y2 - ry;
                        left = max(left, abs(dy / vy));
                    }
                } else {
                    if (vy > 0) {
                        ld dy = y2 - ry;
                        right = min(right, abs(dy / vy));
                    }
                }
            }
        }
    }
    
    if (left + 1e-15 <= right) {
        cout << left << "\n";
    } else {
        cout << "-1\n";
    }
}