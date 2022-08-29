#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };

const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);


const int64_t INF64 = int64_t(2e18) + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<pair<int, int>>> adj(N);

    for (int i = 0; i < N; i++)
        adj[i].reserve(K);

    for (int i = 0; i < M; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        u--; v--;
        adj[u].emplace_back(weight, v);
    }

    vector<uint64_t> hashes(N);
    uint64_t hash_total = 0;

    for (int i = 0; i < N; i++) {
        hashes[i] = rng();
        hash_total += hashes[i];
    }

    vector<vector<uint64_t>> choice_sum(K + 1);

    for (int deg = 1; deg <= K; deg++)
        choice_sum[deg].assign(deg, 0);

    for (int i = 0; i < N; i++) {
        sort(adj[i].begin(), adj[i].end());
        int deg = int(adj[i].size());

        for (int x = 0; x < deg; x++)
            choice_sum[deg][x] += hashes[adj[i][x].second];
    }

    int64_t best_sum = INF64;
    int best_mask = -1;

    for (int mask = 0; mask < 1 << K; mask++) {
        int64_t left = 1, right = 1;

        for (int k = 1; k <= K; k++)
            if (mask >> (k - 1) & 1)
                left *= k;
            else
                right *= k;

        if (left + right < best_sum) {
            best_sum = left + right;
            best_mask = mask;
        }
    }

    cerr << best_sum << endl;

    auto &&multiply_array = [&](const vector<uint64_t> &sums, vector<uint64_t> choices) {
        vector<uint64_t> new_sums;
        new_sums.reserve(sums.size() * choices.size());

        for (uint64_t sum : sums)
            for (uint64_t choice : choices)
                new_sums.push_back(sum + choice);

        return new_sums;
    };

    auto &&build_sorted_sums = [&](int mask) {
        vector<uint64_t> sums = {0};

        for (int k = 1; k <= K; k++)
            if (mask >> (k - 1) & 1)
                sums = multiply_array(sums, choice_sum[k]);

        return sums;
    };

    vector<uint64_t> left_sums = build_sorted_sums(best_mask);
    vector<uint64_t> right_sums = build_sorted_sums(((1 << K) - 1) ^ best_mask);
    sort(right_sums.begin(), right_sums.end());
    int64_t answer = 0;

    for (uint64_t left : left_sums) {
        uint64_t goal = hash_total - left;
        answer += int(upper_bound(right_sums.begin(), right_sums.end(), goal) - lower_bound(right_sums.begin(), right_sums.end(), goal));
    }

    cout << answer << '\n';
}