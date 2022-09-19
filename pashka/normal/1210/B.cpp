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
    vector<long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<long> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<vector<bool>> q(n, vector<bool>(n));
    vector<bool> z(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] & (~a[j])) {
                q[i][j] = true;
            }
        }
    }
    long res = 0;
    for (int i = 0; i < n; i++) {
        res += b[i];
    }
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (q[i][j]) s[i]++;
        }
    }

    int nn = n;
    while (true) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (!z[i] && s[i] == nn - 1) {
                ok = false;
                z[i] = true;
                res -= b[i];
                nn--;
                for (int j = 0; j < n; j++) {
                    if (q[j][i]) {s[j]--;}
                }
            }
        }
        if (ok) break;
    }

    cout << res << "\n";


    return 0;
}