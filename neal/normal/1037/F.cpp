#include <algorithm>
#include <iostream>
using namespace std;

const int N_MAX = 1e6 + 5;
const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

int N, K;
int elements[N_MAX];
int L[N_MAX], R[N_MAX];

int S;
pair<int, int> stack[N_MAX];

int all_k[N_MAX];

int main() {
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++)
        scanf("%d", &elements[i]);

    S = 0;
    stack[S++] = make_pair(INF, -1);

    for (int i = 0; i < N; i++) {
        while (S > 0 && stack[S - 1].first < elements[i])
            S--;

        L[i] = i - stack[S - 1].second - 1;
        stack[S++] = make_pair(elements[i], i);
    }

    S = 0;
    stack[S++] = make_pair(INF, N);

    for (int i = N - 1; i >= 0; i--) {
        while (S > 0 && stack[S - 1].first <= elements[i])
            S--;

        R[i] = stack[S - 1].second - i - 1;
        stack[S++] = make_pair(elements[i], i);
    }

    all_k[0] = 0;

    for (int len = 1; len <= N; len++)
        all_k[len] = (all_k[len - 1] + (len - 1) / (K - 1)) % MOD;

    int total = 0;

    for (int i = 0; i < N; i++) {
        int count = all_k[L[i] + R[i] + 1] - all_k[L[i]] - all_k[R[i]];
        total = (total + (long long) count * elements[i]) % MOD;
    }

    printf("%d\n", (total % MOD + MOD) % MOD);
}