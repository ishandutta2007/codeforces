#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

const long long LL_INF = (long long) 2e18 + 5;

int N;
vector<int> parent;
vector<long long> sums;
vector<long long> A;

int main() {
    scanf("%d", &N);
    parent.resize(N);
    parent[0] = -1;

    for (int i = 1; i < N; i++) {
        scanf("%d", &parent[i]);
        parent[i]--;
    }

    sums.resize(N);

    for (int i = 0; i < N; i++)
        scanf("%lld", &sums[i]);

    A.assign(N, LL_INF);
    A[0] = sums[0];

    for (int i = 1; i < N; i++)
        if (sums[i] >= 0) {
            int p = parent[i];
            int gp = parent[p];
            assert(p >= 0 && gp >= 0);

            if (sums[i] < sums[gp]) {
                puts("-1");
                return 0;
            }

            A[p] = min(A[p], sums[i] - sums[gp]);
        }

    for (int i = 1; i < N; i++)
        if (sums[i] < 0) {
            if (A[i] == LL_INF)
                A[i] = 0;
        } else {
            int p = parent[i];
            int gp = parent[p];
            A[i] = sums[i] - sums[gp] - A[p];
            assert(A[i] >= 0);
        }

    long long total = accumulate(A.begin(), A.end(), 0LL);
    printf("%lld\n", total);
}