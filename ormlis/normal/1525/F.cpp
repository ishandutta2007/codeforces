#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = 2e18 + 5;
const int INFi = 1e9;
const int maxN = 500 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

vector<int> g[maxN];
bool blocked[maxN];
int used[maxN];
int T = 1;
int mt[maxN];

bool kuhn(int v) {
    if (used[v] == T) return false;
    used[v] = T;
    for(auto &u : g[v]) {
        if (blocked[u]) continue;
        if (mt[u] == -1 || kuhn(mt[u])) {
            mt[u] = v;
            mt[v] = u;
            return true;
        }
    }
    return false;
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    range(_, m) {
        int a, b; cin >> a >> b;
        g[a].push_back(b + n);
        g[b + n].push_back(a);
    }
    for(int i = 1; i <= 2 * n; ++i) mt[i] = -1;
    vector<int> x(k + 1), y(k + 1);
    for(int i = 1; i <= k; ++i) cin >> x[i] >> y[i];
    int cur = 0;
    for(int i = 1; i <= n; ++i) {
        T++;
        if (kuhn(i)) cur++;
    }
    int d = n - cur;
    vector<vector<ll>> dp(k + 1, vector<ll> (n + 1, -INF));
    vector<vector<int>> p(k + 1, vector<int> (n + 1, -1));
    dp[0][d] = 0;
    for(int i = 1; i <= k; ++i) {
        for(int was = 0; was <= n; ++was) {
            if (dp[i - 1][was] == -INF) continue;
            for(int current = max(was, i + 1); current <= n; current++) {
                int ad = current - was;
                ll value = dp[i - 1][was] + max(0ll, 1ll * x[i] - 1ll * ad * y[i]);
                if (value >= dp[i][current]) {
                    dp[i][current] = value;
                    p[i][current] = was;
                }
            }
        }
    }
    vector<int> path;
    {
        int z = max(k + 1, d);
        for(int i = k; i >= 1; --i) {
            path.push_back(z - p[i][z]);
            z = p[i][z];
        }
        reverse(all(path));
    }
    vector<int> ans;
    for(auto &z : path) {
        range(_, z) {
            for (int i = 1; i <= n; ++i) {
                if (blocked[i]) continue;
                if (mt[i] == -1) continue;
                int a = i;
                int b = mt[i];
                mt[a] = mt[b] = -1;
                blocked[a] = true;
                T++;
                if (!kuhn(b)) {
                    ans.push_back(a);
                    break;
                }
                blocked[a] = false;
                a = b;
                b = mt[a];
                mt[a] = mt[b] = -1;
                blocked[a] = true;
                T++;
                assert(!kuhn(b));
                ans.push_back(-(a - n));
                break;
            }
        }
        ans.push_back(0);
    }
    cout << ans.size() << '\n';
    for(auto &ww : ans) cout << ww << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(2) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}