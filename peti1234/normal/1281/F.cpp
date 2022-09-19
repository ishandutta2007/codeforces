#include <bits/stdc++.h>

using namespace std;
#define pll pair<long long, long long>
const int c=3002;
int w, n, m, dif[c], rf[c];
long long sok=1e15;
pll op[c][c], cl[c][c];
vector<int> sz[c];
bool v[c];
pll add(pll a, pll b) {
    return {a.first+b.first, a.second+b.second};
}
void dfs(int a) {
    v[a]=true;
    rf[a]=1;
    for (int i=0; i<=n; i++) {
        op[a][i]={-sok, -sok};
    }
    op[a][1]={0, dif[a]};
    for (int x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            rf[a]+=rf[x];
            for (int db=rf[a]; db>=1; db--) {
                op[a][db]=max(add(op[a][db], op[x][1]), add(op[a][db-1], cl[x][1]));
                for (int i=max(2, db-rf[a]+rf[x]); i<=min(rf[x], db); i++) {
                    op[a][db]=max({op[a][db], add(op[a][db-i], cl[x][i]), add(op[a][db-i+1], op[x][i])});
                }
            }
        }
    }
    for (int i=1; i<=rf[a]; i++) {
        cl[a][i]={op[a][i].first+(op[a][i].second>0), 0};
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            dif[i]=-x;
        }
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            dif[i]+=x;
        }
        for (int i=1; i<n; i++) {
            int a, b;
            cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        dfs(1);
        cout << cl[1][m].first << "\n";
        for (int i=1; i<=n; i++) {
            v[i]=0;
            sz[i].clear();
        }
    }
    return 0;
}