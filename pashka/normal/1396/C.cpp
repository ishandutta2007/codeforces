#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    long r1, r2, r3, d;
    cin >> r1 >> r2 >> r3 >> d;
    r1 = min(r1, r3);
    vector<long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long> c1(n);
    vector<long> c2(n);
    for (int i = 0; i < n; i++) {
        c1[i] = r1 * a[i] + r3;
        c2[i] = min(r1 * (a[i] + 2), r2 + r1);
        c2[i] = min(c2[i], c1[i]);
//        cout << i << " " << c1[i] << " " << c2[i] << "\n";
    }
    vector<long> d1(n + 1);
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            d1[i] = c1[0];
        } else {
            d1[i] = c1[i - 1] + d1[i - 1] + d;
            if (i == 2) {
                d1[i] = min(d1[i], 3 * d + c2[i - 1] + c2[i - 2]);
            } else {
                d1[i] = min(d1[i], 4 * d + c2[i - 1] + c2[i - 2] + d1[i - 2]);
                if (i == 3) {
                    d1[i] = min(d1[i], 6 * d + c2[i - 1] + c2[i - 2] + c2[i - 3]);
                } else {
                    d1[i] = min(d1[i], 7 * d + c2[i - 1] + c2[i - 2] + c2[i - 3] + d1[i - 3]);
                }
            }
        }
//        cout << i << " " << d1[i] << "\n";
    }
    long res = d1[n];
    vector<long> d2(n + 1);
    d2[2] = c2[n - 2] + min(2 * d + c1[n - 1], 4 * d + c2[n - 1]);
    for (int i = 3; i <= n; i++) {
        d2[i] = d2[i - 1] + 2 * d + c2[n - i];
    }
    res = min(res, d2[n]);

    for (int k = 2; k < n; k++) {
        res = min(res, d2[k] + d1[n - k] + d);
    }
    cout << res << "\n";

    return 0;
}