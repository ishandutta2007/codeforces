#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 5000 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

vector<int> g[maxN];
int used[maxN];
bool bad = false;
pair<vector<int>, vector<int>> comp = {{}, {}};

pair<int, int> dfs(int v, int c) {
    used[v] = c;
    pair<int, int> res = {0, 0};
    if (c == 1) {
        res.first++;
        comp.first.push_back(v);
    } else {
        res.second++;
        comp.second.push_back(v);
    }
    c = c % 2 + 1;
    for (auto &u: g[v]) {
        if (used[u] == c) continue;
        if (used[u]) {
            bad = true;
            continue;
        }
        auto p = dfs(u, c);
        res.first += p.first;
        res.second += p.second;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    range(i, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<pair<int, int>> ps;
    vector<pair<vector<int>, vector<int>>> comps;
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            ps.push_back(dfs(i, 1));
            comps.push_back(comp);
            comp.first.clear();
            comp.second.clear();
        }
    }
    if (bad) {
        cout << "NO\n";
        return;
    }
    vector<vector<bool>> dp(ps.size() + 1, vector<bool>(n + 1));
    vector<vector<int>> pref(ps.size() + 1, vector<int>(n + 1,-1));
    dp[0][0] = true;
    range(j, ps.size()) {
        range(i, n + 1) {
            if (dp[j][i]) {
                dp[j + 1][i + ps[j].first] = true;
                pref[j + 1][i + ps[j].first] = 0;
                dp[j + 1][i + ps[j].second] = true;
                pref[j + 1][i + ps[j].second] = 1;
            }
        }
    }
    if (!dp[ps.size()][n2]) {
        cout << "NO\n";
        return;
    }
    vector<int> u(n+1);
    vector<pair<int, int>> vz;
    int cur = n2;
    for(int j = ps.size(); j > 0; --j) {
        if (pref[j][cur] == 0) {
            vz.push_back({j-1, 0});
            cur -= ps[j-1].first;
        } else if (pref[j][cur] == 1) {
            vz.push_back({j-1, 1});
            cur -= ps[j-1].second;
        }
    }
    for(auto&p: vz) {
        if (p.second == 0) {
            for (auto &v: comps[p.first].first) {
                u[v] = 2;
            }
        } else {
            for(auto &v: comps[p.first].second) {
                u[v] = 2;
            }
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; ++i) {
        if (u[i]) {
            cout << u[i] << "";
            continue;
        }
        if (n1 > 0) cout << 1 << "";
        else cout << "3";
        n1--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}