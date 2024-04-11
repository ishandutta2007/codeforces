#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;
    long long bad = N;

    for (int i = 0, j = 0; i < N; i = j) {
        while (j < N && S[i] == S[j])
            j++;

        if (i > 0)
            bad += j - i;
    }

    reverse(S.begin(), S.end());

    for (int i = 0, j = 0; i < N; i = j) {
        while (j < N && S[i] == S[j])
            j++;

        if (i > 0)
            bad += j - i - 1;
    }

    cout << (long long) N * (N + 1) / 2 - bad << '\n';
}