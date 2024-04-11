#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T;
    cin >> S >> T;
    int N = S.size(), M = T.size();
    vector<int> prefix(N + 1, 0), suffix(N + 1, 0);

    for (int i = 0; i < N; i++) {
        prefix[i + 1] = prefix[i];

        if (prefix[i] < M && S[i] == T[prefix[i]])
            prefix[i + 1]++;
    }

    for (int i = N - 1; i >= 0; i--) {
        suffix[i] = suffix[i + 1];

        if (suffix[i] < M && S[i] == T[M - 1 - suffix[i]])
            suffix[i]++;
    }

    int best = 0;

    for (int i = 0, j = 0; i < N; i++) {
        while (j < N && prefix[i] + suffix[j + 1] >= M)
            j++;

        best = max(best, j - i);
    }

    cout << best << '\n';
}