#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, x;
    cin >> n >> x;
    vector<int> t(n), h(n), m(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> h[i] >> m[i];
    }

    int res = 0;
    for (int f = 0; f <= 1; f++) {
        int xx = x;
        vector<bool> z(n);
        for (int i = 0; i < n; i++) {
            int k = -1;
            for (int j = 0; j < n; j++) {
                if (!z[j] && h[j] <= xx && t[j] == (f + i) % 2) {
                    if (k == -1 || m[j] > m[k]) {
                        k = j;
                    }
                }
            }
            if (k == -1) {
                break;
            }
            xx += m[k];
            z[k] = true;
            res = max(res, i + 1);
        }
    }

    cout << res << "\n";

    return 0;
}