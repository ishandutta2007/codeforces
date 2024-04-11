#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 0;
    int l = 0;
    int a = -1, b = -1, p = -1;
    for (int i = 0; i < n + 1; i++) {
        int x;
        if (i < n) cin >> x; else x = -1;
        if (x == p) {
            l++;
        } else {
            if (a == b) {
                if (l >= 2) {
                    a = b = p;
                    res += 2;
                } else if (l >= 1) {
                    a = p;
                    res += 1;
                }
            } else {
                if (l >= 2) {
                    if (a == p || b == p) res += 1; else res += 2;
                    a = b = p;
                } else if (l >= 1) {
                    if (a == p || b == p) {
                        a = b = p;
                    } else {
                        a = p; b = -1;
                    }
                    res += 1;
                }
            }
            l = 1;
//            cout << res << " " << a << " " << b << "\n";
        }
        p = x;
    }
    cout << res << "\n";

    return 0;
}