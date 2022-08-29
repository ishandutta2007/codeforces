#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct safe_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = splitmix64(
            chrono::steady_clock::now().time_since_epoch().count() * ((uint64_t) new char | 1));
        return splitmix64(x ^ FIXED_RANDOM);
    }
};

int N, M;
vector<long long> conflict;
gp_hash_table<long long, int8_t, safe_hash> save;

int solve(long long mask) {
    if (mask == 0)
        return 0;

    if (save.find(mask) != save.end())
        return save[mask];

    int first = __builtin_ctzll(mask);
    long long conflict_mask = mask & conflict[first];

    if (conflict_mask == 0)
        return 1 + solve(mask ^ 1LL << first);

    int answer = max(solve(mask ^ 1LL << first), 1 + solve(mask ^ 1LL << first ^ conflict_mask));
    return save[mask] = answer;
}

inline void add_conflicts(long long mask) {
    long long iter_mask = mask;

    while (iter_mask != 0) {
        int index = __builtin_ctzll(iter_mask);
        conflict[index] |= mask ^ 1LL << index;
        iter_mask -= 1LL << index;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    conflict.assign(M, 0);
    M = 0;

    map<string, int> name_to_index;
    long long running_mask = 0;

    for (int i = 0; i < N; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            add_conflicts(running_mask);
            running_mask = 0;
            continue;
        }

        string name;
        cin >> name;

        if (name_to_index.count(name) == 0)
            name_to_index[name] = M++;

        running_mask |= 1LL << name_to_index[name];
    }

    add_conflicts(running_mask);
    cout << solve((1LL << M) - 1) << '\n';
}