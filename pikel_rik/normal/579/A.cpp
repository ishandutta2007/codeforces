#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;

    int c = 0;

    while (x > 0) {
        if (x % 2 == 0)
            x /= 2;
        else {
            x -= 1;
            c += 1;
        }
    }

    cout << c;
    return 0;
}