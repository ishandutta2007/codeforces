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

int bpv;
vector<int> rsq;

int s_set(int pos, int num) {
    pos += bpv;
    rsq[pos] = num;
    pos /= 2;
    while (pos) {
        rsq[pos] = __gcd(rsq[pos * 2], rsq[pos * 2 + 1]);
        pos /= 2;
    }
    return 0;
}

int check(int v, int vl, int vr, int l, int r, int num) {
    if (vr <= l || r <= vl || rsq[v] % num == 0) {
        return 0;
    }
    if (vl + 1 == vr) {
        return 1;
    }
    int vm = (vl + vr) / 2;
    if (l <= vl && vr <= r) {
        if (rsq[v * 2] % num != 0 && rsq[v * 2 + 1] % num != 0) {
            return 2;
        }
        if (rsq[v * 2] % num != 0) {
            return check(v * 2, vl, vm, l, r, num);
        }
        return check(v * 2 + 1, vm, vr, l, r, num);
    }
    int tmp = check(v * 2, vl, vm, l, r, num);
    if (tmp > 1) {
        return 2;
    }
    return tmp + check(v * 2 + 1, vm, vr, l, r, num);
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    bpv = 1;
    while (bpv < n) {
        bpv *= 2;
    }
    rsq = vector<int>(bpv * 2);
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        rsq[i + bpv] = num;
    }
    
    for (int i = bpv - 1; i; --i) {
        rsq[i] = __gcd(rsq[i * 2], rsq[i * 2 + 1]);
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            --l;
            if (check(1, 0, bpv, l, r, x) <= 1) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            int pos, num;
            cin >> pos >> num;
            --pos;
            s_set(pos, num);
        }
    }
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}