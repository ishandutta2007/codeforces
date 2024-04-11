#include <iostream>

using namespace std;

int n, m, k;
int h[1222333];
int p = 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        h[x] = 1;
    }
    if (h[1]) {
        cout << "1\n";
        return 0;
    }
    for (int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        if (p == u) p = v;
        else if (p == v) p = u;
        if (h[p]) {
            cout << p << "\n";
            return 0;
        }
    }
    cout << p << "\n";
}