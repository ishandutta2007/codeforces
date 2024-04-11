#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;
    long long low = M, high = M, time = 0;
    bool success = true;

    for (int i = 0; i < N; i++) {
        long long T, L, H;
        cin >> T >> L >> H;
        assert(T >= time);

        low -= T - time;
        high += T - time;
        time = T;

        low = max(low, L);
        high = min(high, H);

        if (low > high)
            success = false;
    }

    cout << (success ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}