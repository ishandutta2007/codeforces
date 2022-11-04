#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

vector <int> g[MAXN + 1];
int weight[MAXN + 1], ans;
bool vis[MAXN + 1];

void dfs(int nod) {
    vis[nod] = 1;
    weight[nod] = 1;
    for(auto it : g[nod]) {
        if(vis[it] == 0) {
            dfs(it);
            weight[nod] += weight[it];
        }
    }
    ans += 1 - weight[nod] % 2;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, x, y;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if(n % 2 == 1) {
        cout << -1;
        return 0;
    }
    dfs(1);
    cout << ans - 1;
    //cin.close();
    //cout.close();
    return 0;
}