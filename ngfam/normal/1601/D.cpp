#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000005;

#define mid ((l + r) >> 1)
#define lc (x << 1)
#define rc (x << 1 | 1)

int f[maxn];
int pref[maxn];
int it[maxn << 2];
int lazy[maxn << 3];

void toggle(int x) {
    it[x] += lazy[x];
    lazy[lc] += lazy[x];
    lazy[rc] += lazy[x];
    lazy[x] = 0;
}

void update(int x, int l, int r, int u, int v, int val) {
    toggle(x);
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        lazy[x] += val;
        return toggle(x);
    }
    update(lc, l, mid, u, v, val);
    update(rc, mid+1, r, u, v, val);
    it[x] = max(it[lc], it[rc]);
}

int query(int x, int l, int r, int u, int v) {
    toggle(x);
    if (l > v || r < u) return -maxn;
    if (l >= u && r <= v) return it[x];
    int ans = max(query(lc, l, mid, u, v), query(rc, mid+1, r, u, v));
    it[x] = max(it[lc], it[rc]);
    return ans;
}

#undef mid
#undef lc
#undef rc

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int ans = 0;
    vector<pair<int, int>> reg, odd;
    int n, d; cin >> n >> d;
    vector<int> vals = {d};

    for(int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        if (x < d) continue;
        if (x < y) reg.emplace_back(x, y);
        else odd.emplace_back(x, y);

        vals.push_back(x);
        vals.push_back(y);
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    vector<vector<int>> segOdd(vals.size()), segReg(vals.size());

    for(auto &[x, y]: reg) {
        x = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
        y = lower_bound(vals.begin(), vals.end(), y) - vals.begin();
        segReg[y].push_back(x);
    }

    for(auto &[x, y]: odd) {
        x = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
        y = lower_bound(vals.begin(), vals.end(), y) - vals.begin();
        pref[y]++;
        pref[x + 1]--;
        if(y < x) {
            update(1, 0, vals.size(), y, vals.size(), -1);
            segOdd[x].push_back(y);
        }
    }

    for(int i = 1; i < maxn; ++i) pref[i] += pref[i-1];

    for(int i = 0; i < vals.size(); ++i) {
        f[i] = max(pref[i], it[1] + pref[i]);
        for(int l: segReg[i]) {
            f[i] = max(f[i], query(1, 0, vals.size(), 0, l) + 1 + pref[i]);
        }


        if (vals[i] < d) f[i] = -maxn;
        ans = max(ans, f[i]);
        update(1, 0, vals.size(), i, i, f[i]);

        for(int x: segOdd[i]) {
            update(1, 0, vals.size(), x, vals.size(), 1);
        }
    }

    cout << ans << endl;

    return 0;
}