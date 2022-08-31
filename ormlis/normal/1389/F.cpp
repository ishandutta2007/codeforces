#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <set>
#include <map>
#include <random>
#include <chrono>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
using namespace std;

const int INFi = 1e9;
const ll INF = 1e18;

struct segment_tree {
    struct Node {
        int mx = 0;
        int add = 0;

        void upd(int x) {
            add += x;
            mx += x;
        }

        void check(int x) {
            mx = max(mx, x);
        }

        void combine(const Node &a, const Node &b) {
            mx = max(a.mx, b.mx);
            mx += add;
        }
    };

    int n{};
    vector<Node> tree{};

    void build(int k) {
        n = k;
        tree.resize(n * 4);
    }


    void upd1(int v, int l, int r, int pos, int x) {
        if (l > pos || r <= pos) return;
        if (l + 1 == r) {
            tree[v].check(x);
            return;
        }
        x -= tree[v].add;
        upd1(v << 1, l, (l + r) >> 1, pos, x);
        upd1((v << 1) + 1, (l + r) >> 1, r, pos, x);
        tree[v].combine(tree[v << 1], tree[(v << 1) + 1]);
    }

    int get(int v, int l, int r, int lq, int rq) {
        if (l >= rq || r <= lq) return -INFi;
        if (lq <= l && r <= rq) {
            return tree[v].mx;
        }
        return max(get(v << 1, l, (l + r) >> 1, lq, rq),
                   get((v << 1) + 1, (l + r) >> 1, r, lq, rq)) + tree[v].add;
    }


    void upd2(int v, int l, int r, int lq, int rq, int x) {
        if (l >= rq || r <= lq) return;
        if (lq <= l && r <= rq) {
            tree[v].add += x;
            tree[v].mx += x;
            return;
        }
        upd2(v << 1, l, (l + r) >> 1, lq, rq, x);
        upd2((v << 1) + 1, (l + r) >> 1, r, lq, rq, x);
        tree[v].combine(tree[v << 1], tree[(v << 1) + 1]);
    }

    void upd1(int pos, int x) {
        upd1(1, 0, n, pos, x);
    }

    int get(int lq, int rq) {
        return get(1, 0, n, lq, rq);
    }

    void upd2(int lq, int rq, int x) {
        upd2(1, 0, n, lq, rq, x);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<ar<int, 3>> a(n);
    vector<int> cords;
    range(i, n) {
        range(j, 3) {
            cin >> a[i][j];
            if (j != 2) cords.push_back(a[i][j]);
        }
    }
    cords.push_back(0);
    cords.push_back(INFi + 5);
    sort(all(cords));
    cords.resize(unique(all(cords)) - cords.begin());

    auto get_ind = [&](int x) {
        return lower_bound(all(cords), x) - cords.begin();
    };
    int cn = cords.size();
    segment_tree st[2];
    st[0].build(cn);
    st[1].build(cn);
    sort(all(a));
    for (auto &[l, r, t] : a) {
        int j = get_ind(r);
        t--;
        st[t].upd2(j, cn, 1);
        int i = get_ind(l);
        int kek = st[t ^ 1].get(0, i);
        st[t].upd1(j, kek + 1);
        kek = st[t].get(0, j);
        st[t].upd1(j, kek + 1);
    }
    cout << max(st[1].get(0, cn), st[0].get(0, cn));
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