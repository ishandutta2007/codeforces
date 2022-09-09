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
const int SZ = 101;

int d[2][SZ];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    memset(d, 127, sizeof d);
    d[0][0] = 0;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        /*
        for (int j = 0; j < 10; ++j) {
            cerr << d[0][j] << " ";
        }
        cerr << endl;
        */
        int num;
        scanf("%d", &num);
        num /= 100;
        fill(d[1], d[1] + SZ, INF);
        for (int j = 0; j < SZ; ++j) {
            if (j + num / 10 < SZ) {
                d[1][j + num / 10] = min(d[1][j + num / 10], d[0][j] + num);
            }
            if (j >= num) {
                d[1][j - num] = min(d[1][j - num], d[0][j]);
            }
            if (n - i < 1000) {
                for (int k = 1; k <= num && k <= j; ++k) {
                    d[1][j - k] = min(d[1][j - k], d[0][j] + num - k);
                }
            }
        }
        memcpy(d[0], d[1], sizeof d[0]);
    }
    
    int ans = INF;
    for (int i = 0; i < SZ; ++i) {
        ans = min(ans, d[0][i]);
    }

    cout << (ll) ans * 100 << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}