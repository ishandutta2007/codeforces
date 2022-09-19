#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, m, be[c], ki[c], ert[c], maxi;
vector<int> sz[c], sor;
bool v[c];
void dfs(int a) {
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
    }
    sor.push_back(a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b);
        ki[a]++, be[b]++;
    }
    for (int i=1; i<=n; i++) {
        dfs(i);
    }
    reverse(sor.begin(), sor.end());
    for (auto a:sor) {
        ert[a]=max(ert[a], 1);
        maxi=max(maxi, ert[a]);
        if (ki[a]>1) {
            for (auto x:sz[a]) {
                if (be[x]>1) {
                    ert[x]=max(ert[x], ert[a]+1);
                }
            }
        }
    }
    cout << maxi << "\n";
    return 0;
}