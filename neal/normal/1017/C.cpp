#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int longest_increasing(const vector<int> &v) {
    int n = v.size();
    vector<int> endings;

    for (int i = 0; i < n; i++) {
        int location = lower_bound(endings.begin(), endings.end(), v[i]) - endings.begin();

        if (location == (int) endings.size())
            endings.push_back(v[i]);
        else
            endings[location] = v[i];
    }

    return endings.size();
}

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    vector<int> permutation;
    int S = 1;

    while ((S + 1) * (S + 1) <= N)
        S++;

    if (N == S * S || N > S * (S + 1)) {
        if (N > S * (S + 1))
            S++;

        for (int s = 0; s < S; s++)
            for (int i = S - 1; i >= 0; i--) {
                int value = s * S + i;

                if (value < N)
                    permutation.push_back(value);
            }
    } else {
        for (int s = 0; s <= S; s++)
            for (int i = S - 1; i >= 0; i--) {
                int value = s * S + i;

                if (value < N)
                    permutation.push_back(value);
            }
    }

    for (int i = 0; i < N; i++)
        cout << permutation[i] + 1 << (i < N - 1 ? ' ' : '\n');

    // vector<int> rev_perm(N);

    // for (int i = 0; i < N; i++)
    //     rev_perm[i] = N + 1 - permutation[i];

    // int total = longest_increasing(permutation) + longest_increasing(rev_perm);
    // cerr << total << '\n';
    return 0;
}