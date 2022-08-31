#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;


mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * ((uint64_t) new char | 1));

typedef uint64_t hash_t;

// HASH_MULT is a random number that is 3 or 5 mod 8. This ensures the hash doesn't fail until matching length 1024.
const hash_t HASH_MULT = (rng() & ~7) + (rng() % 2 ? 3 : 5);

vector<hash_t> hash_pow;

template<typename T_string>
struct string_hash {
    static const unsigned JUMP = 1024;

    vector<hash_t> prefix_hash;
    vector<hash_t> jump_prefix;

    string_hash(const T_string &str = {}) {
        build(str);
    }

    hash_t get_jump_prefix(unsigned index) const {
        return index < JUMP ? 0 : jump_prefix[index - JUMP];
    }

    void build(const T_string &str) {
        if (hash_pow.empty())
            hash_pow = {1};

        while (hash_pow.size() <= str.size())
            hash_pow.push_back(HASH_MULT * hash_pow.back());

        prefix_hash.resize(str.size() + 1);
        prefix_hash[0] = 0;

        for (int i = 0; i < (int) str.size(); i++)
            prefix_hash[i + 1] = HASH_MULT * prefix_hash[i] + str[i];

        jump_prefix.resize(str.size());

        for (int i = 0; i < (int) str.size(); i++)
            jump_prefix[i] = HASH_MULT * get_jump_prefix(i) + str[i];
    }

    hash_t substring_hash(int start, int end) const {
        return prefix_hash[end] - prefix_hash[start] * hash_pow[end - start];
    }

    hash_t jump_hash(unsigned start, unsigned end) const {
        end += (start - end) & (JUMP - 1);
        return get_jump_prefix(end) - get_jump_prefix(start) * hash_pow[(end - start) / JUMP];
    }

    hash_t combined_hash(int start, int end) const {
        return substring_hash(start, end) + jump_hash(start, end) * hash_pow[end - start];
    }

    bool equal(int start1, int start2, int length) const {
        if (substring_hash(start1, start1 + length) != substring_hash(start2, start2 + length))
            return false;

        return jump_hash(start1, start1 + length) == jump_hash(start2, start2 + length);
    }
};


int N, M;
string S, T;
string_hash<string> hasher;

bool check(long long len0, long long len1) {
    int loc0 = -1, loc1 = -1, position = 0;

    for (int i = 0; i < N; i++)
        if (S[i] == '0') {
            if (loc0 == -1)
                loc0 = position;
            else if (!hasher.equal(loc0, position, len0))
                return false;

            position += len0;
        } else {
            if (loc1 == -1)
                loc1 = position;
            else if (!hasher.equal(loc1, position, len1))
                return false;

            position += len1;
        }

    assert(position == M);
    assert(loc0 >= 0 && loc1 >= 0);
    return !(len0 == len1 && hasher.equal(loc0, loc1, len0));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> S >> T;
    N = S.size();
    M = T.size();
    hasher.build(T);
    long long zeros = 0, ones = 0;

    for (int i = 0; i < N; i++)
        if (S[i] == '0')
            zeros++;
        else
            ones++;

    long long total = 0;

    for (long long len0 = 1; len0 <= M; len0++) {
        long long remaining = M - zeros * len0;

        if (remaining > 0 && remaining % ones == 0) {
            long long len1 = remaining / ones;

            if (check(len0, len1))
                total++;
        }
    }

    cout << total << '\n';
}