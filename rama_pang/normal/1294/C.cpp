#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        lint n;
        cin >> n;
        for (lint i = 2; i * i * i <= n; i++) {
            if (n % i == 0) {
                lint m = n / i;
                for (lint j = i + 1; j * j <= m; j++) {
                    if (m % j == 0) {
                        lint k = m / j;
                        if (j < k) {

                            cout << "YES\n";
                            cout << i << " " << j << " " << k << "\n";
                            goto DONE;
                        }
                    }
                }
            }
        }
        cout << "NO\n";
        DONE:
        cout << "";
    }

}