#include <bits/stdc++.h>

using namespace std;

const int maxn = 300005;

int a[maxn];
vector<int> pos[maxn];
pair<int, int> it[maxn*4];

#define mid ((l + r) >> 1)
#define lc (x << 1)
#define rc (x << 1 | 1)

pair<int, int> combine(pair<int, int> x, pair<int, int> y) {
    if (x.second < y.second) swap(x, y);
    if (x.first == y.first) x.second += y.second;
    else x.second -= y.second;
    return x;
}

void build(int x, int l, int r) {
    if (l == r) {
        it[x] = make_pair(a[r], 1);
        return;
    }
    build(lc, l, mid);
    build(rc, mid + 1, r);
    it[x] = combine(it[lc], it[rc]);
}

pair<int, int> query(int x, int l, int r, int u, int v) {
    if (l >= u && r <= v) return it[x];
    if (l > v || r < u) return make_pair(0, 0);
    return combine(query(lc, l, mid, u, v), query(rc, mid + 1, r, u, v));
}

#undef mid
#undef lc
#undef rc

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q; cin >> n >> q;
    for(int i = 0; i < n; ++i) cin >> a[i], pos[a[i]].push_back(i);

    build(1, 0, n - 1);
    
    while(q--) {
        int l, r; cin >> l >> r;
        l--;

        auto cur = query(1, 0, n - 1, l, r - 1);

        
        int freq = lower_bound(pos[cur.first].begin(), pos[cur.first].end(), r)
                   - lower_bound(pos[cur.first].begin(), pos[cur.first].end(), l);
        

        if (freq * 2 - (r - l) <= 1) cout << 1 << "\n";
        else {
            cout << freq * 2 - (r - l) << "\n";
        }
    }

    return 0;
}