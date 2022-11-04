#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

struct DSU {
    vector <int> par;
    inline void init(int n) {
        par.resize(n + 1);
    }
    int root(int x) {
        if(par[x] == 0) return x;
        return par[x] = root(par[x]);
    }
    inline void join(int x, int y) {
        x = root(x), y = root(y);
        if(x != y) {
            par[x] = y;
        }
    }
};

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    DSU dsu; dsu.init(n);
    vector <int> x(n + 1), y(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        for(j = i - 1; j >= 1; j--) {
            if(x[i] == x[j] || y[i] == y[j]) {
                dsu.join(i, j);
            }
        }
    }
    vector <int> vis(n + 1);
    int ans = 0;
    for(i = 1; i <= n; i++) {
        int nod = dsu.root(i);
        if(vis[nod] == 0) {
            ans++;
        }
        vis[nod] = 1;
    }
    cout << ans - 1;
    //cin.close();
    //cout.close();
    return 0;
}