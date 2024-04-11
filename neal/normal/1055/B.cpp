#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, M, L;
vector<long long> A;

int main() {
    scanf("%d %d %d", &N, &M, &L);
    A.resize(N + 2, 0);

    for (int i = 1; i <= N; i++)
        scanf("%lld", &A[i]);

    int segments = 0;
    bool current = false;

    for (int i = 0; i <= N + 1; i++)
        if (A[i] > L) {
            if (!current)
                segments++;

            current = true;
        } else {
            current = false;
        }

    for (int i = 0; i < M; i++) {
        int type;
        scanf("%d", &type);

        if (type == 0) {
            printf("%d\n", segments);
            continue;
        }

        assert(type == 1);
        int p, d;
        scanf("%d %d", &p, &d);

        if (A[p] <= L && A[p] + d > L) {
            segments++;

            if (A[p - 1] > L)
                segments--;

            if (A[p + 1] > L)
                segments--;
        }

        A[p] += d;
    }
}