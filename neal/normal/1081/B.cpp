#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> A;

int main() {
    scanf("%d", &N);
    A.resize(N);

    for (int &a : A) {
        scanf("%d", &a);
        a = N - a;
    }

    vector<int> freq(N + 1, 0);

    for (int &a : A)
        freq[a]++;

    for (int i = 1; i <= N; i++)
        if (freq[i] % i != 0) {
            puts("Impossible");
            return 0;
        }

    int hat = 0;
    vector<int> current_hat(N + 1, -1);
    puts("Possible");

    for (int i = 0; i < N; i++) {
        if (freq[A[i]] % A[i] == 0)
            current_hat[A[i]] = ++hat;

        printf("%d%c", current_hat[A[i]], i < N - 1 ? ' ' : '\n');
        freq[A[i]]--;
    }
}