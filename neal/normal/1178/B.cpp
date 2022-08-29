#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int N = S.size();
    vector<long long> prefix(N + 1, 0);
    vector<long long> suffix(N + 1, 0);

    for (int i = 0; i + 1 < N; i++)
        if (S[i] == 'v' && S[i + 1] == 'v')
            prefix[i + 2] = prefix[i + 1] + 1;
        else
            prefix[i + 2] = prefix[i + 1];

    for (int i = N - 2; i > 0; i--)
        if (S[i] == 'v' && S[i + 1] == 'v')
            suffix[i - 1] = suffix[i] + 1;
        else
            suffix[i - 1] = suffix[i];

    long long total = 0;

    for (int i = 0; i < N; i++)
        if (S[i] == 'o')
            total += prefix[i] * suffix[i];

    cout << total << '\n';
}