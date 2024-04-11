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
const int maxN = 2e5 + 5;
const int LG = 20;


struct aho_corasik {
    struct Node {
        map<char, int> to{}, go{};
        int link = -1;
        int p = 0;
        char ch = 0;
        int t = -1;
    };

    vector<Node> trie{};

    void build() {
        trie.emplace_back();
    }

    int add(string &s, int i) {
        int v = 0;
        for (auto &c: s) {
            if (!trie[v].to.count(c)) {
                trie[v].to[c] = trie.size();
                trie.emplace_back();
                trie.back().p = v;
                trie.back().ch = c;
            }
            v = trie[v].to[c];
        }
        trie[v].t = i;
        return v;
    }

    void build_suf_links() {
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            link(v);
            for (auto &[c, u] : trie[v].to) {
                q.push(u);
            }
        }
    }

    int link(int v) {
        if (trie[v].link != -1) return trie[v].link;
        if (v == 0 || trie[v].p == 0) return trie[v].link = 0;
        trie[v].link = go(link(trie[v].p), trie[v].ch);
        return trie[v].link;
    }

    int go(int v, char c) {
        if (trie[v].go.count(c)) return trie[v].go[c];
        if (trie[v].to.count(c)) return trie[v].go[c] = trie[v].to[c];
        if (v == 0) return trie[v].to[c] = 0;
        return trie[v].to[c] = go(link(v), c);
    }
};

void solve() {
    string s; cin >> s;
    int q; cin >> q;
    int n = s.size();
    vi k(q);
    vec<str> t(q);
    vvi qq(n + 1);
    rep(i, q) {
        cin >> k[i] >> t[i];
        qq[t[i].size()].push_back(i);
    }
    vvi pos(q);
    for(int len = 1; len <= n; ++len) {
        if (qq[len].empty()) continue;
        aho_corasik aho;
        aho.build();
        for(auto &i : qq[len]) {
            aho.add(t[i], i);
        }
        aho.build_suf_links();
        int v = 0;
        rep(i, n) {
            v = aho.go(v, s[i]);
            if (aho.trie[v].t != -1) {
                pos[aho.trie[v].t].push_back(i);
            }
        }
    }
    rep(i, q) {
        int ans = INFi;
        for(int j = 0; j + k[i] <= pos[i].size(); ++j) {
            int res = pos[i][j + k[i] - 1] - pos[i][j] + (int)t[i].size();
            ans = min(ans, res);
        }
        if (ans == INFi) {
            cout << "-1\n";
            continue;
        }
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}