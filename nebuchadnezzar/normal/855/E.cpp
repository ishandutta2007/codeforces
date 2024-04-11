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

const int bp = 10, MAXL = 64, MAXB = 13;

ll d[MAXB][2][MAXL][(1 << bp) + 5];

ll calc(int b, ll r) {
    if (r == 0) {
        return 0;
    }
    vector<int> arr;
    while (r) {
        arr.puba(r % b);
        r /= b;
    }

    ll ans = 0;
    for (int i = 1; i < szof(arr); ++i) {
        ans += d[b][1][i][0];
    }

    int mask = 0;
    reverse(bend(arr));
    for (int i = 0; i < szof(arr); ++i) {
        int from = 0;
        if (i == 0) {
            from = 1;
        }
        for (int j = from; j < arr[i]; ++j) {
            ans += d[b][0][szof(arr) - i - 1][mask ^ (1 << j)];
        }
        mask ^= (1 << arr[i]);
    }
    ans += d[b][0][0][mask];
    return ans;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    

    for (int q = 2; q <= 10; ++q) {
        int bpv = 1 << q;
        d[q][0][0][0] = 1;
        for (int i = 1; i < MAXL; ++i) {
            for (int j = 0; j < bpv; ++j) {
                for (int k = 0; k < q; ++k) {
                    d[q][0][i][j] += d[q][0][i - 1][j ^ (1 << k)];
                    if (k) {
                        d[q][1][i][j] += d[q][0][i - 1][j ^ (1 << k)];
                    }
                }
            }
        }
    }
    
    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; ++i) {
        int b;
        ll l, r;
        scanf("%d%lld%lld", &b, &l, &r);
        cout << calc(b, r) - calc(b, l - 1) << "\n";
    }
    
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}