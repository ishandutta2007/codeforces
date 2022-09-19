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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sa = a[0];
    int ss = a[0];
    vector<int> res;
    res.push_back(0);
    for (int i = 1; i < n; i++) {
        if (a[0] >= a[i] * 2) {
            sa += a[i];
            res.push_back(i);
        }
        ss += a[i];
    }
    if (sa * 2 > ss) {
        cout << res.size() << "\n";
        for (int x : res) {
            cout << x + 1 << "\n";
        }
    } else {
        cout << 0 << "\n";
    }

    return 0;
}