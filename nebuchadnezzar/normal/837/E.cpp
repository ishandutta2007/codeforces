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

ll f(ll a, ll b) {
    if (b == 0) {
        return 0;
    }
    return 1 + f(a, b - __gcd(a, b));
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    
    ll a, b;
    scanf("%lld%lld", &a, &b);

    ll ans = 0;
    while (true) {
        //cerr << a << " " << b << endl;
        if (b == 0) {
            break;
        }
        ll tmp = __gcd(a, b);
        ll tmpa = a / tmp;
        ll tmpb = b / tmp;
        ll best = 0;
        for (ll i = 2; i * i <= tmpa; ++i) {
            if (tmpa % i == 0) {
                best = max(best, tmpb / i * i);
                while (tmpa % i == 0) {
                    tmpa /= i;
                }
            }
        }
        if (tmpa > 1) {
            best = max(best, tmpb / tmpa * tmpa);
        }

        ans += tmpb - best;
        b = best * tmp;
    }
    
    cout << ans << "\n";
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}