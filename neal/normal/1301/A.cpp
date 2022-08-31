#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    string A, B, C;
    cin >> A >> B >> C;
    int n = A.size();

    for (int i = 0; i < n; i++)
        if (A[i] != C[i] && B[i] != C[i]) {
            cout << "NO" << '\n';
            return;
        }

    cout << "YES" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}