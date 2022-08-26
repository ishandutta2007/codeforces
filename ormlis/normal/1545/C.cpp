#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll INF = 2e18;
const int INFi = 2e9 + 5;
const int maxN = 1500 + 1;
const int md = 998244353;


inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

int rev(int a) {
    return binpow(a, md - 2);
}

const int maxF = 2e5 + 5;
int fact[maxF];
int rfact[maxF];

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxF; ++i) fact[i] = mul(fact[i - 1], i);
    rfact[maxF - 1] = rev(fact[maxF - 1]);
    for (int i = maxF - 1; i >= 1; --i) {
        rfact[i - 1] = mul(rfact[i], i);
    }
}

int C(int n, int k) {
    if (k < 0 || n < k) return 0;
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

int T(int n, int k) {
    return C(n + k - 1, k - 1);
}

vector<int> g[maxN];
int col[maxN];
int cnt[3];
void dfs(int v, int c) {
    col[v] = c;
    cnt[c]++;
    for (auto &u : g[v]) {
        if (col[u] == 0) {
            dfs(u, c ^ 3);
        }
        if ((col[v] ^ col[u]) != 3) {
            assert(0);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n * 2, vector<int>(n));
    range(i, n * 2) range(j, n) cin >> a[i][j];
    range(i, n * 2) range(j, n) a[i][j]--;
    vector<vector<set<int>>> to(n, vector<set<int>>(n));
    vector<vector<bool>> used(n, vector<bool>(n));
    vector<int> c(n * 2, 0);
    // 0 - neutral
    // 1 - always good
    // -1 - always bad
    range(i, n * 2) {
        range(j, n) {
            to[j][a[i][j]].insert(i);
        }
    }
    queue<pair<int, int>> q;
    bool bad = false;
    int cntGood = 0;
    int cntBad = 0;
    auto DoGood = [&](int i) {
        c[i] = 1;
        cntGood++;
        range(j, n) {
            to[j][a[i][j]].erase(i);
            if (used[j][a[i][j]]) bad = true;
            used[j][a[i][j]] = true;
            q.push({j, a[i][j]});
        }
    };
    auto DoBad = [&](int i) {
        c[i] = -1;
        cntBad++;
        range(j, n) {
            to[j][a[i][j]].erase(i);
            if (!used[j][a[i][j]] && to[j][a[i][j]].size() == 1) {
                q.push({j, a[i][j]});
            }
        }
    };
    range(s, n) {
        range(v, n) {
            q.push({s, v});
        }
    }
    while (!q.empty()) {
        auto[s, v] = q.front();
        q.pop();
        if (used[s][v]) {
            while (!to[s][v].empty()) {
                int x = *to[s][v].begin();
                DoBad(x);
            }
        } else if (to[s][v].size() == 1) {
            int x = *to[s][v].begin();
            DoGood(x);
        }
    }
    int cntEdges2 = 0;
    range(i, n * 2) {
        g[i].clear();
        col[i] = 0;
    }
    range(j, n) {
        range(v, n) {
            if (used[j][v]) continue;
            assert(to[j][v].size() == 2);
            if (to[j][v].size() > 2) continue;
            int x = *to[j][v].begin();
            int y = *to[j][v].rbegin();
            cntEdges2++;
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }
    int ans = 1;
    range(i, n * 2) {
        if (col[i] || c[i] != 0) continue;
        cnt[1] = cnt[2] = 0;
        dfs(i, 1);
        //cout << cnt[1] << ' ' << cnt[2] << '\n';
        ans = mul(ans, 2);
    }
    assert(!bad);
//    cout << n << ' ' << cntGood << ' ' << cntBad << ' ' << cntEdges2 << '\n';
    cout << ans << '\n';
    range(i, n * 2) {
        if (col[i] == 1 || c[i] == 1) cout << i + 1 << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    init();
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}