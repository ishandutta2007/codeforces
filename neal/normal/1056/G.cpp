#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long N, M;

int mod_add(int a, int b) {
    int sum = a + b;
    return sum >= N ? sum - N : sum;
}

long long compute_end_up(long long position) {
    for (int i = N - 1; i >= 0; i--)
        if (position < M)
            position = mod_add(position, i);
        else
            position = mod_add(position, N - i);

    return position;
}

long long solve(long long position, long long T) {
    assert(T % N == 0);
    T /= N;
    vector<long long> save(N, -1);
    vector<long long> positions;

    for (long long iter = 0; iter < T; iter++) {
        if (save[position] >= 0) {
            long long start = save[position];
            long long length = iter - start;
            return positions[start + (T - start) % length];
        }

        save[position] = iter;
        positions.push_back(position);
        position = compute_end_up(position);
    }

    return position;
}

int main() {
    long long S, T;
    cin >> N >> M >> S >> T;
    long long position = S - 1;

    while (T % N != 0) {
        if (position < M)
            position = (position + T) % N;
        else
            position = (position + N - T % N) % N;

        T--;
    }

    cout << solve(position, T) + 1 << '\n';
}