#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>
#include <cassert>
#include <iomanip>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e7;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}


struct merge_sort_tree {
    struct Node {
        vector<ar<int, 4>> val{};
        int l{}, r{};
        void combine(const Node &a, const Node &b) {
            val.clear();
            int i = 0, j = 0;
            while (i < (int) a.val.size() || j < (int) b.val.size()) {
                val.push_back({-1, 1, i, j});
                if (i != (int)a.val.size()) val.back()[1] = mul(val.back()[1], a.val[i][1]);
                if (j != (int)b.val.size()) val.back()[1] = mul(val.back()[1], b.val[j][1]);
                if (i == (int) a.val.size()) {
                    val.back()[0] = b.val[j][0];
                    j++;
                } else if (j == (int) b.val.size() || a.val[i][0] < b.val[j][0]) {
                    val.back()[0] = a.val[i][0];
                    i++;
                } else {
                    val.back()[0] = b.val[j][0];
                    j++;
                }
            }
        }
    };

    vector<Node> tree{};
    int n{};

    void build(int k, vector<pair<int, int>> &a) {
        n = k;
        tree.push_back({});
        make(0, 0, n, a);
    }

    void make(int v, int l, int r, vector<pair<int, int>> &a) {
        if (l + 1 == r) {
            tree[v].val = {{a[l].first, a[l].second, 0, 0}};
            return;
        }
        tree[v].l = tree.size();
        tree.push_back({});
        make(tree[v].l, l, (l+r)>>1, a);

        tree[v].r = tree.size();
        tree.push_back({});
        make(tree[v].r,  (l+r)>>1, r, a);

        tree[v].combine(tree[tree[v].l], tree[tree[v].r]);
    }

    int get(int v, int l, int r, int &lq, int &rq, int &i) {
        if (l >= rq || r <= lq || i == tree[v].val.size()) return 1;
        if (lq <= l && r <= rq) {
            return tree[v].val[i][1];
        }
        return mul(get(tree[v].l, l, (l + r) >> 1, lq, rq, tree[v].val[i][2]),
                   get(tree[v].r, (l + r) >> 1, r, lq, rq, tree[v].val[i][3]));
    }

    int get(int lq, int rq) {
        ar<int, 4> for_find = {rq, -1, -1, -1};
        int j = lower_bound(all(tree[0].val), for_find) - tree[0].val.begin();
        return get(0, 0, n, lq, rq, j);
    }
};

struct sparse_table {
    int n{};
    vector<vector<char>> sp{};

    void build(int k, vector<char> a) {
        n = k;
        int lgn = __lg(n) + 1;
        sp.resize(k, vector<char>(lgn));
        range(i, n) sp[i][0] = a[i];
        range(j, lgn - 1) for (int i = 0; i + (1 << j) < n; ++i)
                sp[i][j + 1] = max(sp[i][j], sp[i +
                                                (1
                                                        << j)][j]);
    }

    // [l, r)
    int rmq(int l, int r) {
        int w = __lg(r - l);
        return max(sp[l][w], sp[r - (1 << w)][w]);
    }
};

bool mp[(int) 1e3];
vector<int> primes;

void init_mp() {
    for (int i = 2; i < 1e3; ++i) {
        if (i * i > 2e5) break;
        if (!mp[i]) {
            primes.push_back(i);
            for (int j = i; j < 1e3; j += i) mp[j] = true;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    init_mp();
    int psz = primes.size();
    vector<sparse_table> sps(psz);
    range(i, psz) {
        vector<char> b(n, 0);
        range(j, n) {
            while (a[j] % primes[i] == 0) {
                a[j] /= primes[i];
                b[j]++;
            }
        }
        sps[i].build(n, b);
    }
    vector<pair<int, int>> b(n);
    vector<int> last(2e5 + 5, n);
    for (int i = n - 1; i >= 0; --i) {
        b[i] = {last[a[i]], a[i]};
        last[a[i]] = i;
    }
    merge_sort_tree mst;
    mst.build(n, b);
    int q;
    cin >> q;
    int lastans = 0;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int l = (lastans + x) % n, r = (lastans + y) % n;
        if (l > r) swap(l, r);
        int ans = 1;
        range(i, psz) ans = mul(ans, binpow(primes[i], sps[i].rmq(l, r + 1)));
        ans = mul(ans, mst.get(l, r + 1));
        lastans = ans;
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}