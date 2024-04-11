#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int c = 0;
    if (a < b) {
        c += a;
        b = b - a;
        a = 0;
    }
    else {
        c += b;
        a = a - b;
        b = 0;
    }

    cout << c << " ";
    c = 0;

    cout << max(a, b) / 2;
    return 0;
}