#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    cout << 4 + 3 * n << "\n";
    for (int i = 0; i < n; i++) {
        cout << i << " " << i + 1 << "\n";
        cout << i + 1 << " " << i + 1 << "\n";
        cout << i + 2 << " " << i + 1 << "\n";
    }
    cout << "0 0\n";
    cout << "1 0\n";
    cout << n << " " << n + 1 << "\n";
    cout << n + 1 << " " << n + 1 << "\n";

    return 0;
}