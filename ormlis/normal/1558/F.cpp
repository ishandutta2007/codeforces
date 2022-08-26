#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

/*
using namespace __gnu_pbds;

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 3e6 + 1;

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

    void push(int v) {
        tree[v << 1].val += tree[v].upd;
        tree[(v << 1) + 1].val += tree[v].upd;
        tree[v << 1].upd += tree[v].upd;
        tree[(v << 1) + 1].upd += tree[v].upd;
        tree[v].upd = 0;
    }

    void upd(int v, int l, int r, int lq, int rq, ll x) {
        if (l >= rq || r <= lq) return;
        if (lq <= l && r <= rq) {
            tree[v].val += x;
            tree[v].upd += x;
            return;
        }
        push(v);
        upd(v << 1, l, (l + r) >> 1, lq, rq, x);
        upd((v << 1) + 1, (l + r) >> 1, r, lq, rq, x);
        tree[v].val = max(tree[v << 1].val, tree[(v << 1) + 1].val);
    }

    ll get(int v, int l, int r, int lq, int rq) {
        if (l >= rq || r <= lq) return -INF;
        if (lq <= l && r <= rq) {
            return tree[v].val;
        }
        return tree[v].upd + get(v << 1, l, (l + r) >> 1, lq, rq) +
               get((v << 1) + 1, (l + r) >> 1, r, lq, rq);
    }

    void upd(int lq, int rq, ll x) {
        upd(1, 0, n, lq, rq, x);
    }

    ll get(int lq, int rq) {
        return get(1, 0, n, lq, rq);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n), p(n);
    range(i, n) {
        cin >> a[i];
        a[i]--;
        p[a[i]] = i;
    }
    segment_tree st;
    st.build(n);
    ll ans = 0;
    st.upd(0, n, -INFi);
    for(int i = 0; i < n; i += 2) st.upd(i, i + 1, 1);
    set<int> bad;
    int R = 0;
    range(i, n + 1) bad.insert(i);
    range(i, n) {
        st.upd(p[i], p[i] + 1, INFi + p[i]);
        st.upd(0, p[i], 1);
        st.upd(p[i] + 1, n, -1);
        bad.erase(p[i]);
        while(R < *bad.begin()) {
            st.upd(R, R + 1, -INFi);
            R++;
        }
        ans = max(ans, st.get(0, n));
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}