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

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 1e5 + 100;
const int LG = 20;

struct segment_tree {
    struct Node {
        ll val = INF;
        ll upd = 0;

        void combine(const Node &a, const Node &b) {
            val = min(a.val, b.val) + upd;
        }
    };

    vector<Node> tree{};
    int n{};

    void build(int k) {
        n = k;
        tree.resize(n * 4);
    }

    void upd(int v, int l, int r, int lq, int rq, ll val) {
        if (l >= rq || r <= lq) return;
        if (lq <= l && r <= rq) {
            tree[v].val += val;
            tree[v].upd += val;
            return;
        }
        upd(v << 1, l, (l + r) >> 1, lq, rq, val);
        upd(v << 1 | 1, (l + r) >> 1, r, lq, rq, val);
        tree[v].combine(tree[v << 1], tree[v << 1 | 1]);
    }

    ll get() {
        return tree[1].val;
    }

    void upd(int lq, int rq, ll val) {
        upd(1, 0, n, lq, rq, val);
    }
};

segment_tree ST[LG];
ll dp[maxN][LG];
vector<int> divs[maxN];
int phi[maxN];
int mp[maxN];
vector<int> primes;

void preclac() {
    for (int i = 2; i < maxN; ++i) {
        if (!mp[i]) {
            mp[i] = i;
            primes.push_back(i);
            phi[i] = i - 1;
        }
        for (auto &p : primes) {
            if (p > mp[i] || p * i >= maxN) break;
            mp[p * i] = p;
            if (p == mp[i]) {
                phi[p * i] = phi[i] * p;
            } else {
                phi[p * i] = phi[i] * (p - 1);
            }
        }
    }
    rep(i, LG) {
        ST[i].build(maxN);
        ST[i].upd(0, 1, -INF);
    }
    for (int i = 1; i < maxN; ++i) for (int j = i; j < maxN; j += i) divs[j].push_back(i);
    for (int k = 1; k < maxN; ++k) {
        for (int to = LG - 1; to >= 1; --to) {
            for (auto &d : divs[k]) {
                ST[to - 1].upd(0, d, phi[k / d]);
            }
            dp[k][to] = ST[to - 1].get();
            ST[to].upd(k, k + 1, -INF + dp[k][to]);
        }
    }
}

void solve() {
    int n, k; cin >> n >> k;
    cout << dp[n][min(LG - 1, k)] + n << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    preclac();
    range(i, t) {
        solve();
    }
    return 0;
}