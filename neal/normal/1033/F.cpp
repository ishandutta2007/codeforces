#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int W, N, M;
vector<uint16_t> freq;
vector<uint16_t> quick_count;

int needed(char bit_gate, int bit) {
    // 0 or 1: must be this, 2: can be either, 3: impossible
    switch (bit_gate) {
        case 'A': return bit == 0 ? 2 : 0;
        case 'O': return bit == 0 ? 0 : 3;
        case 'X': return bit;
        case 'a': return bit == 0 ? 3 : 1;
        case 'o': return bit == 0 ? 1 : 2;
        case 'x': return bit ^ 1;
    }

    assert(false);
}

int recurse(string &gate, int position, int mask, int extended) {
    if (position >= W)
        return (int) freq[mask] * quick_count[extended];

    int opt0 = needed(gate[position], 0);
    int opt1 = needed(gate[position], 1);
    int answer = 0;

    if (opt0 != 3) answer += recurse(gate, position + 1, mask, extended + (opt0 << 2 * position));
    if (opt1 != 3) answer += recurse(gate, position + 1, mask + (1 << position), extended + (opt1 << 2 * position));

    return answer;
}

int solve(string gate) {
    reverse(gate.begin(), gate.end());
    return recurse(gate, 0, 0, 0);
}

int main() {
    scanf("%d %d %d", &W, &N, &M);
    freq.resize(1 << W);

    for (int i = 0; i < N; i++) {
        int v;
        scanf("%d", &v);
        freq[v]++;
    }

    quick_count.resize(1 << 2 * W);

    for (int a = 0; a < 1 << W; a++) {
        int expanded = 0;

        for (int i = 0; i < W; i++)
            if (a & 1 << i)
                expanded += 1 << 2 * i;

        quick_count[expanded] = freq[a];
    }

    int a = 0;

    while (a < 1 << 2 * W) {
        for (int i = 0; i < W; i++)
            if ((a >> 2 * i) % 4 == 2) {
                quick_count[a] = quick_count[a - (2 << 2 * i)] + quick_count[a - (1 << 2 * i)];
                break;
            }

        int index = W;

        for (int i = 0; i < W; i++)
            if ((a >> 2 * i) % 4 == 2) {
                a ^= a & 3 << 2 * i;
            } else {
                index = i;
                break;
            }

        a += 1 << 2 * index;
    }

    for (int i = 0; i < M; i++) {
        char gate[100];
        scanf("%s", gate);
        printf("%d\n", solve(gate));
    }
}