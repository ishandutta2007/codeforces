#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int m = 1; m <= 15; m++) {
        for (int k = 0; k < m; k++) {
            int nn = m * m - k * k;
            int pp = k * (m - k);
            if (nn >= n && nn % 2 == n % 2 && nn - 2 * pp <= n) {
                vector<string> res(m, string(m, 'o'));
                for (int i = 0; i < k; i++) {
                    for (int j = 0; j < k; j++) {
                        res[i][m - 1 - j] = '.';
                    }
                }
                for (int i = 1; i < m; i++) {
                    if (nn > n && res[0][m - 1 - i] == 'o') {
                        res[0][m - 1 - i] = res[i][m - 1] = '.';
                        nn -= 2;
                    }
                }
                cout << m << "\n";
                for (string s : res) {
                    cout << s << "\n";
                }
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}