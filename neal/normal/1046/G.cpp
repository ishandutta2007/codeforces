#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> A;
vector<int> forward_diffs;

template<typename T>
vector<int> z_algorithm(const T &pattern) {
    // Z[i] = for the suffix [i, n) of pattern, the longest prefix that is also a prefix of pattern.
    int n = pattern.size();
    vector<int> Z(n, 0);
    Z[0] = n;
    int loc = 1;

    for (int i = 1; i < n; i++) {
        if (i < loc + Z[loc])
            Z[i] = min(Z[i - loc], loc + Z[loc] - i);

        while (i + Z[i] < n && pattern[Z[i]] == pattern[i + Z[i]])
            Z[i]++;

        if (i + Z[i] > loc + Z[loc])
            loc = i;
    }

    return Z;
}

int main() {
    scanf("%d %d", &N, &M);
    A.resize(N);

    for (int &a : A)
        scanf("%d", &a);

    A.push_back(A[0] + M);

    for (int i = 0; i < N; i++)
        forward_diffs.push_back(A[i + 1] - A[i]);

    vector<int> pattern(forward_diffs.begin(), forward_diffs.end());
    pattern.insert(pattern.end(), forward_diffs.rbegin(), forward_diffs.rend());
    pattern.insert(pattern.end(), forward_diffs.rbegin(), forward_diffs.rend());

    vector<int> Z = z_algorithm(pattern);
    vector<int> special;

    for (int i = 0; i < N; i++)
        if (Z[N + i] >= N)
            special.push_back((A[0] + A[N - i]) % M);

    sort(special.begin(), special.end());
    int S = special.size();
    printf("%d\n", S);

    for (int i = 0; i < S; i++)
        printf("%d%c", special[i], i < S - 1 ? ' ' : '\n');
}