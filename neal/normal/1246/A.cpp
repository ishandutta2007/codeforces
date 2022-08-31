#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N, P;
    cin >> N >> P;

    for (long long K = 1; K <= 1000; K++) {
        long long goal = N - K * P;

        if (goal < K)
            continue;

        if (__builtin_popcountll(goal) <= K) {
            cout << K << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
}