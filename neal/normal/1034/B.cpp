#include <iostream>
using namespace std;

int main() {
    long long N, M;
    scanf("%lld %lld", &N, &M);

    if (N > M)
        swap(N, M);

    long long answer = 0;

    if (N == 1) {
        answer = 6 * (M / 6) + 2 * max(M % 6 - 3, 0LL);
    } else if (N == 2) {
        // Can make 2x4, 2x5, or 2x6
        if (M == 2) {
            answer = 0;
        } else if (M == 3 || M == 7) {
            answer = N * (M - 1);
        } else {
            answer = N * M;
        }
    } else {
        answer = N * M;
        answer -= answer % 2;
    }

    printf("%lld\n", answer);
}