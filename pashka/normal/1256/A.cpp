#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b, n, s;
        cin >> a >> b >> n >> s;
        
        // x * n + y == s
        int x = min(s / n, a);
        int y = s - x * n;
        
        if (y <= b) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}