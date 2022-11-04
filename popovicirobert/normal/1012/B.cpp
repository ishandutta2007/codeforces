#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

vector <int> g[2 * MAXN + 1];
bool vis[2 * MAXN + 1];

void dfs(int nod) {
    vis[nod] = 1;
    for(auto it : g[nod]) {
        if(vis[it] == 0) {
            dfs(it);
        }
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, q;
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for(i = 1; i <= q; i++) {
        int r, c;
        cin >> r >> c;
        g[r].push_back(c + n);
        g[c + n].push_back(r);
    }
    int ans = 0;
    for(i = 1; i <= n + m; i++) {
        if(!vis[i]) {
            dfs(i);
            ans++;
        }
    }
    cout << ans - 1;
    //cin.close();
    //cout.close();
    return 0;
}