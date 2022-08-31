#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct safe_hash32 {
    static unsigned hash32(unsigned x) {
        x = (x ^ (x >> 16)) * 0x45d9f3b;
        x = (x ^ (x >> 16)) * 0x45d9f3b;
        return x ^ (x >> 16);
    }

    size_t operator()(unsigned x) const {
        static const unsigned XOR_VALUE = hash32(
            chrono::steady_clock::now().time_since_epoch().count() * ((uint64_t) new char | 1));

        return hash32(x ^ XOR_VALUE);
    }
};

int N, M;
vector<int> A, B;

int solve(int jump) {
    gp_hash_table<int, int, safe_hash32> freq;

    for (int i = 0; i < N; i++)
        freq[A[i] & (2 * jump - 1)]++;

    for (int i = 0; i < M; i++)
        freq[(B[i] + jump) & (2 * jump - 1)]++;

    int most = 0;

    for (auto &p : freq)
        most = max(most, p.second);

    return most;
}

int main() {
    int _;
    scanf("%d %d", &N, &_);
    A.resize(N);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    scanf("%d %d", &M, &_);
    B.resize(M);

    for (int i = 0; i < M; i++)
        scanf("%d", &B[i]);

    int answer = 1;

    for (int i = 0, j = 0; i < N; i++) {
        while (j < M && B[j] < A[i])
            j++;

        if (j < M && A[i] == B[j])
            answer = 2;
    }

    for (int jump = 1; jump <= 1e9; jump *= 2)
        answer = max(answer, solve(jump));

    printf("%d\n", answer);
}