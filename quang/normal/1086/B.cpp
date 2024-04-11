#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, s;
int deg[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++, deg[v]++;
    }
    if (n == 2) {
        cout << s << endl;
        return 0;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            cnt++;
        }
    }
    cout << fixed << setprecision(10) << (double)s * 2 / cnt << endl;
    return 0;
}