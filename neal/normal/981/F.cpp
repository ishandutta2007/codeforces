#include <algorithm>
#include <iostream>
using namespace std;

const int N_MAX = 200005;
const int INF = 1000000005;

int N, L;
int A[3 * N_MAX], B[3 * N_MAX];

bool works(int max_dist) {
    int lowest = -INF, highest = INF;
    int b_start = 0, b_end = 0;

    for (int i = N; i < 2 * N; i++) {
        while (b_start < 3 * N && B[b_start] < A[i] - max_dist)
            b_start++;

        while (b_end < 3 * N && B[b_end] <= A[i] + max_dist)
            b_end++;

        lowest = max(lowest, b_start - i);
        highest = min(highest, b_end - i);
    }

    return lowest < highest;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        cin >> A[N + i];
    }

    for (int i = 0; i < N; i++) {
        cin >> B[N + i];
    }

    sort(A + N, A + 2 * N);
    sort(B + N, B + 2 * N);

    for (int i = 0; i < N; i++) {
        A[i] = A[N + i] - L;
        B[i] = B[N + i] - L;
        A[2 * N + i] = A[N + i] + L;
        B[2 * N + i] = B[N + i] + L;
    }

    int low = 0, high = L;

    while (low < high) {
        int mid = (low + high) / 2;

        if (works(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low << '\n';
    return 0;
}