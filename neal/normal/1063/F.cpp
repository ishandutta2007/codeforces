#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * ((uint64_t) new char | 1));

typedef uint64_t hash_t;

// HASH_MULT is a random number that is 3 or 5 mod 8. This ensures the hash doesn't fail until length 1024.
const hash_t HASH_MULT = (rng() & ~7) | (rng() % 2 ? 3 : 5);

vector<hash_t> hash_pow, prefix_hash;

int N;
string S;

gp_hash_table<hash_t, int> last_seen;

hash_t substring_hash(int start, int end) {
    return prefix_hash[end] - prefix_hash[start] * hash_pow[end - start];
}

void prepare_hashes() {
    hash_pow.resize(N + 1);
    prefix_hash.resize(N + 1);

    hash_pow[0] = 1;
    prefix_hash[0] = 0;

    for (int i = 0; i < N; i++) {
        hash_pow[i + 1] = HASH_MULT * hash_pow[i];
        prefix_hash[i + 1] = HASH_MULT * prefix_hash[i] + S[i];
    }
}

int latest_index(int start, int length) {
    hash_t hash = substring_hash(start, start + length);
    return last_seen.find(hash) == last_seen.end() ? -1 : last_seen[hash];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    prepare_hashes();
    last_seen[0] = N;
    int answer = 0, longest = 0;

    for (int i = N - 1; i >= 0; i--) {
        longest++;

        while (longest > 0 && max(latest_index(i, longest - 1), latest_index(i + 1, longest - 1)) < i + longest)
            longest--;

        answer = max(answer, longest);

        for (int len = longest; len > 0 && last_seen.find(substring_hash(i, i + len)) == last_seen.end(); len--)
            last_seen[substring_hash(i, i + len)] = i;
    }

    cout << answer << '\n';
}