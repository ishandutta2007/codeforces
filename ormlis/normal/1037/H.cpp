#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using i128 = __int128;
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

const int INFi = 1e9;
const ll INF = 2e18;
const int LG = 20;
const int maxN = 2e5 + 10;


struct suf_mas {
    int n;
    vector<int> s;
    vector<int> c, p, lcp;

    suf_mas(vector<int> &as) {
        s = as;
        s.push_back(-1);
        n = s.size();
        p.resize(n);
        c.resize(n);
        lcp.resize(n);
        vector<pair<int, int>> a(n);
        range(i, n)a[i] = {s[i], i};
        sort(all(a));
        range(i, n)p[i] = a[i].second;
        for (int i = 1; i < n; ++i) c[p[i]] = c[p[i - 1]] + (a[i].first != a[i - 1].first);
        for (int k = 0; (1 << k) < n; ++k) get(k);
        build_lcp();
    }

    void build_lcp() {
        int k = 0;
        range(i, n - 1) {
            int x = c[i];
            int j = p[x - 1];
            while (s[i + k] == s[j + k]) k++;
            lcp[x] = k;
            k = max(0, k - 1);
        }
    }

    void c_sort() {
        vector<int> cnt(n), pos(n);
        for (auto x: p) cnt[c[x]]++;
        for (int i = 1; i < n; ++i) pos[i] = pos[i - 1] + cnt[i - 1];
        vector<int> res(n);
        for (auto x: p) res[pos[c[x]]++] = x;
        p = res;
    }

    void get(const int &k) {
        range(i, n)p[i] = (p[i] - (1 << k) + n) % n;
        c_sort();
        vector<int> c_res(n);
        c_res[p[0]] = 0;
        for (int i = 1; i < n; ++i) {
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
            pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            c_res[p[i]] = c_res[p[i - 1]] + (prev != now);
        }
        c = c_res;
    }
};

struct segment_tree {
    struct Node {
        int min_L;
        int min_len;
        int min_R;

        void init_L(int x) {
            min_L = x;
            min_R = min_len + x;
        }

        void init_len(int x) {
            min_len = x;
            min_R = min_L + x;
        }

        void combine(const Node &a, const Node &b) {
            min_L = min(a.min_L, b.min_L);
            min_len = min(a.min_len, b.min_len);
            min_R = min({a.min_R, b.min_R, a.min_len + b.min_L});
        }

        Node() : min_L(INFi), min_len(INFi), min_R(INFi) {}
    };

    vector<Node> t{};
    int n{};

    void build(vi a) {
        n = a.size();
        t.resize(n * 4);
        make(1, 0, n, a);
    }

    void make(int v, int l, int r, vi &a) {
        if (l + 1 == r) {
            t[v].init_len(a[l]);
            return;
        }
        make(v << 1, l, (l + r) >> 1, a);
        make(v << 1 | 1, (l + r) >> 1, r, a);
        t[v].combine(t[v << 1], t[v << 1 | 1]);
    }

    void upd(int v, int l, int r, int &pos, int &val) {
        if (l > pos || r <= pos) return;
        if (l + 1 == r) {
            t[v].init_L(val);
            return;
        }
        upd(v << 1, l, (l + r) >> 1, pos, val);
        upd(v << 1 | 1, (l + r) >> 1, r, pos, val);
        t[v].combine(t[v << 1], t[v << 1 | 1]);
    }

    int get(int v, int l, int r, int lq, int R, int &len) {
        if (r <= lq) return -1;
        if (l >= lq && min(t[v].min_R, t[v].min_L + len) > R) {
            len = min(len, t[v].min_len);
            return -1;
        }
        if (l + 1 == r) return t[v].min_L;
        int a = get(v << 1, l, (l + r) >> 1, lq, R, len);
        if (a != -1) return a;
        return get(v << 1 | 1, (l + r) >> 1, r, lq, R, len);
    }

    int get(int lq, int R) {
        int len = INFi;
        return get(1, 0, n, lq, R, len);
    }

    void upd(int pos, int val) {
        upd(1, 0, n, pos, val);
    }
};

void solve() {
    string s; cin >> s;
    vi cur;
    int n = s.size();
    rep(i, n) cur.push_back(int(s[i]) + 1e6);
    int q; cin >> q;
    vi L(q), R(q);
    vi len(q), start(q);
    rep(i, q) {
        cin >> L[i] >> R[i];
        L[i]--;
        R[i]--;
        string x; cin >> x;
        cur.push_back(i + 1);
        start[i] = cur.size();
        len[i] = x.size();
        for(auto c : x) cur.push_back(int(c) + 1e6);
    }
    cur.push_back(q + 1);
    suf_mas SA(cur);
    segment_tree st;
    st.build(SA.lcp);
    vvi to(n);
    vi ans(q);
    rep(i, q) to[L[i]].push_back(i);
    for(int l = n - 1; l >= 0; --l) {
        st.upd(SA.c[l], l);
        for(auto j : to[l]) {
            ans[j] = st.get(SA.c[start[j]] + 1, R[j]);
        }
    }
    rep(i, q) {
        if (ans[i] == -1) {
            cout << "-1\n";
        } else {
            rep(j, len[i] + 1) {
                cout << s[ans[i] + j];
                if (cur[ans[i] + j] != cur[start[i] + j]) break;
            }
            cout << '\n';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(15) << fixed;
    int t = 1;
//    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}