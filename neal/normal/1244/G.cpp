#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long N, K;

int main() {
    cin >> N >> K;

    if (K < N * (N + 1) / 2) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> P(N), Q(N);

    for (int i = 0; i < N; i++)
        P[i] = Q[i] = i + 1;

    long long sum = N * (N + 1) / 2;

    for (int i = 0; 2 * i < N - 1; i++) {
        int j = N - 1 - i;

        if (sum + j - i <= K) {
            swap(Q[i], Q[j]);
            sum += j - i;
            continue;
        }

        assert(sum <= K && sum + j - i > K);
        j = i + (K - sum);
        swap(Q[i], Q[j]);
        sum += j - i;
    }

    cout << sum << '\n';

    for (int i = 0; i < N; i++)
        cout << P[i] << (i < N - 1 ? ' ' : '\n');

    for (int i = 0; i < N; i++)
        cout << Q[i] << (i < N - 1 ? ' ' : '\n');
}