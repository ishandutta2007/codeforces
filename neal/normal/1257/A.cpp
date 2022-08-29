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
        int N, X, A, B;
        cin >> N >> X >> A >> B;
        cout << min(abs(A - B) + X, N - 1) << '\n';
    }
}