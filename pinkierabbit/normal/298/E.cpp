#include <cstdio>
#include <algorithm>

const int MN = 100005;

int N, S[MN], A[MN], B[MN], per[MN];

int main() {
    puts("YES");
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &S[i]), per[i] = i;
    if (N <= 2) {
        for (int i = 1; i <= N; ++i) printf("%d%c", S[i], " \n"[i == N]);
        for (int i = 1; i <= N; ++i) printf("0%c", " \n"[i == N]);
        return 0;
    }
    std::sort(per + 1, per + N + 1, [](int i, int j) {
        return S[i] < S[j];
    });
    int K = (N - 1) / 3 + 1;
    for (int i = 1; i <= K; ++i)
        A[per[i]] = S[per[i]], B[per[i]] = 0;
    for (int i = K + 1; i <= 2 * K; ++i)
        A[per[i]] = 0, B[per[i]] = S[per[i]];
    for (int i = 2 * K + 1; i <= N; ++i)
        A[per[i]] = S[per[i]] - (N - i),
        B[per[i]] = N - i;
    for (int i = 1; i <= N; ++i) printf("%d%c", A[i], " \n"[i == N]);
    for (int i = 1; i <= N; ++i) printf("%d%c", B[i], " \n"[i == N]);
    return 0;
}