#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        ll x, y, p, q;
        cin >> x >> y >> p >> q;
        ll tmp = gcd(p, q);
        p /= tmp;
        q /= tmp;
        ll res = (ll) (y + q - 1) / q * q;
        //ll a = (ll) x * q / tmp;
        //ll b = (ll) (y + q - 1) / q * p;

        //cerr << b << " " << res << endl;
        
        if (p == 0) {
            if (x == 0) {
                cout << "0\n";
            } else {
                cout << "-1\n";
            }
            continue;
        }

        if (p == q) {
            if (x == y) {
                cout << "0\n";
            } else {
                cout << "-1\n";
            }
            continue;
        }

        ll rest = y - x;

        ll ans = res - y;
        ll val = max((rest - res + res / q * p + (q - p) - 1) / (q - p), (x - res / q * p + p - 1) / p);
        ans += val * q;
        //res - rest + mid * q >= res / q * p + mid * p
        //x <= res / q * p + mid * p;
        //mid = 
        cout << ans << "\n";
    }
    
    
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}