#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int v = 0;
    int u;
    for (int i = 1; i <= n; i++) {
        cin >> u;
        v = max(v, u);
    }
    v -= 25;
    if (v < 0) {
        v = 0;
    }
    cout << v << endl;
    return 0;
}