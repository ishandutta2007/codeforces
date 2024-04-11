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

const int maxN = 3e5 + 5;
vector<int> g[maxN];
int val[maxN];
vector<int> g2[maxN];
int used[maxN];
int pred[maxN];
int h[maxN];

void dfs(int v) {
    used[v] = 1;
    for(auto &u : g[v]) {
        if (used[u]) continue;
        pred[u] = v;
        h[u] = h[v] + 1;
        g2[v].push_back(u);
        dfs(u);
    }
}


void solve() {
    int n, m; cin >> n >> m;
    rep(_, m) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    int q; cin >> q;
    vector<vector<int>> answers;
    rep(_, q) {
        int a, b; cin >> a >> b;
        vi lp, rp;
        while(a != b) {
            if (h[a] > h[b]) {
                lp.push_back(a);
                val[a] ^= 1;
                a = pred[a];
            } else {
                rp.push_back(b);
                val[b] ^= 1;
                b = pred[b];
            }
        }
        lp.push_back(a);
        reverse(all(rp));
        for(auto &x : rp) lp.push_back(x);
        answers.push_back(lp);
    }
    bool ok = true;
    for(int i = 1; i <= n; ++i) {
        if (val[i] != 0) ok = false;
    }
    if (ok) {
        cout << "YES\n";
        for(auto &ve : answers) {
            cout << ve.size() << '\n';
            for(auto &v : ve) cout << v << ' ';
            cout << '\n';
        }
        return;
    }
    cout << "NO\n";
    int answer = 0;
    for(int i = 1; i <= n; ++i) {
        int cnt = 0;
        for(auto &u : g2[i]) {
            if (val[u]) cnt++;
        }
        answer -= cnt / 2;
        cnt %= 2;
        if (cnt == 0 && val[i] == 1) answer++;
    }
    cout << answer << '\n';
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