#include <bits/stdc++.h>

using namespace std;

int n;

inline long long c2(int n) {
    if (n < 1) {
        return 0ll;
    }
    return 1ll * n * (n - 1) / 2;
}

inline long long c3(int u) {
    if (n < 2) {
        return 0ll;
    }
    return 1ll * n * (n - 1) * (n - 2) / 6;
}

int main() {
    cin >> n;
    long long res = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if ((i >= 5) && (j >= 1)) {
                continue;
            }
            if (i + j > n) {
                continue;
            }
            int u = n - i - j;
            res += u + 1;
            // cout << i << " " << j << " " << res << endl;
        }
    }
    cout << res << endl;
    return 0;
}