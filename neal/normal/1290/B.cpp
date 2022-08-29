#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int ALPHABET = 26;

int N, Q;
string S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S;
    N = S.size();
    vector<vector<int>> counts(ALPHABET, vector<int>(N + 1, 0));

    for (int c = 0; c < ALPHABET; c++)
        for (int i = 0; i < N; i++)
            counts[c][i + 1] = counts[c][i] + (S[i] == 'a' + c ? 1 : 0);

    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int L, R;
        cin >> L >> R;
        L--; R--;
        bool answer = false;

        if (L == R)
            answer = true;

        if (S[L] != S[R])
            answer = true;

        int chars = 0;

        for (int c = 0; c < ALPHABET; c++)
            if (counts[c][R + 1] - counts[c][L] > 0)
                chars++;

        if (chars >= 3)
            answer = true;

        cout << (answer ? "Yes" : "No") << '\n';
    }
}