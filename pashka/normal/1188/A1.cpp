#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        d[x]++;
        d[y]++;
    }

    for (int i = 0; i < n; i++) {
        if (d[i] == 2) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}