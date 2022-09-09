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

vector<int> rsq, there;
int bpv;

int s_segset(int v, int vl, int vr, int l, int r, int val) {
    if (vr <= l || r <= vl) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        rsq[v] = (ll) (vr - vl) * val;
        there[v] = val;
        return 0;
    }
    int vm = (vl + vr) / 2;
    if (there[v] != 2) {
        rsq[v * 2] = (ll) (vm - vl) * there[v];
        rsq[v * 2 + 1] = (ll) (vm - vl) * there[v];
        there[v * 2] = there[v];
        there[v * 2 + 1] = there[v];
        there[v] = 2;
    }
    s_segset(v * 2, vl, vm, l, r, val);
    s_segset(v * 2 + 1, vm, vr, l, r, val);
    rsq[v] = rsq[v * 2] + rsq[v * 2 + 1];
    return 0;
}

int s_set(int pos, int val) {
    s_segset(1, 0, bpv, pos, pos + 1, val);
    return 0;
}


int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n, s1, s2;
    scanf("%d%d%d", &n, &s1, &s2);

    vector<ll> arr = {s1, s2};
    vector<ll> inp;
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        inp.puba(num);
        arr.puba(num);
    }

    sort(bend(arr));
    arr.resize(unique(bend(arr)) - arr.begin());
    bpv = 1;
    while (bpv < szof(arr)) {
        bpv *= 2;
    }


    ll l = 0, r = INF;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        rsq = vector<int>(bpv * 2, 0);
        there = vector<int>(bpv * 2, 2);
        if (abs(s1 - s2) > mid) {
            l = mid;
            continue;
        }
        if (abs(s1 - inp[0]) <= mid) {
            s_set(lower_bound(bend(arr), s1) - arr.begin(), 1);
        }
        if (abs(s2 - inp[0]) <= mid) {
            s_set(lower_bound(bend(arr), s2) - arr.begin(), 1);
        }
        for (int i = 0; i < n - 1; ++i) {
            if (!rsq[1]) {
                break;
            }
            ll cur = inp[i];
            ll next = inp[i + 1];
            s_set(lower_bound(bend(arr), cur) - arr.begin(), 1);
            ll lg = next - mid;
            int pos = lower_bound(bend(arr), lg) - arr.begin();
            s_segset(1, 0, bpv, 0, pos, 0);
            ll rg = next + mid;
            pos = upper_bound(bend(arr), rg) - arr.begin();
            s_segset(1, 0, bpv, pos, bpv, 0);
        }

        if (rsq[1]) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << r << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}