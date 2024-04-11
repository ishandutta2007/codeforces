// Solution to https://codeforces.com/contest/1168/problem/E
// Given an array Z[i] of size 2^k, finds two permutations A[i] and B[i] such that Z[i] = A[i] xor B[i] for all i
#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * ((uint64_t) new char | 1));

int K, N;
vector<int> A, B, Z;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K;
    N = 1 << K;
    Z.resize(N);
    int all_xor = 0;

    for (auto &z : Z) {
        cin >> z;
        all_xor ^= z;
    }

    if (all_xor != 0) {
        cout << "Fou" << '\n';
        return 0;
    }

    A.resize(N);
    B.resize(N);
    vector<int> location(N);

    for (int i = 0; i < N; i++)
        A[i] = B[i] = i;

    // Runtime seems to be O(n log n) when starting from a random shuffle.
    shuffle(A.begin(), A.end(), rng);
    shuffle(B.begin(), B.end(), rng);

    for (int i = 0; i < N; i++)
        location[B[i]] = i;

    for (int i = 0; i < N; i++) {
        int u = i;

        while (Z[u] != (A[u] ^ B[u])) {
            int v = location[A[u] ^ Z[u]];
            swap(B[u], B[v]);
            swap(location[B[u]], location[B[v]]);

            if (v > i) {
                break;
            } else {
                swap(A[v], A[i + 1]);
                u = v;
            }
        }
    }

    // Z[i] = A[i] ^ B[i]

    cout << "Shi" << '\n';

    for (int i = 0; i < N; i++)
        cout << A[i] << (i < N - 1 ? ' ' : '\n');

    for (int i = 0; i < N; i++)
        cout << B[i] << (i < N - 1 ? ' ' : '\n');
}