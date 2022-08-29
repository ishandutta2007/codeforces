#include <algorithm>
#include <cassert>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int N;
vector<int> A;
vector<tuple<int, int, int>> ops;

void flip(int x, int diff) {
    int y = x + diff;
    int z = y + diff;
    assert(0 <= x && x < y && y < z && z < N);
    assert(x + z == 2 * y);
    A[x] ^= 1;
    A[y] ^= 1;
    A[z] ^= 1;
    ops.emplace_back(x, y, z);
}

void output_yes() {
    puts("YES");
    printf("%d\n", (int) ops.size());

    for (auto &t : ops)
        printf("%d %d %d\n", get<0>(t) + 1, get<1>(t) + 1, get<2>(t) + 1);

    assert((int) ops.size() <= N / 3 + 12);
}

bool matches(int index, vector<int> sequence) {
    int n = sequence.size();
    assert(index + n <= N);

    for (int i = 0; i < n; i++)
        if (A[index + i] != sequence[i])
            return false;

    return true;
}

int main() {
    scanf("%d", &N);
    A.resize(N);

    for (int &a : A)
        scanf("%d", &a);

    vector<int> counts(3, 0);

    for (int i = 0; i < N; i++)
        counts[i % 3] ^= A[i];

    bool all_equal = counts[0] == counts[1] && counts[1] == counts[2];

    // N <= 6 -> counts must all be equal
    if (N <= 6 && !all_equal) {
        puts("NO");
        return 0;
    }

    // N = 7 -> counts 1 and 2 must be equal
    if (N <= 7 && counts[1] != counts[2]) {
        puts("NO");
        return 0;
    }

    if (N >= 7 && counts[0] != counts[2])
        flip(0, 3);

    if (N >= 8 && counts[1] != counts[2])
        flip(1, 3);

    counts.assign(3, 0);

    for (int i = 0; i < N; i++)
        counts[i % 3] ^= A[i];

    all_equal = counts[0] == counts[1] && counts[1] == counts[2];
    assert(all_equal);

    for (int i = 0; i < N; i++) {
        if (i + 4 < N && matches(i, {1, 0, 1})) {
            flip(i, 2);
            continue;
        }

        if (i + 8 < N && matches(i, {1, 0, 0})) {
            flip(i, 4);
            continue;
        }

        if (i + 11 < N && matches(i, {1, 1, 0})) {
            int value = 4 * A[i + 3] + 2 * A[i + 4] + A[i + 5];

            if (value == 0) {
                flip(i, 5);
                flip(i + 1, 4);
            } else if (value == 1) {
                flip(i, 5);
                flip(i + 1, 5);
            } else if (value == 2) {
                flip(i, 4);
                flip(i + 1, 5);
            } else if (value == 3) {
                flip(i, 4);
                flip(i + 1, 4);
            } else if (value == 4) {
                flip(i, 5);
                flip(i + 1, 2);
            } else if (value == 5) {
                if (i + 14 < N) {
                    flip(i, 7);
                    flip(i + 1, 2);
                } else {
                    assert(A[i] == 1);
                    flip(i, 1);
                    continue;
                }
            } else if (value == 6) {
                flip(i, 1);
                flip(i + 2, 1);
            } else if (value == 7) {
                flip(i, 4);
                flip(i + 1, 2);
            } else {
                assert(false);
            }

            for (int k = 0; k < 6; k++)
                assert(A[i + k] == 0);

            continue;
        }

        if (A[i] == 1)
            flip(i, 1);
    }

    output_yes();
}