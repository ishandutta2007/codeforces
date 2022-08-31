#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<long long> adj;
vector<pair<int, int>> edges;
int A, B;

// For every mask, computes the sum of values[sub] where sub is a submask of mask.
template<typename T_out, typename T_in>
vector<T_out> submask_sums(int n, const vector<T_in> &values) {
    vector<T_out> dp(values.begin(), values.end());

    for (int bit = 0; bit < n; bit++)
        for (int mask = 0; mask < 1 << n; mask++)
            if (mask >> bit & 1)
                dp[mask] += dp[mask ^ 1 << bit];

    return dp;
}

long long count_no_twos() {
    A = N / 2;
    B = N - A;
    vector<bool> left_mask(1 << A, false), right_mask(1 << B, false);

    for (int mask = 0; mask < 1 << A; mask++) {
        bool valid = true;

        for (int i = 0; i < A; i++)
            if (mask >> i & 1)
                if (mask & adj[i]) {
                    valid = false;
                    break;
                }

        left_mask[mask] = valid;
    }

    for (int mask = 0; mask < 1 << B; mask++) {
        bool valid = true;

        for (int i = 0; i < B; i++)
            if (mask >> i & 1)
                if (mask & (adj[A + i] >> A)) {
                    valid = false;
                    break;
                }

        right_mask[mask] = valid;
    }

    vector<int> left_mask_counts = submask_sums<int>(A, left_mask);
    long long answer = 0;

    for (int mask = 0; mask < 1 << B; mask++)
        if (right_mask[mask]) {
            int acceptable = (1 << A) - 1;

            for (int i = 0; i < B; i++)
                if (mask >> i & 1)
                    acceptable &= ~adj[A + i];

            answer += left_mask_counts[acceptable];
        }

    return answer;
}

vector<bool> visited;
vector<int> depth;

void dfs(int node, int dep) {
    assert(!visited[node]);
    visited[node] = true;
    depth[node] = dep;

    for (long long prefix = adj[node]; prefix != 0; prefix &= prefix - 1) {
        int neighbor = __builtin_ctzll(prefix);

        if (!visited[neighbor])
            dfs(neighbor, dep + 1);
    }
}

long long count_no_ones() {
    visited.assign(N, false);
    depth.resize(N);
    int components = 0;

    for (int i = 0; i < N; i++)
        if (!visited[i]) {
            dfs(i, 0);
            components++;
        }

    return 1LL << components;
}

long long count_all_twos() {
    vector<bool> must_be_one(N, false);

    for (pair<int, int> &edge : edges)
        must_be_one[edge.first] = must_be_one[edge.second] = true;

    long long answer = 1;

    for (int i = 0; i < N; i++)
        if (!must_be_one[i])
            answer *= 2;

    return answer;
}

long long count_all_ones() {
    visited.assign(N, false);
    depth.resize(N);
    int components = 0;

    for (int i = 0; i < N; i++)
        if (!visited[i]) {
            dfs(i, 0);
            components++;
        }

    // Ensure the graph is bipartite.
    for (pair<int, int> &edge : edges)
        if (depth[edge.first] % 2 == depth[edge.second] % 2)
            return 0;

    return 1LL << components;
}

int main() {
    cin >> N >> M;

    if (M == 0) {
        cout << 0 << '\n';
        return 0;
    }

    adj.assign(N, 0);

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        edges.emplace_back(x, y);
        adj[x] |= 1LL << y;
        adj[y] |= 1LL << x;
    }

    // cerr << "no twos: " << count_no_twos() << endl;
    // cerr << "no ones: " << count_no_ones() << endl;
    // cerr << "all twos: " << count_all_twos() << endl;
    // cerr << "all ones: " << count_all_ones() << endl;

    long long opposite = 2 * count_no_twos() + count_no_ones();
    opposite -= 2 * count_all_twos() + count_all_ones();
    cout << (1LL << N) - opposite << '\n';
}