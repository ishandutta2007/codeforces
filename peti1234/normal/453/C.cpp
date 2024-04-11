#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, m, f[c];
vector<int> sz[c], sol;
bool v[c], par[c];
void add(int a) {
    par[a]=1-par[a];
    sol.push_back(a);
}
void dfs(int a) {
    v[a]=true;
    add(a);
    for (int x:sz[a]) {
        if (!v[x]) {
            f[x]=a;
            dfs(x);
            add(a);
        }
    }
    if (par[a]) {
        if (f[a]) {
            add(f[a]), add(a);
        } else sol.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        cin >> par[i];
    }
    for (int i=1; i<=n; i++) {
        if (par[i]) {
            if (sol.size()) {
                cout << -1;
                return 0;
            }
            dfs(i);
        }
    }
    cout << sol.size() << "\n";
    for (int i:sol) cout << i << " ";
    return 0;
}
/*
2 0
0 1
*/