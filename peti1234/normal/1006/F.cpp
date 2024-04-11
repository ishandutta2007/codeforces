#include <bits/stdc++.h>

using namespace std;
long long n, m, k, ans, t[21][21], f;
map<pair<int, long long>, int> db;
void solve(int a, int b, long long ert) {
    ert^=t[a][b];
    if (a+b==f) {
        db[{a, ert}]++;
    } else {
        if (a+1<=n) solve(a+1, b, ert);
        if (b+1<=m) solve(a, b+1, ert);
    }
}
void solve2(int a, int b, long long ert) {
    if (a+b==f) {
        ans+=db[{a, ert}];
    } else {
        ert^=t[a][b];
        if (a-1>=1) solve2(a-1, b, ert);
        if (b-1>=1) solve2(a, b-1, ert);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    f=min(n, m)+1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> t[i][j];
        }
    }
    solve(1, 1, k);
    solve2(n, m, 0);
    cout << ans << "\n";
    return 0;
}