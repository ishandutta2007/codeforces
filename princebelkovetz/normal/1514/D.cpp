#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cassert>
#include <functional>
using namespace std;
#define ld long double
#define debug(x) cout << #x << " actually equals " << x << '\n';
constexpr int mod = 1e9 + 7;
const int root = 500;
struct query {
    int l, r, id;
    query(int l = 0, int r = 0, int id = 0) :
        l(l), r(r), id(id) {}
    bool operator<(const query& a) const {
        if (l / root != a.l / root)
            return l / root < a.l / root;
        return r < a.r;
    }
};
struct hashstack {
    vector <vector <int>> a;
    vector <int> sum;
    hashstack(int n) {
        a.resize((n + root - 1) / root, vector <int>(root));
        sum.resize((n + root - 1) / root);
    }
    void inc(int x) {
        a[x / root][x % root]++;
        sum[x / root]++;
    }
    void dec(int x) {
        a[x / root][x % root]--;
        sum[x / root]--;
    }
    int get() {
        for (int i = a.size() - 1; i >= 0; --i) {
            if (sum[i]) {
                for (int j = root - 1; j >= 0; --j) {
                    if (a[i][j]) return i * root + j;
                }
            }
        }
    }
};
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector <int> a(n);
    for (auto& x : a) cin >> x;
    vector <query> qs(q);
    for (int i = 0; i < q; ++i) {
        cin >> qs[i].l >> qs[i].r;
        qs[i].l--;
        qs[i].id = i;
    }
    sort(qs.begin(), qs.end());
    int lx = 0, rx = 0;
    vector <int> cnt(n + 1);
    hashstack all(n + 1);
    all.a[0][0] = n, all.sum[0] = n;
    vector <int> ans(q);
    for (auto& x : qs) {
        while (rx < x.r) {
            all.dec(cnt[a[rx]]);
            cnt[a[rx]]++;
            all.inc(cnt[a[rx]]);
            rx++;
        }
        while (lx > x.l) {
            lx--;
            all.dec(cnt[a[lx]]);
            cnt[a[lx]]++;
            all.inc(cnt[a[lx]]);
        }
        while (rx > x.r) {
            rx--;
            all.dec(cnt[a[rx]]);
            cnt[a[rx]]--;
            all.inc(cnt[a[rx]]);
        }
        while (lx < x.l) {
            all.dec(cnt[a[lx]]);
            cnt[a[lx]]--;
            all.inc(cnt[a[lx]]); 
            lx++;
        }
        int ok = all.get(), res = 0;
        if (ok > (x.r - x.l + 1) / 2) {
            if (ok == x.r - x.l) res = ok;
            else res = ok - (x.r - x.l - ok + 1) + 1;
        }
        else {
            res = 1;
        }
        ans[x.id] = res;
    }
    for (auto x : ans) cout << x << '\n';
    return 0;
}