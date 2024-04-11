#include <bits/stdc++.h>

using namespace std;
const int c=300002;
int w, n, m;
vector<int> sol, sz[c];
bool v[c], jo[c];
void dfs(int a) {
    v[a]=true;
    if (!jo[a]) {
        sol.push_back(a);
        jo[a]=true;
        for (int x:sz[a]) {
            jo[x]=1;
        }
    }
    for (int x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            sz[i].clear(), v[i]=0, jo[i]=0;
        }
        sol.clear();
        for (int i=1; i<=m; i++) {
            int a, b; cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        dfs(1);
        bool s=1;
        for (int i=1; i<=n; i++) {
            if (!v[i]) {
                s=0;
            }
        }
        if (!s) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << sol.size() << "\n";
            for (int i:sol) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}