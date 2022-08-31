#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 5000 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

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
        if (l >= rq || r <= lq) return 0;
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
    int n;
    cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];

    segment_tree st;
    st.build(n);

    vector<pair<int, pair<int, int>>> stk = {{INFi, {-1, 0}}};

    ll ans = 0;

    range(i, n) {
        st.upd(0, i, a[i]);
        while (stk.back().first <= a[i]) {
            st.upd(stk.back().second.first, stk.back().second.second, -a[i] + stk.back().first);
            stk.pop_back();
        }

        ans = max(ans, st.get(0, n));

        stk.push_back({a[i], {stk.back().second.second, i + 1}});
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}