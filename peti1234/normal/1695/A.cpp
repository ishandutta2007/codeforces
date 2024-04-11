#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, m, maxi=-2e9, sor=0, oszlop=0;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int x;
            cin >> x;
            if (x>maxi) {
                maxi=x;
                sor=i, oszlop=j;
            }
        }
    }
    cout << max(sor, n+1-sor)*max(oszlop, m+1-oszlop) << "\n";
}



int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}