#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int deg[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    int found = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 2) {
            found = 1;
            break;
        }
    }
    cout << (found ? "NO" : "YES") << endl;
    return 0;
}