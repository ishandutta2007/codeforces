#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    int N;
    string S;
    cin >> N >> S;
    bool yes = false;

    for (int i = 0; i < N; i++)
        if (S[i] == '8' && N - i >= 11)
            yes = true;

    cout << (yes ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}