#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
using namespace std;

const ll INF = 1e18 + 5;
const int INFi = 1e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

struct segment_tree {
    int n{};
    vector<pair<ll, int>> tree{};
    vector<ll> up{};

    void build(int k, vector<ll> &a) {
        n = k;
        tree.resize(n * 4);
        up.resize(n * 4, 0);
        make(1, 0, n, a);
    }

    void make(int v, int l, int r, vector<ll> &a) {
        if (l + 1 == r) {
            tree[v].first = a[l];
            tree[v].second = l;
            return;
        }
        make(v << 1, l, (l + r) >> 1, a);
        make(v << 1 | 1, (l + r) >> 1, r, a);
        tree[v] = min(tree[v<<1], tree[v<<1|1]);
    }

    void push(int v) {
        if (up[v] == 0) return;
        tree[v << 1].first += up[v];
        up[v << 1] += up[v];
        tree[v << 1 | 1].first += up[v];
        up[v << 1 | 1] += up[v];
        up[v] = 0;
    }


    void upd(int v, int l, int r, int lq, int rq, ll x) {
        if (l >= rq || r <= lq) return;
        if (lq <= l && r <= rq) {
            tree[v].first += x;
            up[v] += x;
            return;
        }
        push(v);
        upd(v << 1, l, (l + r) >> 1, lq, rq, x);
        upd((v << 1) + 1, (l + r) >> 1, r, lq, rq, x);
        tree[v] = min(tree[v << 1], tree[(v << 1) + 1]);
    }

    pair<ll, int> get(int v, int l, int r, int lq, int rq) {
        if (l >= rq || r <= lq) return {INF, INFi};
        if (lq <= l && r <= rq) {
            return tree[v];
        }
        push(v);
        return min(get(v << 1, l, (l + r) >> 1, lq, rq),
                   get((v << 1) + 1, (l + r) >> 1, r, lq, rq));
    }

    void upd(int lq, int rq, ll x) {
        upd(1, 0, n, lq, rq, x);
    }

    pair<ll, int> get(int lq, int rq) {
        return get(1, 0, n, lq, rq);
    }
};


string s;
int n;
int x, y;

pair<vector<ll>, pair<int, int>> solve(int l, int r) {
    vector<ll> res(r - l + 1, INF);
    if (l + 1 == r) {
        pair<int, int> res2 = {1, 1};
        if (s[l] != '0') res[1] = 0, res2.second = 2;
        if (s[l] != '1') res[0] = 0, res2.first = 0;
        return {res, res2};
    }
    int mid = (r + l) / 2;
    auto T1 = solve(l, mid);
    vector<ll> res1 = T1.first;
    pair<int, int> p1 = T1.second;
    auto T2 = solve(mid, r);
    vector<ll> res2 = T2.first;
    pair<int, int> p2 = T2.second;
    pair<int, int> ress2 = {INFi, - INFi};
    range(i, (int)res.size()) {
        int L = p1.first, R = min(i, p1.second - 1);
        L = max(L, i - (p2.second - 1));
        R = min(R, i - p2.first);
        if (L > R) continue;
        auto check = [&] (int j) {
            ll s = res1[j] + res2[i - j];
            s += 1ll * j * (r - mid - (i - j)) * y;
            s += 1ll * (mid - l - j) * (i - j) * x;
            return s;
        };

        auto check2 = [&] (int j) {
            return check(j) < check(j + 1);
        };
        while(R - L > 1) {
            int m = (R + L) / 2;
            if (check2(m)) {
                R = m;
            } else {
                L = m;
            }
        }
        res[i] = min(check(L), check(R));
        ress2.first = min(ress2.first, i);
        ress2.second = i + 1;
    }
    return {res, ress2};
}

void solve() {
    cin >> s;
    n = s.size();
    cin >> x >> y;
    auto T = solve(0, n);
    cout << *min_element(all(T.first));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}