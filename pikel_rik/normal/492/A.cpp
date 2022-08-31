#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int c = 1;

    while (n >= 0) {
        n -= c * (c + 1) / 2;
        c += 1;
    }

    cout << c - 2;
    return 0;
}