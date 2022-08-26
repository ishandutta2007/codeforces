#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 2e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

struct segment_tree {
    struct Node {
        ll val = 0;
        ll upd = 0;
    };

    int n{};
    vector<Node> tree{};

    void build(int k) {
        n = k;
        tree.resize(n * 4);
    }

    void upd(int v, int l, int r, int lq, int rq, ll x) {
        if (l >= rq || r <= lq) return;
        if (lq <= l && r <= rq) {
            tree[v].val += x;
            tree[v].upd += x;
            return;
        }
        upd(v << 1, l, (l + r) >> 1, lq, rq, x);
        upd((v << 1) + 1, (l + r) >> 1, r, lq, rq, x);
        tree[v].val = min(tree[v << 1].val, tree[(v << 1) + 1].val) + tree[v].upd;
    }

    ll get(int v, int l, int r, int lq, int rq) {
        if (l >= rq || r <= lq) return INFi;
        if (lq <= l && r <= rq) {
            return tree[v].val;
        }
        return tree[v].upd + min(get(v << 1, l, (l + r) >> 1, lq, rq),
                                 get((v << 1) + 1, (l + r) >> 1, r, lq, rq));
    }

    void upd(int lq, int rq, ll x) {
        upd(1, 0, n, lq, rq, x);
    }

    ll get(int lq, int rq) {
        return get(1, 0, n, lq, rq);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    segment_tree st;
    m--;
    st.build(m);
    vector<ar<int, 3>> segs(n);
    range(i, n) {
        cin >> segs[i][1] >> segs[i][2] >> segs[i][0];
        segs[i][1]--;
        segs[i][2]--;
    }
    sort(all(segs));
    int j = 0;
    int ans = INFi;
    for (auto &[w, l, r] : segs) {
        while (j < n && !st.get(0, m)) {
            st.upd(segs[j][1], segs[j][2], 1);
            j++;
        }
        if (st.get(0, m) == 0) break;
        ans = min(ans, segs[j - 1][0] - w);
        st.upd(l, r, -1);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}