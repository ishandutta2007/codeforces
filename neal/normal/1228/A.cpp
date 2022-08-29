#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

bool works(int x) {
    vector<bool> digits(10, false);

    while (x > 0) {
        if (digits[x % 10])
            return false;

        digits[x % 10] = true;
        x /= 10;
    }

    return true;
}

int main() {
    int L, R;
    cin >> L >> R;

    for (int x = L; x <= R; x++)
        if (works(x)) {
            cout << x << '\n';
            return 0;
        }

    cout << -1 << '\n';
    return 0;
}