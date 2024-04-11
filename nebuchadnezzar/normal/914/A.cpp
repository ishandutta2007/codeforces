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
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }




int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    int ans = -INF;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (num < 0) {
            ans = max(ans, num);
        } else {
           int l = 0, r = 10000;
           while (r - l > 1) {
                int mid = (l + r) / 2;
                if (mid * mid > num) {
                    r = mid;
                } else {
                    l = mid;
                }
           }
           if (l * l == num) {
                continue;
           }
           ans = max(ans, num);
        }
    }
    
    cout << ans << "\n";
    
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}