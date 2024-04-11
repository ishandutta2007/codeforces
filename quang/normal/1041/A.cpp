#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int main() {
    int n;
    cin >> n;
    int mx = 0, mn = INF;
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        mx = max(mx, u);
        mn = min(mn, u);
    }
    cout << mx - mn + 1 - n << endl;
    return 0;
}