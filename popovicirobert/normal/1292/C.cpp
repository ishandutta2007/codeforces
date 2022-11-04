#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define uint unsigned int


using namespace std;

const int MAXN = 3000;

vector <int> g[MAXN + 1];

ll dp[MAXN + 1][MAXN + 1];
int idl[MAXN + 1], idr[MAXN + 1], id;
int sz[MAXN + 1];
int coef[MAXN + 1][MAXN + 1], dst[MAXN + 1][MAXN + 1];

void dfs(int nod, int par, int *dst) {
    sz[nod] = 1, idl[nod] = ++id;
    dst[nod] = dst[par] + 1;
    for(auto it : g[nod]) {
        if(it != par) {
            dfs(it, nod, dst);
            sz[nod] += sz[it];
        }
    }
    idr[nod] = id;
}

void dfs1(int nod, int par, int root, int up) {
    for(auto it : g[nod]) {
        if(it != par) {
            int cur = up;
            if(root == nod) {
                cur = sz[root] - sz[it];
            }
            coef[root][it] = cur * sz[it];
            dfs1(it, nod, root, cur);
        }
    }
}

int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for(i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    auto get = [&](int a, int b) {
        return coef[a][b];
    };

    for(i = n; i >= 1; i--) {
        dst[i][0] = -1, id = 0;
        dfs(i, 0, dst[i]);
        dfs1(i, 0, i, -1);
    }

    queue < pair <int, int> > Q;
    for(i = 1; i <= n; i++) {
        for(auto it : g[i]) {
            if(i < it) {
                Q.push({i, it});
                dp[i][it] = get(i, it);
            }
        }
    }

    while(Q.size()) {
        auto cur = Q.front();
        Q.pop();


        for(auto it : g[cur.first]) {
            if(dst[it][cur.second] > dst[cur.first][cur.second]) {
                if(dp[it][cur.second] == 0) {
                    Q.push({it, cur.second});
                }
                dp[it][cur.second] = max(dp[it][cur.second], dp[cur.first][cur.second] + get(it, cur.second));
            }
        }
        for(auto it : g[cur.second]) {
            if(dst[cur.first][it] > dst[cur.first][cur.second]) {
                if(dp[cur.first][it] == 0) {
                    Q.push({cur.first, it});
                }
                dp[cur.first][it] = max(dp[cur.first][it], dp[cur.first][cur.second] + get(cur.first, it));
            }
        }
    }

    ll ans = 0;
    for(i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;

    return 0;
}