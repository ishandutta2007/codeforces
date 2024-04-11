#include <bits/stdc++.h>

using namespace std;
int n, db;
bool p;
vector<int> sz[100002];
bool v[100002];
void dfs(int a, int ert) {
    v[a]=true;
    int cnt=0;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) dfs(x, ert+1);
        if (sz[x].size()==1) cnt++;
    }
    if (ert%2 && sz[a].size()==1) p=true;
    db+=max(0, cnt-1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        if (sz[i].size()==1) {
            dfs(i, 0);
            if (p) cout << 3 << " ";
            else cout << 1 << " ";
            cout << n-1-db << "\n";
            return 0;
        }
    }
    return 0;
}
// Kicsit bonyolultabb, de knny volt lerni.