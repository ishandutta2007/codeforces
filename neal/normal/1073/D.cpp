#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
long long T;
vector<long long> A;

int main() {
    scanf("%d %lld", &N, &T);
    A.resize(N);

    for (long long &a : A)
        scanf("%lld", &a);

    long long candies = 0;

    while (true) {
        long long sum = 0, count = 0;

        for (int i = 0; i < N; i++)
            if (sum + A[i] <= T) {
                sum += A[i];
                count++;
            }

        if (sum == 0)
            break;

        candies += count * (T / sum);
        T %= sum;
    }

    printf("%lld\n", candies);
}