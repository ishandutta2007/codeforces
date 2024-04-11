#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int BITS = 60;

long long N, K;

int get_bits(long long number) {
    return 64 - __builtin_clzll(number);
}

long long count_prefix(long long number) {
    int bits = get_bits(number);
    int zero_bits = 0;
    int N_bits = get_bits(N);
    long long count = 0;

    while (number <= N) {
        count += min(N + 1, number + (1LL << zero_bits)) - number;
        number *= 2;
        zero_bits++;
    }

    return count;
}

long long count_paths(long long number) {
    long long count = count_prefix(number);

    if (number % 2 == 0)
        count += count_prefix(number + 1);

    return count;
}

int main() {
    cin >> N >> K;
    long long answer = 0;

    for (int bit = BITS - 1; bit >= 0; bit--)
        if (count_paths(answer + (1LL << bit)) >= K)
            answer += 1LL << bit;

    cout << answer << '\n';
}