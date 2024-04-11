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

vector<pii> rmq, there;
int bpv;

int seg_set(int v, int vl, int vr, int l, int r, pii val) {
    if (vr <= l || r <= vl) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        rmq[v] = val;
        there[v] = val;
        return 0;
    }
    if (there[v].ff != -123) {
        rmq[v * 2] = there[v];
        there[v * 2] = there[v];
        rmq[v * 2 + 1] = there[v];
        there[v * 2 + 1] = there[v];
        there[v] = {-123, -1};
    }
    int vm = (vl + vr) / 2;
    seg_set(v * 2, vl, vm, l, r, val);
    seg_set(v * 2 + 1, vm, vr, l, r, val);
    rmq[v] = max(rmq[v * 2], rmq[v * 2 + 1]);
    return 0;
}

int s_set(int pos, pii val) {
    seg_set(1, 0, bpv, pos, pos + 1, val);
    return 0;
}

pii s_get(int v, int vl, int vr, int l, int r) {
    if (vr <= l || r <= vl) {
        return {-INF, -1};
    }
    if (l <= vl && vr <= r) {
        return rmq[v];
    }
    if (there[v].ff != -123) {
        rmq[v * 2] = there[v];
        there[v * 2] = there[v];
        rmq[v * 2 + 1] = there[v];
        there[v * 2 + 1] = there[v];
        there[v] = {-123, -1};
    }
    int vm = (vl + vr) / 2;
    return max(s_get(v * 2, vl, vm, l, r), s_get(v * 2 + 1, vm, vr, l, r));
}


int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n;
    scanf("%d", &n);

    if (n == 1) {
        cout << "1\n";
        return 0;
    }

    vector<int> inp;
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        inp.puba(num);
    }
    
    bpv = 1;
    while (bpv <= n) {
        bpv *= 2;
    }
    rmq = vector<pii>(bpv * 2, {-INF, -1});
    there = vector<pii>(bpv * 2, {-123, -1});

    int val = 0, num = 0;

    vector<bool> records(n);

    for (int i = 0; i < n; ++i) {
        pii tmp = s_get(1, 0, bpv, 0, inp[i]);
        s_set(inp[i], {tmp.ff + 1, tmp.ss});
        seg_set(1, 0, bpv, 0, inp[i], {-INF, -1});
        //cerr << "set " << inp[i] << " " << tmp.ff + 1 << " " << -tmp.ss << endl;
        if (val < inp[i]) {
            records[i] = 1;
            s_set(val, {num, -inp[i]});
            //cerr << "set " << val << " " << num << " " << inp[i] << endl;
            val = inp[i];
            ++num;
        }
    }
    
    pii tmp = s_get(1, 0, bpv, 0, bpv);
    int ans = -tmp.ss;
    if (tmp.ff < num && num < n) {
        ans = INF;
        for (int i = 0; i < n; ++i) {
            if (!records[i]) {
                ans = min(ans, inp[i]);
            }
        }
    } else if (tmp.ff == num) {
        for (int i = 0; i < n; ++i) {
            if (!records[i]) {
                ans = min(ans, inp[i]);
            }
        }
    }

    cout << ans << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}