#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * ((uint64_t) new char | 1));

using hash_t = uint64_t;

// When P = 2^32 - 13337, both P and (P - 1) / 2 are prime.
const hash_t HASH_P = (unsigned) -13337;

// Avoid multiplication bases near 0 or P - 1.
uniform_int_distribution<hash_t> MULT_DIST(0.1 * HASH_P, 0.9 * HASH_P);
const hash_t HASH_MULT[] = {MULT_DIST(rng), MULT_DIST(rng)};
const int HASH_COUNT = 2;

vector<unsigned> hash_pow[HASH_COUNT] = {{1}, {1}};

struct string_hash {
    vector<unsigned> prefix_hash[HASH_COUNT];

    string_hash() {
        build(string());
    }

    template<typename T_string>
    string_hash(const T_string &str) {
        build(str);
    }

    int length() const {
        return (int) prefix_hash[0].size() - 1;
    }

    template<typename T>
    void add_char(const T &c) {
        for (int h = 0; h < HASH_COUNT; h++) {
            prefix_hash[h].push_back((HASH_MULT[h] * prefix_hash[h].back() + c) % HASH_P);

            if (hash_pow[h].size() < prefix_hash[h].size())
                hash_pow[h].push_back(HASH_MULT[h] * hash_pow[h].back() % HASH_P);
        }
    }

    template<typename T_string>
    void build(const T_string &str) {
        for (int h = 0; h < HASH_COUNT; h++)
            if (prefix_hash[h].empty())
                prefix_hash[h] = {0};

        for (auto &c : str)
            add_char(c);
    }

    hash_t _single_hash(int h, int start, int end) const {
        hash_t start_hash = (hash_t) prefix_hash[h][start] * hash_pow[h][end - start];
        return (prefix_hash[h][end] + HASH_P * HASH_P - start_hash) % HASH_P;
    }

    hash_t substring_hash(int start, int end) const {
        return _single_hash(0, start, end) + (HASH_COUNT > 1 ? _single_hash(1, start, end) << 32 : 0);
    }

    bool equal(int start1, int start2, int length) const {
        return substring_hash(start1, start1 + length) == substring_hash(start2, start2 + length);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string_hash hasher;
    string result = "";

    while (N-- > 0) {
        string word;
        cin >> word;
        string_hash word_hash(word);
        int len = word.size(), overlap = 0;

        for (int i = 1; i <= min(hasher.length(), len); i++)
            if (hasher.substring_hash(hasher.length() - i, hasher.length()) == word_hash.substring_hash(0, i))
                overlap = i;

        for (int i = overlap; i < len; i++) {
            hasher.add_char(word[i]);
            result += word[i];
        }
    }

    cout << result << '\n';
}