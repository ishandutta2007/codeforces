#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    long long A, B, N;
    cin >> A >> B >> N;

    if (N % 3 == 0)
        cout << A << '\n';
    else if (N % 3 == 1)
        cout << B << '\n';
    else if (N % 3 == 2)
        cout << (A ^ B) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}