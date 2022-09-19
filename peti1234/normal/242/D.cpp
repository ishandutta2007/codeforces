#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, m, t[c];
vector<int> sz[c], sol, mex;
void dfs(int a) {
    sol.push_back(a);
    t[a]--;
    for (int i:sz[a]) {
        t[i]--;
        if (!t[i]) {
            dfs(i);
        }
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
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        if (!t[i]) {
            dfs(i);
        }
    }
    cout << sol.size() << "\n";
    for (int i:sol) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}