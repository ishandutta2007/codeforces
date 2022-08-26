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
// #include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < (n); ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

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

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 4e5 + 1;
const int md2 = 998244353;
const int md3 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

struct segment_tree {
    struct Node {
        ll cnt = 0;
        ll val = 0;
        ll upd = 0;

        void check(ll x) {
            val += cnt * x;
            upd += x;
        }

        void change() {
            if (cnt == 0) {
                cnt = 1;
                val = upd;
            } else {
                cnt = 0;
                val = 0;
            }
        }

        void combine(const Node &a, const Node &b) {
            val = a.val + b.val;
            cnt = a.cnt + b.cnt;
        }
    };

    vector<Node> tree{};
    int n{};

    void build(int k) {
        n = k;
        tree.resize(n * 4);
    }

    void push(int v) {
        if (!tree[v].upd) return;
        tree[v << 1].check(tree[v].upd);
        tree[v << 1 | 1].check(tree[v].upd);
        tree[v].upd = 0;
    }

    void upd1(int v, int l, int r, int &pos) {
        if (l > pos || r <= pos) return;
        if (l + 1 == r) {
            tree[v].change();
            return;
        }
        push(v);
        upd1(v << 1, l, (l + r) >> 1, pos);
        upd1(v << 1 | 1, (l + r) >> 1, r, pos);
        tree[v].combine(tree[v << 1], tree[v << 1 | 1]);
    }

    void upd2(int v, int l, int r, int &lq, int &rq, ll &val) {
        if (l >= rq || r <= lq) return;
        if (lq <= l && r <= rq) {
            tree[v].check(val);
            return;
        }
        push(v);
        upd2(v << 1, l, (l + r) >> 1, lq, rq, val);
        upd2(v << 1 | 1, (l + r) >> 1, r, lq, rq, val);
        tree[v].combine(tree[v << 1], tree[v << 1 | 1]);
    }

    void upd1(int pos) {
        upd1(1, 0, n, pos);
    }

    void upd2(int l, int r, ll val) {
        upd2(1, 0, n, l, r, val);
    }


    ll get_all_sum() {
        return tree[1].val;
    }

    ll getL(int v, int l, int r, int k) {
        if (l + 1 == r) {
            return tree[v].val;
        }
        push(v);
        if (tree[v << 1].cnt >= k) {
            return getL(v << 1, l, (l + r) >> 1, k);
        } else {
            return getL(v << 1 | 1, (l + r) >> 1, r, k - tree[v << 1].cnt);
        }
    }


    ll getL(int k) {
        if (k <= 0) return 0;
        return getL(1, 0, n, k);
    }

    ll getR(int v, int l, int r, int k) {
        if (l + 1 == r) {
            return tree[v].val;
        }
        push(v);
        if (tree[v << 1 | 1].cnt >= k) {
            return getR(v << 1 | 1, (l + r) >> 1, r, k);
        } else {
            return getR(v << 1, l, (l + r) >> 1, k - tree[v << 1 | 1].cnt);
        }
    }

    ll getR(int k) {
        if (k <= 0) return 0;
        return getR(1, 0, n, k);
    }

    ll getRsum(int v, int l, int r, int k) {
        if (l + 1 == r) {
            return tree[v].val;
        }
        push(v);
        if (tree[v << 1 | 1].cnt >= k) {
            return getRsum(v << 1 | 1, (l + r) >> 1, r, k);
        } else {
            return getRsum(v << 1, l, (l + r) >> 1, k - tree[v << 1 | 1].cnt) +
                   tree[v << 1 | 1].val;
        }
    }

    ll getRsum(int k) {
        if (k <= 0) return 0;
        return getRsum(1, 0, n, k);
    }

    ll getLsum(int v, int l, int r, int k) {
        if (l + 1 == r) {
            return tree[v].val;
        }
        push(v);
        if (tree[v << 1].cnt >= k) {
            return getLsum(v << 1, l, (l + r) >> 1, k);
        } else {
            return getLsum(v << 1 | 1, (l + r) >> 1, r, k - tree[v << 1].cnt) +
                   tree[v << 1].val;
        }
    }

    ll getLsum(int k) {
        if (k <= 0) return 0;
        return getLsum(1, 0, n, k);
    }


};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> s(n);
    range(i, n) cin >> s[i];
    vector<pair<int, ll>> qs(q);
    range(i, q) cin >> qs[i].first >> qs[i].second;
    auto xx = s;
    range(i, q) xx.push_back(qs[i].second);
    sort(all(xx));
    xx.resize(unique(all(xx)) - xx.begin());
    int xn = xx.size();
    int sz = 0;
    segment_tree stL;
    segment_tree stR;
    stL.build(xn);
    stR.build(xn);
    auto add = [&](ll x) {
        int i = lower_bound(all(xx), x) - xx.begin();
        stL.upd1(i);
        stR.upd1(i);
        stL.upd2(i, xn, x);
        stR.upd2(0, i + 1, x);
        sz++;
    };

    auto del = [&](ll x) {
        int i = lower_bound(all(xx), x) - xx.begin();
        stL.upd2(i, xn, -x);
        stR.upd2(0, i + 1, -x);
        stL.upd1(i);
        stR.upd1(i);
        sz--;
    };

    auto get_diff = [&](int i) {
        ll sum_l = stL.getL(i);
        ll sum_r = stR.getR(i - 1);
        return sum_l - sum_r;
    };

    auto print_ans = [&]() {
        if (sz <= 1) {
            cout << "0\n";
            return;
        }
        int k = (sz + 1) / 2;
        if (get_diff(k) >= 0) {
            cout << stR.get_all_sum() - stL.get_all_sum() << '\n';
            return;
        }
        int lb = k - 1;
        int rb = k - 1;
        {
            int L = 0, R = k;
            while (R - L > 1) {
                int mid = (R + L) / 2;
                if (get_diff(mid) >= 0) {
                    L = mid;
                } else {
                    R = mid;
                }
            }
            lb = R - 1;
        }
        {
            int L = k, R = sz;
            while (R - L > 1) {
                int mid = (R + L) / 2;
                ll x = get_diff(mid);
                if (get_diff(mid) >= 0) {
                    R = mid;
                } else {
                    L = mid;
                }
            }
            rb = L - 1;
        }
        ll res = stR.getRsum(lb - 1) + stR.getLsum(sz - rb);
        res -= stL.getLsum(lb);
        res -= stL.getRsum(sz - rb - 1);
        cout << res << '\n';
    };
    range(i, n) add(s[i]);
    print_ans();
    range(i, q) {
        if (qs[i].first == 1) {
            add(qs[i].second);
        } else {
            del(qs[i].second);
        }
        print_ans();
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