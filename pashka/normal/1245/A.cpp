#include <bits/stdc++.h>

#define long long long int

using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        while (y > 0) {
            int q = x % y;
            x = y;
            y = q;
        }
        if (x != 1) {
            cout << "Infinite\n";
        } else {
            cout << "Finite\n";
        }
    }

    return 0;
}