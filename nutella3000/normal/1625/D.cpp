#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld double
#define vi vector<int>
#define vvi vector<vector<int>>

mt19937 Rand(time(0));

int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }
ld rnd_01d() { return (ld)Rand() / (1ll<<32); }
ld rnd_d(ld r) { return rnd_01d() * r; }

const int inf = 1e18 + 7;
const int N = 2e5 + 3;

pii fuck(vector<pii> a1, vector<pii> a2, int bit) {
    if (a1.empty() || a2.empty()) return {-1, 0};
    if (bit < 0) return {a1[0].fi^a2[0].fi, a1[0].se * 1e9 + a2[0].se};
    vector<pii> b1, b2, c1, c2;

    for (auto i : a1) {
        if (i.fi >> bit & 1) b2.pb(i);
        else b1.pb(i);
    }
    for (auto i : a2) {
        if (i.fi >> bit & 1) c2.pb(i);
        else c1.pb(i);
    }
    if ((size(b1) && size(c2)) || (size(b2) && size(c1)))
        return max(fuck(b1, c2, bit-1), fuck(b2, c1, bit-1));
    else
        return max(fuck(b1, c1, bit-1), fuck(b2, c2, bit-1));
}

pii mx_pair(vector<pii> a, int bit) {
    return fuck(a, a, bit);
}

void run() {
    int n, k;
    cin >> n >> k;
    int mx = 32 - (k ? __builtin_clz(k) : 32);
    map<int, vector<pii>> a;
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        a[v >> mx].pb(v, i);
    }
    if (k == 0) {
        cout << n << endl;
        for (int i = 1; i <= n; ++i)
            cout << i << " ";
        cout << endl;
        return;
    }

    vector<int> res;
    for (auto arr : a) {
        pii tmp = mx_pair(arr.se, mx-1);
        if (tmp.fi < k) res.pb(arr.se[0].se);
        else {
            res.pb(tmp.se% (int)1e9);
            res.pb(tmp.se/(int)1e9);
        }
    }
    if (size(res) < 2) {
        cout << -1 << endl;
        return;
    }
    cout << size(res) << endl;
    for (auto i : res) {
        cout << i + 1 << " ";
    }
    cout << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(20);
    //auto time = clock();
    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
    //cout << ((double) clock() - time) / CLOCKS_PER_SEC << endl;
}