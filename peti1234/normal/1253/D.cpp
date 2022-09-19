#include <bits/stdc++.h>
 
using namespace std;
int maxi, db, n, m;
bool v[200001];
vector<int> sz[200001];
void dfs(int a)
{
    v[a]=true;
    maxi=max(maxi, a);
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            dfs(x);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b);
        sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            if (maxi>i) {
                db++;
            }
            dfs(i);
        }
    }
    cout << db << "\n";
    return 0;
}