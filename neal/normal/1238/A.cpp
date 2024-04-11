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
        long long X, Y;
        cin >> X >> Y;
        cout << (X - Y > 1 ? "YES" : "NO") << '\n';
    }
}