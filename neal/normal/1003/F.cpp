#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

const int MAX_TEXT = 1e5 + 5;

typedef uint64_t hash_t;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// When P = 2^32 - 13337, both P and (P - 1) / 2 are prime. Also, we avoid multiplication bases near 0 or P - 1.
const int HASH_COUNT = 2;
const hash_t HASH_P = (uint32_t) -13337;
uniform_int_distribution<hash_t> MULT_DIST(0.25 * HASH_P, 0.75 * HASH_P);
const hash_t HASH_MULT[HASH_COUNT] = {MULT_DIST(rng), MULT_DIST(rng)};

int N;
vector<string> words;
vector<hash_t> prefix_hash[HASH_COUNT];
vector<hash_t> hash_pow[HASH_COUNT];
vector<int> length_sum;

hash_t compute_hash(const string &str, int h) {
    hash_t value = 0;

    for (char c : str)
        value = (HASH_MULT[h] * value + c) % HASH_P;

    return value;
}

hash_t segment_hash(int start, int end, int h) {
    int length = length_sum[end] - length_sum[start];
    hash_t value = prefix_hash[h][end] + HASH_P - hash_pow[h][length] * prefix_hash[h][start] % HASH_P;
    return value >= HASH_P ? value - HASH_P : value;
}

hash_t combined_hash(int start, int end) {
    return segment_hash(start, end, 0) + (segment_hash(start, end, 1) << 32);
}

void prepare_hashes() {
    for (int h = 0; h < HASH_COUNT; h++) {
        hash_pow[h].resize(MAX_TEXT);
        hash_pow[h][0] = 1;

        for (int i = 1; i < MAX_TEXT; i++)
            hash_pow[h][i] = HASH_MULT[h] * hash_pow[h][i - 1] % HASH_P;

        prefix_hash[h].resize(N + 1);
        prefix_hash[h][0] = 0;

        for (int i = 0; i < N; i++)
            prefix_hash[h][i + 1] = (hash_pow[h][words[i].size()] * prefix_hash[h][i] + compute_hash(words[i], h)) % HASH_P;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    words.resize(N);
    length_sum.resize(N + 1);
    length_sum[0] = 0;

    for (int i = 0; i < N; i++) {
        cin >> words[i];
        words[i] += ' ';
        length_sum[i + 1] = length_sum[i] + words[i].size();
    }

    prepare_hashes();
    int best_save = 0;

    for (int length = 1; 2 * length <= N; length++) {
        unordered_map<hash_t, int> most_recent;
        vector<int> most_segments;
        vector<hash_t> hashes;

        for (int i = 0; i + length <= N; i++) {
            if (i >= length)
                most_recent[hashes[i - length]] = i - length;

            hash_t hash_value = combined_hash(i, i + length);
            hashes.push_back(hash_value);
            most_segments.push_back(1);

            if (most_recent.find(hash_value) != most_recent.end())
                most_segments[i] = most_segments[most_recent[hash_value]] + 1;

            if (most_segments[i] >= 2) {
                int save = (length_sum[i + length] - length_sum[i]) - (length + 1);
                best_save = max(best_save, most_segments[i] * save);
            }
        }
    }

    cout << length_sum[N] - 1 - best_save << '\n';
    return 0;
}