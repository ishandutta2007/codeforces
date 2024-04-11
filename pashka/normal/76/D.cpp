#include <bits/stdc++.h>
#define long unsigned long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    long a, b;
    cin >> a >> b;
    if (a < b) {
        cout << -1;
        return 0;
    }
    long c = a - b;
    if (c & 1) {
        cout << -1;
        return 0;
    }
    c >>= 1;
    if (c & b) {
        cout << -1;
        return 0;
    }
    long x = c;
    long y = c + b;
    cout << x << " " << y;

    return 0;
}