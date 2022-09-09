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

vector<int> have_bit[30];

int bpv;
//vector<int> rsq;
vector<pii> rmq;
vector<int> there;

int s_segplus(int v, int vl, int vr, int l, int r, int val) {
    if (vr <= l || r <= vl) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        rmq[v].ff += val;
        there[v] += val;
        return 0;
    }
    int vm = (vl + vr) / 2;
    if (there[v]) {
        rmq[v * 2].ff += there[v];
        rmq[v * 2 + 1].ff += there[v];
        there[v * 2] += there[v];
        there[v * 2 + 1] += there[v];
        there[v] = 0;
    }
    
    s_segplus(v * 2, vl, vm, l, r, val);
    s_segplus(v * 2 + 1, vm, vr, l, r, val);
    if (rmq[v * 2].ff != rmq[v * 2 + 1].ff) {
        rmq[v] = min(rmq[v * 2], rmq[v * 2 + 1]);
    } else {
        rmq[v] = {rmq[v * 2].ff, rmq[v * 2].ss + rmq[v * 2 + 1].ss};
    }
    return 0;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n;
    scanf("%d", &n);

    vector<int> inp;
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        inp.puba(num);
        for (int j = 0; j < 30; ++j) {
            if (num & (1 << j)) {
                have_bit[j].puba(i);
            }
        }
    }
    
    vector<tuple<int, int, int, int>> scanline;

    for (int i = 0; i < n; ++i) {
        int l = 0, r = n - 1;
        for (int j = 0; j < 30; ++j) {
            if (!(inp[i] & (1 << j))) {
                auto it = lower_bound(bend(have_bit[j]), i);
                if (it != have_bit[j].begin()) {
                    l = max(l, *(it - 1) + 1);
                }
                if (it != have_bit[j].end()) {
                    r = min(r, *it - 1);
                }
            }
        }
        int x1 = l, x2 = i, y1 = i, y2 = r;
        //cerr << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        scanline.puba({x1, y1, y2 + 1, 0});
        scanline.puba({x2 + 1, y1, y2 + 1, 1});
    }
    
    sort(bend(scanline));

    bpv = 1;
    while (bpv < n + 5) {
        bpv *= 2;
    }

    rmq.resize(bpv * 2);
    there.resize(bpv * 2);

    for (int i = 0; i < bpv; ++i) {
        rmq[i + bpv].ss = 1;
    }
    for (int i = bpv - 1; i; --i) {
        rmq[i].ss = rmq[i * 2].ss + rmq[i * 2 + 1].ss;
    }

    int prev = 0;
    ll ans = (ll) n * (n + 1) / 2;
    //cerr << ans << "\n";
    for (auto cur : scanline) {
        int x, y1, y2, t;
        tie(x, y1, y2, t) = cur;
        ans -= (ll) (x - prev) * (bpv - rmq[1].ss);
        //cerr << x - prev << " " << (bpv - rmq[1].ss) << endl;
        if (t == 0) {
            s_segplus(1, 0, bpv, y1, y2, 1);
        } else {
            s_segplus(1, 0, bpv, y1, y2, -1);
        }

        prev = x;
    }

    cout << ans << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}