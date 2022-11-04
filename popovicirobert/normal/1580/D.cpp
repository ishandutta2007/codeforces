#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define Test(x) cout << "Case #" << x << ": ";
 
 
using namespace std;

constexpr ll INF = 1e18;
constexpr int MAXN = 4000;

ll dp[MAXN + 1][MAXN + 1];


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> g(n + 1);
    function<void(int, int, int)> makeTree = [&](int l, int r, int par) {
        if (l > r) return;

        int pos = l;
        for (int i = l; i <= r; i++) {
            if (a[i] < a[pos]) {
                pos = i;
            }
        }

        g[par].push_back(pos);
        makeTree(l, pos - 1, pos);
        makeTree(pos + 1, r, pos);
    };

    makeTree(1, n, 0);

    // for (int i = 1; i <= n; i++) {
    //     cerr << i << ": ";
    //     for (auto itr : g[i]) {
    //         cerr << itr << " ";
    //     }
    //     cerr << "\n";
    // }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = -INF;
        }
    }

    vector<int> size(n + 1);

    function<void(int)> dfs = [&](int node) {
        for (auto itr : g[node]) {
            dfs(itr);

            for (int tot = size[node] + size[itr]; tot >= 0; tot--) {
                for (int j = max(0, tot - size[node]); j <= min(tot, size[itr]); j++) {
                    int i = tot - j;
                    dp[node][tot] = max(dp[node][tot], dp[node][i] + dp[itr][j] -
                                                       2LL * i * j * a[node]);
                }
            }

            size[node] += size[itr];
        }

        for (int i = m - 1; i >= 0; i--) {
            dp[node][i + 1] = max(dp[node][i + 1],
                                  dp[node][i] + 1LL * (m - 1 - 2 * i) * a[node]);
        }

        size[node]++;
    };

    dfs(g[0].back());

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cerr << dp[i][j] << " ";
    //     }
    //     cerr << "\n";
    // }

    ll answer = 0;
    for (int i = 1; i <= n; i++) {
        answer = max(answer, dp[i][m]);
    }

    cout << answer;
    
    return 0;
}