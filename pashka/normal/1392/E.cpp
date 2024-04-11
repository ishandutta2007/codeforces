#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<long>> a(n, vector<long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i % 2 == 0) a[i][j] = 1LL << (i + j);
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout.flush();
    int q;
    cin >> q;
    while (q--) {
        long k;
        cin >> k;
        int x = 0, y = 0;
        cout << "1 1\n";
        while (x != n - 1 || y != n - 1) {
            if ((k >> (x + y + 1)) & 1) {
                if (x % 2 == 0) {
                    y++;
                } else {
                    x++;
                }
            } else {
                if (x % 2 == 1) {
                    y++;
                } else {
                    x++;
                }
            }
            cout << x + 1 << " " << y + 1 << "\n";
        }
        cout.flush();
    }

    return 0;
}