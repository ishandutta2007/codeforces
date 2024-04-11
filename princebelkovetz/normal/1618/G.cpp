#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>
#include <string>
#include <numeric>
#pragma GCC optimize("O3")

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 998244353, N = 4e2 + 2;

struct dsu {
    vector <int> p;
    dsu(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    int get(int a) {
        return p[a] = p[a] == a ? a : get(p[a]);
    }
    void unite(int a, int b) {
        p[a] = b;
    }
};

int curAns = 0;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12);
    int n, m, q; cin >> n >> m >> q;
    vector <pair <int, int>> cost;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        cost.push_back({ x, 1 });
        curAns += x;
    }
    for (int i = 0, x; i < m; ++i) {
        cin >> x;
        cost.push_back({ x, 0 });
    }
    vector <int> cnt(n + m);
    vector <pair <int, int>> qs(q);
    vector <int> qAns(q);
    sort(cost.begin(), cost.end());
    vector <int> ds(n + m - 1);
    iota(ds.begin(), ds.end(), 0);
    sort(ds.begin(), ds.end(), [&](int i, int j) {
        return cost[i + 1].first - cost[i].first < cost[j + 1].first - cost[j].first;
        });
    vector <int> pref(n + m + 1);
    for (int i = 0; i < n + m; ++i) {
        pref[i + 1] = pref[i] + cost[i].first;
        if (cost[i].second) cnt[i]++;
    }
    for (int i = 0; i < q; ++i) {
        cin >> qs[i].first;
        qs[i].second = i;
    }
    sort(qs.begin(), qs.end());
    int curIdx = 0;
    dsu setUnion(n + m);
    for (auto& x : qs) {
        while (curIdx < ds.size()) {
            int curDif = cost[ds[curIdx] + 1].first - cost[ds[curIdx]].first;
            if (curDif > x.first) break;
            int lx = ds[curIdx], rx = setUnion.get(ds[curIdx] + 1);
            curAns -= pref[rx + 1] - pref[rx + 1 - cnt[rx]];
            curAns -= pref[lx + 1] - pref[lx + 1 - cnt[lx]];
            cnt[rx] += cnt[lx];
            setUnion.unite(lx, rx);
            curAns += pref[rx + 1] - pref[rx + 1 - cnt[rx]];
            curIdx++;
        }
        qAns[x.second] = curAns;
    }
    for (auto& x : qAns) cout << x << '\n';
    cout << '\n';
}