#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T-- > 0) {
        long long N, K;
        cin >> N >> K;
        long long steps = 0;

        while (N > 0) {
            steps += N % K;
            N -= N % K;

            if (N == 0)
                break;

            N /= K;
            steps++;
        }

        cout << steps << '\n';
    }
}