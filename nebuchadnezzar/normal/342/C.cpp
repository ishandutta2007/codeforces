#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int r, h;

int main() {
    cin >> r >> h;

    int ans = h / r * 2;

    if (h - (h / r) * r >= r / 2.0) {
        ans += 2;
        if (r - (h - (h / r) * r) < (1 - sqrt(3) / 2) * r) {
            ans += 1;
        }
    } else {
        ans += 1;
    }

    cout << ans;

    return 0;
}