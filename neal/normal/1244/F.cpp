#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, K;
string S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K >> S;

    if (count(S.begin(), S.end(), 'B') == N || count(S.begin(), S.end(), 'W') == N) {
        cout << S << '\n';
        return 0;
    }

    bool all_different = true;

    for (int i = 0; i < N; i++)
        if (S[i] == S[(i + 1) % N])
            all_different = false;

    if (all_different) {
        cout << (K % 2 == 0 ? S : S.substr(1) + S[0]) << '\n';
        return 0;
    }

    S = S + S + S;
    vector<bool> one(3 * N, false);

    for (int i = 0; i < 3 * N; i++)
        one[i] = i > 0 && i < 3 * N - 1 && S[i] != S[i - 1] && S[i] != S[i + 1];

    for (int i = 0, j = 0; i < 3 * N; i = j) {
        if (!one[i]) {
            j = i + 1;
            continue;
        }

        while (j < 3 * N && one[j])
            j++;

        int count = j - i;

        for (int k = 0; k < count; k++)
            if (K >= min(k + 1, count - k))
                S[i + k] = k < count / 2 ? S[i - 1] : S[j];
            else
                S[i + k] = (K % 2 == 0 ? S[i + k] : 'B' + 'W' - S[i + k]);
    }

    cout << S.substr(N, N) << '\n';
}