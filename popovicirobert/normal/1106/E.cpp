#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const ll INF = 1e18;
const int MAXN = (int) 1e5 + 5;
const int MAXM = 200;

struct Data {
    int s, t, d, w;
    bool operator <(const Data &other) const {
        if(w == other.w)
            return d > other.d;
        return w > other.w;
    }
}arr[MAXN + 1];

struct DSU {
    vector <int> par;
    int n;
    DSU(int _n) {
        n = _n;
        par.resize(n + 1);
    }
    int root(int x) {
        if(par[x] == 0)
            return x;
        return par[x] = root(par[x]);
    }
    inline void join(int x, int y) {
        x = root(x), y = root(y);
        if(x != y) {
            par[x] = y;
        }
    }
};

int id[MAXN + 1];
ll dp[MAXN + 1][MAXM + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for(i = 1; i <= k; i++) {
        cin >> arr[i].s >> arr[i].t >> arr[i].d >> arr[i].w;
    }
    sort(arr + 1, arr + k + 1);
    DSU dsu(n + 1);
    for(i = 1; i <= k; i++) {
        int pos = arr[i].s;
        pos = dsu.root(pos);
        while(pos <= arr[i].t) {
            id[pos] = i;
            dsu.join(pos, pos + 1);
            pos = dsu.root(pos);
        }
    }
    for(i = 2; i <= n + 1; i++) {
        for(j = 0; j <= m; j++) {
            dp[i][j] = INF;
        }
    }
    ll ans = INF;
    for(i = 1; i <= n; i++) {
        for(j = 0; j <= m; j++) {
            if(j > 0) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            }
            if(j < m) {
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
            }
            if(id[i] > 0) {
                dp[i][j] += arr[id[i]].w;
            }
            if(id[i] > 0) {
                dp[arr[id[i]].d + 1][j] = min(dp[arr[id[i]].d + 1][j], dp[i][j]);
            }
            else {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            }
        }
    }
    cout << dp[n + 1][m];
    //cin.close();
    //cout.close();
    return 0;
}