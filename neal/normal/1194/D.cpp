#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string ALICE = "Alice", BOB = "Bob";

void solve_case() {
    int N, K;
    cin >> N >> K;

    if (K % 3 != 0) {
        cout << (N % 3 != 0 ? ALICE : BOB) << '\n';
        return;
    }

    N %= K + 1;
    cout << (N % 3 == 0 && N < K ? BOB : ALICE) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}