#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    long long X;
    cin >> X;
    bool answer = (X >= 15 && 1 <= X % 14 && X % 14 <= 6);
    cout << (answer ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        run_case();
}