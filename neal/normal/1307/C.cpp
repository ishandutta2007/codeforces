#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int ALPHABET = 26;

int N;
string S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S;
    N = S.size();
    vector<long long> freq(ALPHABET, 0);
    vector<vector<long long>> pair_freq(ALPHABET, vector<long long>(ALPHABET, 0));

    for (int i = N - 1; i >= 0; i--) {
        for (int c = 0; c < ALPHABET; c++)
            pair_freq[S[i] - 'a'][c] += freq[c];

        freq[S[i] - 'a']++;
    }

    long long most = 0;

    for (int a = 0; a < ALPHABET; a++) {
        most = max(most, freq[a]);

        for (int b = 0; b < ALPHABET; b++)
            most = max(most, pair_freq[a][b]);
    }

    cout << most << '\n';
}