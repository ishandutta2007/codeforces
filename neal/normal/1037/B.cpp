#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long S;
    cin >> N >> S;
    vector<int> A(N);

    for (int i = 0; i < N; i++)
        cin >> A[i];

    sort(A.begin(), A.end());
    int mid = N / 2;

    if (S < A[mid]) {
        S = INF - S;

        for (int i = 0; i < N; i++)
            A[i] = INF - A[i];

        reverse(A.begin(), A.end());
    }

    long long total = 0;

    for (int i = mid; i < N; i++)
        total += max(S - A[i], 0LL);

    cout << total << '\n';
}