#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int j = 0; j < 20; j++) {
        int c = 0;
        for (int i = 0; i < n; i++) {
            if ((a[i] >> j) & 1) {
                b[c++] |= (1 << j);
            }
        }
    }
    long res = 0;
    for (int i = 0; i < n; i++) {
        res += (long)b[i] * b[i];
    }
    cout << res;

    return 0;
}