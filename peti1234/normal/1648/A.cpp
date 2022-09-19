#include <bits/stdc++.h>

using namespace std;
const int c=100005;
long long n, m, ans, sor[c], oszlop[c], sdb[c], odb[c];
vector<vector<int>> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    sz.resize(n+1);
    for (int i=1; i<=n; i++) {
        sz[i].resize(m+1);
        for (int j=1; j<=m; j++) {
            cin >> sz[i][j];
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int x=sz[i][j];
            ans+=i*sdb[x]-sor[x];
            sdb[x]++, sor[x]+=i;
        }
    }
    for (int j=1; j<=m; j++) {
        for (int i=1; i<=n; i++) {
            int x=sz[i][j];
            ans+=j*odb[x]-oszlop[x];
            odb[x]++, oszlop[x]+=j;
        }
    }
    cout << ans << "\n";
    return 0;
}