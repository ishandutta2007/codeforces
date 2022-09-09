#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);

int n;

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &n);
    
    ll now = 2;
    for (int i = 0; i < n; ++i) {
        //cerr << "now: " << now << endl;
        ll num = now / (i + 1);
        ll tmp = (ll) (i + 1) * (i + 2) * (i + 2);
        ll a2 = (num + tmp - 1) / tmp;
        ll l = 0, r = 3e9;
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            if (mid * mid < a2) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << (tmp * r * r - num) << "\n";
        //assert(tmp * r * r - num >= 0);
        now = r * (i + 2) * (i + 1); 
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}