#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N);
    vector<pair<int, int>> sorted(N);
    vector<bool> big(N, false);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sorted[i] = {A[i], i};
    }

    sort(sorted.rbegin(), sorted.rend());
    long long total = 0;

    for (int i = 0; i < M * K; i++) {
        total += sorted[i].first;
        big[sorted[i].second] = true;
    }

    cout << total << '\n';
    int big_count = 0, index = 0;

    for (int i = 0; i < N; i++) {
        if (big[i])
            big_count++;

        if (big_count >= M) {
            if (index < K - 1)
                cout << i + 1 << (index < K - 2 ? ' ' : '\n');

            index++;
            big_count = 0;
        }
    }
}