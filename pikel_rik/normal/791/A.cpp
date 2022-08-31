#include <bits/stdc++.h>
using namespace std;

int main() {
    int w1, w2, c = 0;
    cin >> w1 >> w2;

    while (w1 <= w2) {
        w1 *= 3;
        w2 *= 2;
        c += 1;
    }
    cout << c;
    return 0;
}