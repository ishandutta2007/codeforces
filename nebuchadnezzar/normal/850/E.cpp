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
const int MAXN = 21;
const int MOD = 1e9 + 7;
char buf[1 << MAXN];

ll rsq[1 << MAXN];
int inp[1 << MAXN];
ll tmp[1 << MAXN];

int calc(int v, int vl, int vr) {
    //cerr << v << " " << vl << " " << vr << endl;
    if (vl + 1 == vr) {
        return 0;
    }
    int vm = (vl + vr) / 2;
    calc(v * 2, vl, vm);
    calc(v * 2 + 1, vm, vr);
    fill(tmp + vl, tmp + vr, 0);
    
    for (int i = vl; i < vr; ++i) {
        //if (!inp[i]) {
        //    continue;
        //}
        if (i < vm) {
            tmp[i] = (rsq[i] * 2 + rsq[i + vm - vl]) % MOD;
        } else {
            tmp[i] = (rsq[i] * 2 + rsq[i - (vm - vl)]) % MOD;
        }
    }
    //cerr << vl << " " << vr << endl;
    for (int i = vl; i < vr; ++i) {
        rsq[i] = tmp[i];
        //cerr << rsq[i] << " ";
    }
    //cerr << endl;
    return 0;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n;
    scanf("%d", &n);

    scanf("%s", buf);

    int bpv = 1 << n;
    for (int i = 0; i < bpv; ++i) {
        rsq[i] = buf[i] - '0';
        inp[i] = rsq[i];
    }
    
    calc(1, 0, bpv);

    ll ans = 0;
    for (int i = 0; i < bpv; ++i) {
        ans = (ans + rsq[i] * inp[i]) % MOD;
    }

    ans = (ans * 3) % MOD;
    cout << ans << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}