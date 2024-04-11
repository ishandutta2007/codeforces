#include <bits/stdc++.h>

using namespace std;
long long w, n, m, u, ert, oo, mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=m; i++) {
            cin >> u >> u >> ert;
            oo|=ert;
        }
        for (int i=1; i<n; i++) {
            oo=2*oo%mod;
        }
        cout << oo%mod << "\n";
        oo=0;
    }
    return 0;
}