#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
vector<int> A;

bool can_guarantee(int minimum) {
    vector<bool> good(N);

    for (int i = 0; i < N; i++)
        good[i] = A[i] >= minimum;

    vector<bool> works(M + 1);
    int length = N - M;

    for (int start = 0; start <= M; start++)
        works[start] = good[start] || good[start + length - 1];

    int need = M + 1 - K;

    for (int i = 0; i + need <= M + 1; i++) {
        bool ok = true;

        for (int j = i; j < i + need && ok; j++)
            if (!works[j])
                ok = false;

        if (ok)
            return true;
    }

    return false;
}

void run_case() {
    cin >> N >> M >> K;
    M--;
    K = min(K, M);
    A.resize(N);

    for (int &a : A)
        cin >> a;

    vector<int> sorted = A;
    sort(sorted.begin(), sorted.end());
    int low = 0, high = N - 1;

    while (low < high) {
        int mid = (low + high + 1) / 2;

        if (can_guarantee(sorted[mid]))
            low = mid;
        else
            high = mid - 1;
    }

    cout << sorted[low] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}