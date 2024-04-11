#include <bits/stdc++.h>

using namespace std;
vector<int> sz[500001];
bool v[500001];
int t[5000001][2];
int n, ln=2;
void dfs(int a, int ert)
{
    v[a]=true;
    int si=sz[a].size();
    ln+=si;
    int db=0;
    t[a][0]=ert, t[a][1]=ln;
    ert=ln;
    for (int i=0; i<sz[a].size(); i++) {
        int x=sz[a][i];
        if (!v[x]) {
            db++;
            dfs(x, ert-db);
        }
    }
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
    dfs(1, 1);
    for (int i=1; i<=n; i++) cout << t[i][0] << " " << t[i][1] << "\n";
    return 0;
}