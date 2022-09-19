#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int n, m, cnt, l[c], r[c], ans[c], si[c][3];
vector<pair<int, int> > sz[c][3];
void solve(int a, int s) {
    while (sz[a][s].size()>0) {
        auto p=sz[a][s].back();
        sz[a][s].pop_back();
        int x=p.first, id=p.second;
        if (!ans[id]) {
            ans[id]=(l[id]==a ? 1 : 2);
            si[a][s]--, si[x][s]--;
            solve(x, s);
            return;
        }
    }
    if (si[a][3-s]%2) {
        solve(a, 3-s);
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        l[i]=a, r[i]=b;
        sz[a][c].push_back({b, i});
        sz[b][c].push_back({a, i});
        si[a][c]++, si[b][c]++;
    }
    for (int i=1; i<=n; i++) {
        cnt+=si[i][1]%2;
    }
    for (int i=1; i<=n; i++) {
        if ((si[i][1]+si[i][2])%2) solve(i, 1);
    }
    /*for (int i=1; i<=n; i++) {
        if (si[i][1]%2) solve(i, 1);
    }*/
    for (int i=1; i<=n; i++) {
        solve(i, 1);
        solve(i, 2);
    }
    cout << cnt << "\n";
    for (int i=1; i<=m; i++) {
        cout << ans[i];
    }
    cout << "\n";
    return 0;
}