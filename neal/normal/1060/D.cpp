#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> L(N), R(N);

    for (int i = 0; i < N; i++)
        scanf("%d %d", &L[i], &R[i]);

    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    long long sum = 0;

    for (int i = 0; i < N; i++)
        sum += max(L[i], R[i]);

    printf("%lld\n", sum + N);
}