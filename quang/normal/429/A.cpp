#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 1e5 + 1;

int n;
bool init[N], goal[N];
vector <int> a[N], ans;

void DFS(int u, int par, bool flip, bool pre_flip) {
    if((init[u] ^ flip) != goal[u]) {
        ans.push_back(u);
        flip ^= 1;
    }
    for(int i = 0; i < (int)a[u].size(); i++)
        if(par != a[u][i]) DFS(a[u][i], u, pre_flip, flip);
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) cin >> init[i];
    for(int i = 1; i <= n; i++) cin >> goal[i];
    DFS(1, 0, 0, 0);
    cout << ans.size() << endl;
    for(int i = 0; i < (int)ans.size(); i++) cout << ans[i] << endl;
    return 0;
}