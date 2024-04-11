#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> A(N);

    for (int &a : A)
        scanf("%d", &a);

    int answer = -1;
    vector<bool> seen(2 * N, false);
    int mex = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] > mex) {
            answer = i + 1;
            break;
        }

        if (A[i] < (int) seen.size())
            seen[A[i]] = true;

        while (seen[mex])
            mex++;
    }

    printf("%d\n", answer);
}