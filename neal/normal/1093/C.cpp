#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<long long> A, B;

int main() {
    scanf("%d", &N);
    A.resize(N);
    B.resize(N / 2);

    for (long long &b : B)
        scanf("%lld", &b);

    for (int i = 0; i < N / 2; i++) {
        A[i] = 0;
        A[N - 1 - i] = B[i];

        if (i == 0)
            continue;

        long long adjust = max(A[i - 1] - A[i], A[N - 1 - i] - A[N - i]);
        A[i] += adjust;
        A[N - 1 - i] -= adjust;
    }

    for (int i = 0; i < N; i++)
        printf("%lld%c", A[i], i < N - 1 ? ' ' : '\n');
}