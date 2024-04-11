#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    if (n * m == 1) {
        cout << 0;
        return 0;
    }
    if (m == 1) {
        for (int i = 0; i < n; i++) {
            cout << (i + 2) << "\n";
        }
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << (i + 1) * (n + 1 + j) << " ";
        }
        cout << "\n";
    }

    return 0;
}