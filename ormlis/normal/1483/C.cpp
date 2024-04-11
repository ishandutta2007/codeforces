#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

typedef long long ll;
typedef long double ld;

using namespace std;

const int maxN = 1e5;
const int INFi = 2e9;
const ll INF = 1e18;
const int md = 1e9 + 7;


struct segment_tree {
    struct Node {
        ll val = 0;
        ll upd = 0;

        void combine(const Node &a, const Node &b) {
            val = max(a.val, b.val) + upd;
        }

        void init(ll x) {
            val = x;
        }

        void check(ll x) {
            upd += x;
            val += x;
        }
    };

    vector<Node> tree{};
    int n{};

    void build(int k) {
        n = k;
        tree.resize(n * 4);
    }

    void make(int v, int l, int r, vector<ll> &a) {
        if (l + 1 == r) {
            tree[v].init(a[l]);
            return;
        }
        make(v << 1, l, (l + r) >> 1, a);
        make(v << 1 | 1, (l + r) >> 1, r, a);
        tree[v].combine(tree[v << 1], tree[v << 1 | 1]);
    }

    void upd(int v, int l, int r, int lq, int rq, ll x) {
        if (r <= lq || l >= rq) return;
        if (lq <= l && r <= rq) {
            tree[v].check(x);
            return;
        }
        upd(v << 1, l, (l + r) >> 1, lq, rq, x);
        upd(v << 1 | 1, (l + r) >> 1, r, lq, rq, x);
        tree[v].combine(tree[v << 1], tree[v << 1 | 1]);
    }

    void upd(int lq, int rq, ll x) {
        upd(1, 0, n, lq, rq, x);
    }

    ll get(int v, int l, int r, int lq, int rq) {
        if (r <= lq || l >= rq) return -INF;
        if (lq <= l && r <= rq) return tree[v].val;
        return max(get(v << 1, l, (l + r) >> 1, lq, rq), get(v << 1 | 1, (l + r) >> 1, r, lq, rq)) +
               tree[v].upd;
    }

    ll get(int lq, int rq) {
        return get(1, 0, n, lq, rq);
    }
};


void solve() {
    int n; cin >> n;
    vector<int> h(n + 1);
    range(i, n) cin >> h[i + 1];
    vector<int> b(n + 1);
    range(i, n) cin >> b[i + 1];
    h[0] = -INFi;
    multiset<ll> can;
    vector<pair<int, ll>> stk = {{0, 0}};
    vector<ll> dp(n + 1);
    for(int i = 1; i <= n; ++i) {
        ll mx = dp[i - 1];
        while(h[stk.back().first] > h[i]) {
            mx = max(mx, stk.back().second);
            can.erase(can.find(stk.back().second + b[stk.back().first]));
            stk.pop_back();
        }
        stk.emplace_back(i, mx);
        can.insert(mx + b[i]);
        dp[i] = *can.rbegin();
    }
    cout << dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}