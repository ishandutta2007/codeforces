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

ll l1, r1, l2, r2, k;

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%I64d%I64d%I64d%I64d%I64d", &l1, &r1, &l2, &r2, &k);

    ll lg = max(l1, l2);
    ll rg = min(r1, r2);

    if (lg <= rg) {
        ll ans = rg - lg + 1;
        if (lg <= k && k <= rg) {
            --ans;
        }
        cout << ans << "\n";
    } else {
        cout << "0\n";
    }


    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}