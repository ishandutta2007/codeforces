#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

struct DSU {

    vector <int> par, sz;
    int n;

    inline void init(int _n) {
        n = _n;
        par.resize(n + 1), sz.resize(n + 1, 1);
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
            sz[y] += sz[x];
        }
    }

};

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    DSU dsu[2]; dsu[0].init(n), dsu[1].init(n);

    for(i = 1; i < n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        dsu[c].join(x, y);
    }

    vector < vector <bool> > vis(2, vector <bool>(n + 1));

    ll ans = 0;
    for(i = 1; i <= n; i++) {
        int a = dsu[0].root(i), b = dsu[1].root(i);

        ans += 1LL * (dsu[0].sz[a] - 1) * (dsu[1].sz[b] - 1);

        if(vis[0][a] == 0) {
            vis[0][a] = 1;
            ans += 1LL * dsu[0].sz[a] * (dsu[0].sz[a] - 1);
        }
        if(vis[1][b] == 0) {
            vis[1][b] = 1;
            ans += 1LL * dsu[1].sz[b] * (dsu[1].sz[b] - 1);
        }
    }

    cout << ans;

    //cin.close();
    //cout.close();
    return 0;
}