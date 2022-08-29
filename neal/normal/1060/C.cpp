#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const long long LL_INF = (long long) 1e18 + 5;

vector<long long> compute_min_sums(vector<long long> nums) {
    int n = nums.size();
    vector<long long> min_sums(n + 1, LL_INF);
    min_sums[0] = 0;

    for (int i = 0; i < n; i++) {
        long long sum = 0;

        for (int j = i + 1; j <= n; j++) {
            sum += nums[j - 1];
            min_sums[j - i] = min(min_sums[j - i], sum);
        }
    }

    return min_sums;
}

int N, M;
long long X;
vector<long long> A, B;

int main() {
    scanf("%d %d", &N, &M);
    A.resize(N);
    B.resize(M);

    for (long long &a : A)
        scanf("%lld", &a);

    for (long long &b : B)
        scanf("%lld", &b);

    scanf("%lld", &X);
    vector<long long> min_sums_A = compute_min_sums(A);
    vector<long long> min_sums_B = compute_min_sums(B);
    int area = 0;

    for (int rows = 1; rows <= N; rows++)
        for (int cols = 1; cols <= M; cols++)
            if (min_sums_A[rows] * min_sums_B[cols] <= X)
                area = max(area, rows * cols);

    printf("%d\n", area);
}