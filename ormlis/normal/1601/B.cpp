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
#define f0r(a, b) for (int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
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

struct FSegTree {
    struct Node {
        int value;
        int ind;

        Node(int _val = INFi) : value(_val), ind(-1) {}

        void combine(const Node &a, const Node &b) {
            value = min(a.value, b.value);
            if (value == a.value) ind = a.ind;
            else ind = b.ind;
        }

        void apply(int x) {
            value = x;
        }
    };

    Node combine(const Node &a, const Node &b) {
        Node res;
        res.combine(a, b);
        return res;
    }

    vector<Node> t;
    int n;

    void build(int k) {
        n = k;
        t.resize(n * 2 + 2);
    }

    template<typename T>
    void build(vector<T> &v) {
        n = v.size();
        t.resize(n * 2 + 2);
        range(i, n) {
            t[i + n].ind = i;
            t[i + n].apply(v[i]);
        }
        for (int i = n - 1; i >= 0; --i) t[i].combine(t[i << 1], t[i << 1 | 1]);
    }

    void upd(int i, int x) {
        for (t[i += n].apply(x); i > 1; i >>= 1) t[i >> 1].combine(t[i], t[i ^ 1]);
    }

    // [l, r)
    Node get(int l, int r) {
        Node result;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) result = combine(result, t[l++]);
            if (r & 1) result = combine(result, t[--r]);
        }
        return result;
    }
};

void solve() {
    int n;
    cin >> n;
    vi a(n + 1), b(n + 1);
    rep(i, n) cin >> a[i + 1];
    rep(i, n) cin >> b[i + 1];
    vi c(n + 1);
    vi dist(n + 1, -1);
    vi pred(n + 1, -1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    rep(i, n + 1) {
        c[i] = i - a[i];
    }
    c[0] = INFi;
    vvi g(n + 1);
    rep(i, n + 1) {
        g[i + b[i]].push_back(i);
    }
    FSegTree st;
    st.build(c);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto &u : g[v]) {
            while (true) {
                auto cur = st.get(u, n + 1);
                if (cur.value > u) break;
                assert(cur.ind != -1);
                int j = cur.ind;
                pred[j] = u;
                dist[j] = dist[v] + 1;
                q.push(j);
                st.upd(j, INFi);
            }
        }
    }
    if (dist[n] == -1) {
        cout << "-1\n";
        return;
    }
    cout << dist[n] << '\n';
    int t = n;
    while (pred[t] != -1) {
        cout << pred[t] << ' ';
        t = pred[t];
        t += b[t];
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}