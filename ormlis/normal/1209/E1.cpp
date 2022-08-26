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
const int md = 998244353;

vector<int> g[maxN];
bool was[maxN];
int edg = 0;
int vert = 0;
void dfs(int v) {
    vert++;
    edg += g[v].size();
    was[v] = true;
    for(auto &u : g[v]) {
        if (was[u]) continue;
        dfs(u);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(m, vector<int> (n));
    range(i, n) {
        range(j, m) {
            cin >> a[j][i];
        }
    }
    vector<int> mx(m);
    range(i, m) mx[i] = *max_element(all(a[i]));
    vector<int> ord(m);
    iota(all(ord), 0);
    sort(all(ord), [&] (const int &i, const int &j) {
        return mx[i] > mx[j];
    });
    if (m > n) {
        ord.resize(n);
    }
    int ans = 0;
    function<void(int)> rec = [&] (int i) {
        if (i == (int)ord.size()) {
            int res = 0;
            range(j, n) {
                int w = 0;
                for(auto &e : ord) w = max(w, a[e][j]);
                res += w;
            }
            ans = max(ans, res);
            return;
        }
        int j = ord[i];
        range(_, n) {
            rec(i + 1);
            range(t, n - 1) {
                swap(a[j][t], a[j][t + 1]);
            }
        }
    };
    rec(0);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}