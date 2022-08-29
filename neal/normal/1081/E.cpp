#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e6 + 5;
const long long LL_INF = (long long) 2e18 + 5;

int main() {
    int N;
    scanf("%d", &N);
    vector<long long> output;
    long long sum = 0;

    for (int i = 0; i < N / 2; i++) {
        int X;
        scanf("%d", &X);
        long long min_a = LL_INF;

        for (int d = 1; d * d < X; d++)
            if (X % d == 0) {
                int s = X / d;

                if (s != d && (s - d) % 2 == 0) {
                    long long candidate = (s - d) / 2;

                    if (candidate * candidate > sum)
                        min_a = min(min_a, candidate * candidate);
                }
            }

        if (min_a == LL_INF) {
            puts("No");
            return 0;
        }

        output.push_back(min_a - sum);
        output.push_back(X);
        sum = min_a + X;
    }

    puts("Yes");

    for (int i = 0; i < N; i++)
        printf("%lld%c", output[i], i < N - 1 ? ' ' : '\n');
}