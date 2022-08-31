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
const int maxN = 2e5 + 1;
const int md = 1e9 + 7;

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

vector<ar<int, 3>> g[maxN];
int dist[maxN];
bool was[maxN];
int ans[maxN];
int st10[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};

int len(int num) {
    int r = 0;
    while(num) {
        r++;
        num /= 10;
    }
    return r;
}

int get_char(int num, int len, int i) {
    return (num / st10[len - i - 1]) % 10;
}

void dfs(vector<ar<int, 4>> &kek, int cur) {
    vector<vector<ar<int, 4>>> nxt(10);
    for(auto [to, num, i, len] : kek) {
        i++;
        if (was[to]) continue;
        if (i == len) {
            was[to] = true;
            ans[to] = cur;
            for(auto &[u, cost, num2] : g[to]) {
                if (was[u] || dist[to] + cost != dist[u]) continue;
                ar<int, 4> ed = {u, num2, 0, cost};
                nxt[get_char(num2, cost, 0)].push_back(ed);
            }
        } else {
            nxt[get_char(num, len, i)].push_back({to, num, i, len});
        }
    }
    range(num, 10) {
        if (nxt[num].empty()) continue;
        dfs(nxt[num], add(mul(cur, 10), num));
    }
}

void solve() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int x, y; cin >> x >> y;
        g[x].push_back({y, len(i), i});
        g[y].push_back({x, len(i), i});
    }
    set<pair<int, int>> q;
    for(int i = 1; i <= n; ++i) {
        dist[i] = INFi;
        if (i == 1) {
            dist[i] = 0;
        }
        q.insert({dist[i], i});
    }
    while(!q.empty()) {
        auto [d, v] = *q.begin();
        q.erase(q.begin());
        for(auto &[u, cost, i] : g[v]) {
            if (dist[u] > d + cost) {
                q.erase({dist[u], u});
                dist[u] = d + cost;
                q.insert({dist[u], u});
            }
        }
    }
    vector<ar<int, 4>> st = {{1, -1, 0, 1}};
    dfs(st, 0);
    for(int i = 2; i <= n; ++i) cout << ans[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;

    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}