#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> A, D;

bool works(int length) {
    for (int i = 0; i + length < N; i++)
        if (D[i] != D[i + length])
            return false;

    return true;
}

int main() {
    scanf("%d", &N);
    A.assign(N + 1, 0);
    D.assign(N, 0);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        D[i - 1] = A[i] - A[i - 1];
    }

    vector<int> lengths;

    for (int k = 1; k <= N; k++)
        if (works(k))
            lengths.push_back(k);

    printf("%d\n", (int) lengths.size());

    for (int i = 0; i < (int) lengths.size(); i++)
        printf("%d%c", lengths[i], i < (int) lengths.size() - 1 ? ' ' : '\n');
}