#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

namespace DSU {
    int p[MAX_N], r[MAX_N];
    void init(int n) { iota(p, p + n + 1, 0); fill_n(r, n + 1, 0); }
    int find(int x) { return x == p[x] ? x : (p[x] = find(p[x])); }
    bool union_(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return 0;
        if (r[x] < r[y]) swap(x, y);
        p[y] = x;
        r[x] += r[x] == r[y];
        return 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    array<int, 3> spec;
    vector<array<int, 3>> ed(m - 1);
    cin >> spec[0] >> spec[1] >> spec[2];
    for (auto &e : ed)
        cin >> e[0] >> e[1] >> e[2];

    auto cmp = [](auto &a, auto &b) { return a[2] < b[2]; };
    sort(ed.begin(), ed.end(), cmp);

    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        long long mst = 0, mst2 = mid;

        DSU::init(n);
        auto ed2 = ed;
        ed2.push_back({spec[0], spec[1], mid});
        sort(ed2.begin(), ed2.end(), cmp);
        for (auto &e : ed2) if (DSU::union_(e[0], e[1])) mst += e[2];

        DSU::init(n);
        DSU::union_(spec[0], spec[1]);
        for (auto &e : ed) if (DSU::union_(e[0], e[1])) mst2 += e[2];

        if (mst < mst2)
            hi = mid - 1;
        else
            lo = mid;
    }
    cout << lo << "\n";

    return 0;
}