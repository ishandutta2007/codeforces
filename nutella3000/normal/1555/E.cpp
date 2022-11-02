#include <bits/stdc++.h>
using namespace std;
     
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) begin(a), end(a)
#define mp make_pair
#define pb emplace_back
#define ld long double
mt19937 rnd;

const int inf = 2e9 + 3;
const int max_n = (1 << 20);

int n, m;
int mn[2 * max_n], lazy[2 * max_n];

void upd(int v, int x) {
    lazy[v] += x;
    mn[v] += x;
}

void push(int v) {
    upd(v * 2, lazy[v]);
    upd(v * 2 + 1, lazy[v]);
    lazy[v] = 0;
}

int merge(int v1, int v2) {
    return min(mn[v1], mn[v2]);
}


void segadd(int l, int r, int x, int v = 1, int tl = 0, int tr = m - 1) {
    if (tl >= r || tr <= l) return;
    if (tl >= l && tr <= r) { upd(v, x); return; }
    push(v);
    int mid = (tl + tr) / 2;
    segadd(l, r, x, v * 2, tl, mid);
    segadd(l, r, x, v * 2 + 1, mid, tr);
    mn[v] = merge(v * 2, v * 2 + 1);
}

void run() {
    cin >> n >> m;
    vector<pair<int, pii>> req(n);
    for (int i = 0; i < n; ++i) {
        int l, r, w;
        cin >> l >> r >> w;
        req[i] = {w, {l - 1, r - 1}};
    }
    sort(all(req));

    int res = inf, l_b = 0;
    for (int i = 0; i < n; ++i) {
        auto [w, aboba] = req[i];
        auto [l, r] = aboba;
        segadd(l, r, 1);

        while (mn[1]) {
            segadd(req[l_b].se.fi, req[l_b].se.se, -1);
            ++l_b;
        }

        if (l_b) chkmin(res, w - req[l_b - 1].fi);
    }

    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);

#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}