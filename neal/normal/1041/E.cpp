#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> A;

int main() {
    scanf("%d", &N);
    M = N - 1;
    A.resize(M);

    for (int i = 0; i < M; i++) {
        int B;
        scanf("%d %d", &A[i], &B);

        if (B != N) {
            puts("NO");
            return 0;
        }
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < M; i++)
        if (A[i] <= i) {
            puts("NO");
            return 0;
        }

    vector<int> answer;
    vector<bool> used(N, false);
    int low = 1;

    for (int i = 0, j = 0; i < M; i = j) {
        while (j < M && A[i] == A[j])
            j++;

        answer.push_back(A[i]);
        used[A[i]] = true;

        for (int k = 1; k <= j - i - 1; k++) {
            while (used[low]) {
                low++;
                assert(low < N);
            }

            answer.push_back(low);
            used[low] = true;
        }
    }

    answer.push_back(N);
    puts("YES");

    for (int i = 0; i < M; i++)
        printf("%d %d\n", answer[i], answer[i + 1]);
}