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

const int bpv = (1 << 19);

int rsq[bpv * 2];

int s_plus(int pos, int val) {
    pos += bpv;
    rsq[pos] += val;
    pos /= 2;
    while (pos) {
        rsq[pos] = rsq[pos * 2] + rsq[pos * 2 + 1];
        pos /= 2;
    }
    return 0;
}

int s_get(int v, int vl, int vr, int l, int r) {
    if (vr <= l || r <= vl) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        return rsq[v];
    }
    int vm = (vl + vr) / 2;
    return s_get(v * 2, vl, vm, l, r) + s_get(v * 2 + 1, vm, vr, l, r);
}


int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n;
    scanf("%d", &n);

    set<int> have;
    for (int i = 0; i < n; ++i) {
        have.insert(i);
    }
    cout << "1 ";
    for (int i = 0; i < n - 1; ++i) {
        int num;
        scanf("%d", &num);
        --num;
        have.erase(num);
        s_plus(num, 1);
        cout << 1 + s_get(1, 0, bpv, 0, *--have.end()) << " ";
    }

    cout << "1\n";
    
    
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}