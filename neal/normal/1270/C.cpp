#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    int N;
    cin >> N;
    long long S = 0, X = 0;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        S += a;
        X ^= a;
    }

    cout << 2 << '\n';
    cout << X << ' ' << S + X << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        run_case();
}