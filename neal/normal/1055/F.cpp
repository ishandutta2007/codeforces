#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct identity {
    template<typename T>
    T operator()(const T &x) const {
        return x;
    }
};

template<typename T, typename T_extract_key = identity>
void radix_sort(vector<T> &data, int bits_per_pass = 10, const T_extract_key &extract_key = identity()) {
    if (data.size() < 256) {
        sort(data.begin(), data.end(), [&](const T &a, const T &b) {
            return extract_key(a) < extract_key(b);
        });
        return;
    }

    using T_key = decltype(extract_key(data.front()));
    T_key minimum = numeric_limits<T_key>::max();

    for (T &x : data)
        minimum = min(minimum, extract_key(x));

    int max_bits = 0;

    for (T &x : data) {
        T_key key = extract_key(x);
        max_bits = max(max_bits, key == minimum ? 0 : 64 - __builtin_clzll(key - minimum));
    }

    int passes = max((max_bits + bits_per_pass / 2) / bits_per_pass, 1);

    if (32 - __builtin_clz(data.size()) <= 1.5 * passes) {
        sort(data.begin(), data.end(), [&](const T &a, const T &b) {
            return extract_key(a) < extract_key(b);
        });
        return;
    }

    vector<T> buffer(data.size());
    vector<int> counts;
    int bits_so_far = 0;

    for (int p = 0; p < passes; p++) {
        int bits = (max_bits + p) / passes;
        counts.assign(1 << bits, 0);

        for (T &x : data) {
            T_key key = extract_key(x) - minimum;
            counts[(key >> bits_so_far) & ((1 << bits) - 1)]++;
        }

        int count_sum = 0;

        for (int &count : counts) {
            int current = count;
            count = count_sum;
            count_sum += current;
        }

        for (T &x : data) {
            T_key key = extract_key(x) - minimum;
            int key_section = (key >> bits_so_far) & ((1 << bits) - 1);
            buffer[counts[key_section]++] = x;
        }

        swap(data, buffer);
        bits_so_far += bits;
    }
}


const int BITS = 62;

int N;
long long K;
vector<int> parent;
vector<long long> up_weight, root_xor;
vector<long long> first, second;

long long starting_with(long long value, int lowest_bit) {
    first.resize(N);
    second.resize(N);
    long long total = 0;

    for (int i = 0; i < N; i++) {
        first[i] = root_xor[i] >> lowest_bit;
        second[i] = first[i] ^ value;
    }

    radix_sort(second);
    int pos = 0;

    for (int i = 0, j = 0; i < N; i = j) {
        while (j < N && first[i] == first[j])
            j++;

        while (pos < N && second[pos] < first[i])
            pos++;

        while (pos < N && second[pos] == first[i]) {
            total += j - i;
            pos++;
        }
    }

    return total;
}

int main() {
    scanf("%d %lld", &N, &K);
    parent.assign(N, -1);
    up_weight.assign(N, 0);
    root_xor.assign(N, 0);

    for (int i = 1; i < N; i++) {
        scanf("%d %lld", &parent[i], &up_weight[i]);
        parent[i]--;
        root_xor[i] = root_xor[parent[i]] ^ up_weight[i];
    }

    radix_sort(root_xor);
    long long answer = 0;

    for (int bit = BITS - 1; bit >= 0; bit--) {
        long long count = starting_with(answer >> bit, bit);

        if (K > count) {
            K -= count;
            answer += 1LL << bit;
        }
    }

    printf("%lld\n", answer);
}