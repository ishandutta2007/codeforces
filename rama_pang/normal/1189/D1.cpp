#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> deg(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        deg[u]++;
        deg[v]++;
    }

    for (int i = 0; i < n; i++) {
        if (deg[i] == 2) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;

}