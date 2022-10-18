#ifdef ONPC
    #define _GLIBCXX_DEBUG
    #define deb(a) cerr << "@@@@@@@ " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
#define char unsigned char

using namespace std;
mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

const int N = 112345;
ll dp[2][N];
ll val[2][N];
vector<int> g[N];

void dfs(int v, int pr) {
    dp[0][v] = dp[1][v] = 0;
    for (int u : g[v]) {
        if (u != pr) {
            dfs(u, v);
            for (int i = 0; i < 2; i++) {
                dp[i][v] += max(dp[0][u] + abs(val[0][u] - val[i][v]), dp[1][u] + abs(val[1][u] - val[i][v]));
            }
        }
    }
}

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        g[i].clear();
        cin >> val[0][i] >> val[1][i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(0, 0);
    cout << max(dp[0][0], dp[1][0]) << '\n';
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}