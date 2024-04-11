#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    long long N, K;
    cin >> N >> K;
    long long mod = N % K;
    mod = min(mod, K / 2);
    cout << N - N % K + mod << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        run_case();
}