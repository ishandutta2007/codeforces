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
const ll INFL = 7e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }




int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n, p, q, r;
    scanf("%d%d%d%d", &n, &p, &q, &r);

    vector<ll> d1(4, -INFL), d2(4, -INFL);

    d1[0] = 0;

    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        d2 = vector<ll>(4, -INFL);
        d2[0] = d1[0];
        d2[1] = max(d1[1], d2[0] + (ll) p * num);
        d2[2] = max(d1[2], d2[1] + (ll) q * num);
        d2[3] = max(d1[3], d2[2] + (ll) r * num);
        swap(d1, d2);
    }
    
    cout << d1[3] << "\n";
    
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}