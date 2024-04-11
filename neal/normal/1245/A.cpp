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
        int A, B;
        cin >> A >> B;
        cout << (__gcd(A, B) == 1 ? "Finite" : "Infinite") << '\n';
    }
}