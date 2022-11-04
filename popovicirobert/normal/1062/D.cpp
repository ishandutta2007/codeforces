#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = (int) 1e5;

vector < pair <int, int> > g[2 * MAXN + 1];
bool vis[2 * MAXN + 1];

inline void addEdge(int x, int y, int c) {
    g[x].push_back({y, c});
    g[y].push_back({x, c});
}

int comp[2 * MAXN + 1], cur;

void dfs(int nod) {
    comp[nod] = cur;
    for(auto it : g[nod]) {
        if(comp[it.first] == 0) {
            dfs(it.first);
        }
    }
}

ll sol[2 * MAXN + 1];

int main() {
    //ifstream cin("C.in");
    //ofstream cout("C.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 2; 2 * i <= n; i++) {
        for(j = 2 * i; j <= n; j += i) {
            addEdge(i + n, j + n, j / i);
            addEdge(i + n, j, j / i);
            addEdge(i, j + n, j / i);
            addEdge(i, j, j / i);
        }
    }
    for(i = 0; i <= 2 * n; i++) {
        if(comp[i] == 0) {
            cur++;
            dfs(i);
        }
    }
    ll ans = 0;
    for(i = 0; i <= 2 * n; i++) {
        for(auto it : g[i]) {
            sol[comp[i]] += it.second;
        }
    }
    for(i = 0; i <= 2 * n; i++) {
        ans = max(ans, sol[i]);
    }
    cout << ans / 2;
    //cin.close();
    //cout.close();
    return 0;
}