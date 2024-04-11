#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1005;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

vector<int> g[maxN];
int m[maxN], k[maxN];
int ans[maxN][5000], h[maxN][5000];
int ok = 1;
int used[maxN][5000];

vector<int> current;
void dfs(int v, int c) {
    current.push_back(v);
    used[v][c] = 1;
    ans[v][c] = -1;
    int nxtc = (c + k[v]) % ok;
    if (nxtc < 0) nxtc += ok;
    int nxt = g[v][nxtc % m[v]];
    if (used[nxt][nxtc]) {
        if (ans[nxt][nxtc] == -1) {
            set<int> s;
            for(int i = h[nxt][nxtc]; i < (int)current.size(); ++i) {
                s.insert(current[i]);
            }
            ans[v][c] = s.size();
        }
        else ans[v][c] = ans[nxt][nxtc];
        return;
    }
    h[nxt][nxtc] = h[v][c] + 1;
    dfs(nxt, nxtc);
    ans[v][c] = ans[nxt][nxtc];
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> k[i];
    for (int i = 1; i <= n; ++i) {
        cin >> m[i];
        ok = ok * m[i] / __gcd(ok, m[i]);
        g[i].resize(m[i]);
        range(j, m[i]) cin >> g[i][j];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < ok; ++j) {
            if (!used[i][j]) {
                dfs(i, j);
                current.clear();
            }
        }
    }
    int q;
    cin >> q;
    range(_, q) {
        int x, y;
        cin >> x >> y;
        y %= ok;
        if (y < 0) y += ok;
        cout << ans[x][y] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}