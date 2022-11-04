#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = (int) 3e5;

ll aib[MAXN + 1];

inline void update(int pos, int val) {
    pos = min(pos, MAXN);
    for(int i = pos; i > 0; i -= lsb(i)) {
        aib[i] += val;
    }
}

inline ll query(int pos, int n) {
    ll ans = 0;
    for(int i = pos; i <= n; i += lsb(i)) {
        ans += aib[i];
    }
    return ans;
}

vector <int> g[MAXN + 1];


vector < pair <int, int> > upd[MAXN + 1];
ll sol[MAXN + 1];

void dfs(int nod, int par, int lvl) {
    for(auto it : upd[nod]) {
        update(lvl + it.second, it.first);
    }
    sol[nod] = query(lvl, MAXN);
    for(auto it : g[nod]) {
        if(it != par) {
            dfs(it, nod, lvl + 1);
        }
    }
    for(auto it : upd[nod]) {
        update(lvl + it.second, -it.first);
    }
}

int main() {
    //ifstream cin("C.in");
    //ofstream cout("C.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin >> m;
    for(i = 1; i <= m; i++) {
        int v, d, x;
        cin >> v >> d >> x;
        upd[v].push_back({x, d});
    }
    dfs(1, 0, 1);
    for(i = 1; i <= n; i++) {
        cout << sol[i] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}