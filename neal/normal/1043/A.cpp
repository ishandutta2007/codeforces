#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> A(N);

    for (int &a : A)
        scanf("%d", &a);

    int K = *max_element(A.begin(), A.end());
    int sum = accumulate(A.begin(), A.end(), 0);

    if (K * N <= 2 * sum)
        K = 2 * sum / N + 1;

    printf("%d\n", K);
}