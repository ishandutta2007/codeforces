#include <bits/stdc++.h>


#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 1e6 + 30;
const int LG = 100;

struct segment_tree {
    int n{};
    vector<pair<ll, int>> tree{};

    void build(int k) {
        n = k;
        tree.resize(n * 4, {-INF, -1});
    }


    void upd(int v, int l, int r, int pos, ll x) {
        if (l > pos || r <= pos) return;
        if (l + 1 == r) {
            tree[v] = {x, l};
            return;
        }
        upd(v << 1, l, (l + r) >> 1, pos, x);
        upd((v << 1) + 1, (l + r) >> 1, r, pos, x);
        tree[v] = max(tree[v << 1], tree[(v << 1) + 1]);
    }

    pair<ll, int> get(int v, int l, int r, int lq, int rq) {
        if (l >= rq || r <= lq) return {-INF, -1};
        if (lq <= l && r <= rq) {
            return tree[v];
        }
        return max(get(v << 1, l, (l + r) >> 1, lq, rq),
                   get((v << 1) + 1, (l + r) >> 1, r, lq, rq));
    }

    void upd(int pos, ll x) {
        upd(1, 0, n, pos, x);
    }

    pair<ll, int> get(int lq, int rq) {
        return get(1, 0, n, lq, rq);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ar<int, 4>> qs(q);
    set<int> alive;
    rep(i, n) alive.insert(i);
    vector<int> w(n, INFi);
    rep(i, q) {
        cin >> qs[i][0];
        cin >> qs[i][1];
        if (qs[i][0] == 0) {
            cin >> qs[i][2] >> qs[i][3];
            if (qs[i][3] == 0) {
                int l = qs[i][1];
                int r = qs[i][2];
                l--;
                auto it = alive.lower_bound(l);
                while (it != alive.end() && (*it) < r) {
                    w[*it] = i;
                    it = alive.erase(it);
                }
            }
        } else {
            qs[i][2] = qs[i][3] = -1;
        }
    }
    vector<int> b(n, INFi);
    segment_tree st;
    st.build(n);
    rep(i, n) st.upd(i, w[i]);
    rep(i, q) {
        if (qs[i][0] == 0) {
            if (qs[i][3] == 0) continue;
            int l = qs[i][1];
            int r = qs[i][2];
            l--;
            auto it1 = alive.lower_bound(l);
            auto it2 = prev(alive.lower_bound(r));
            if ((*it1) != (*it2)) continue;
            auto res = st.get(l, r);
            ll d2 = -1;
            if (l < res.second) {
                d2 = max(d2, st.get(l, res.second).first);
            }
            if (res.second + 1 < r) {
                d2 = max(d2, st.get(res.second + 1, r).first);
            }
            assert(res.first == INFi);
            assert(d2 != INFi);
            b[res.second] = min(1ll * b[res.second], d2);
            assert(w[res.second] == INFi);
            assert(l <= res.second && res.second < r);
        } else {
            int j = qs[i][1];
            j--;
            if (w[j] < i) {
                cout << "NO\n";
                continue;
            }
            if (b[j] < i) {
                cout << "YES\n";
                continue;
            }
            cout << "N/A\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}