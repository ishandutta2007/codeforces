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
const ll INFM = 1e12 + 7;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }
const int MAXN = 1e5 + 5;


vector<tuple<int, int, int>> arr[2];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; ++i) {
        int d, f, t, c;
        scanf("%d%d%d%d", &d, &f, &t, &c);
        if (f == 0) {
            arr[1].puba({d, t - 1, c});
        } else {
            arr[0].puba({d, f - 1, c});
        }
    }

    const int SZ = 1e6 + 5;

    vector<ll> costs(SZ);

    sort(bend(arr[0]));

    vector<ll> cur_c(n, INFM);
    ll tot_c = (ll) n * INFM;
    int c = 0;
    for (int i = 0; i < SZ; ++i) {
        costs[i] = tot_c;
        while (c < szof(arr[0]) && get<0>(arr[0][c]) <= i) {
            int day, city, cost;
            tie(day, city, cost) = arr[0][c++];
            tot_c -= cur_c[city];
            cur_c[city] = min(cur_c[city], (ll) cost);
            //cerr << tot_c << " " << cur_c[city] << endl;   
            tot_c += cur_c[city];
        }
    }
    
    sort(bend(arr[1]));
    reverse(bend(arr[1]));

    c = 0;
    tot_c = (ll) n * INFM;
    cur_c = vector<ll>(n, INFM);
    for (int i = SZ + k - 1; i - k >= 0; --i) {
        while (c < szof(arr[1]) && get<0>(arr[1][c]) >= i) {
            int day, city, cost;
            tie(day, city, cost) = arr[1][c++];
            tot_c -= cur_c[city];
            cur_c[city] = min(cur_c[city], (ll) cost);   
            tot_c += cur_c[city];
        }
        costs[i - k] += tot_c;
    }

    ll ans = INFL;
    for (int i = 0; i < SZ; ++i) {
        ans = min(ans, costs[i]);
    }
    if (ans >= INFM) {
        ans = -1;
    }
    cout << ans << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}