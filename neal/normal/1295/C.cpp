#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;
const int ALPHABET = 26;

void run_case() {
    string S, T;
    cin >> S >> T;
    int N = S.size();
    vector<array<int, ALPHABET>> closest(N + 1);

    for (int c = 0; c < ALPHABET; c++)
        closest[N][c] = INF;

    for (int i = N - 1; i >= 0; i--) {
        closest[i] = closest[i + 1];
        closest[i][S[i] - 'a'] = i;
    }

    int position = 0, total = 1;

    for (char c : T) {
        if (closest[0][c - 'a'] >= INF) {
            cout << -1 << '\n';
            return;
        }

        position = closest[position][c - 'a'] + 1;

        if (position >= INF) {
            total++;
            position = closest[0][c - 'a'] + 1;
        }
    }

    cout << total << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}