#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0) {
        int X, Y;
        cin >> X >> Y;

        if (X >= 4)
            cout << "YES" << '\n';
        else if (X == 2 || X == 3)
            cout << (Y <= 3 ? "YES" : "NO") << '\n';
        else if (X == 1)
            cout << (Y <= 1 ? "YES" : "NO") << '\n';
        else
            assert(false);
    }
}