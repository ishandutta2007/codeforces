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
    
    int n, t;
    scanf("%d%d", &n, &t);
    --t;

    vector<int> inp;
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        inp.puba(num);
    }
    
    map<int, int> amount;
    int cur = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i + 1 > t) {
            break;
        }
        int wait = t - i - 1;
        if (wait + i + 1 >= inp[i]) {
            ++cur;
            amount[wait - (wait + i + 1 - inp[i])]++;
        }
        ans = max(ans, cur);
        cur -= amount[wait];
    }

    cout << ans << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}