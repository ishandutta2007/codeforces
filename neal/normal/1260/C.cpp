#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    long long R, B, K;
    cin >> R >> B >> K;

    if (R < B)
        swap(R, B);

    bool bad = B * (K - 1) + __gcd(R, B) <= R - 1;
    cout << (bad ? "REBEL" : "OBEY") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}