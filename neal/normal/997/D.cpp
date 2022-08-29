#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

template<typename T1, typename T2>
void mod_add(T1 &a, T2 b) {
    a += b;

    if (a >= MOD)
        a -= MOD;
}

struct tree {
    int N, K;
    vector<vector<int>> adj;

    void init(int n, int k) {
        N = n;
        K = k;
        adj.clear();
        adj.resize(N);
    }

    void read_input() {
        for (int i = 0; i < N - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }

    vector<int> dfs(int node, int parent, vector<int> &full_cycle_count) {
        vector<int> children(K + 1, 0);

        for (int child : adj[node]) {
            if (child == parent)
                continue;

            const vector<int> &child_cycles = dfs(child, node, full_cycle_count);

            for (int k = 0; k <= K; k++)
                mod_add(children[k], child_cycles[k]);
        }

        mod_add(full_cycle_count[0], 1);
        vector<int> node_cycles(K + 1, 0);
        node_cycles[0] = 1;

        for (int k = 1; k <= K; k++)
            for (int first = 1; first <= k; first++) {
                long long cycle_count = (long long) children[first - 1] * node_cycles[k - first] % MOD;

                // node -> child -> first-length cycle back to child -> node -> (k - first) more
                mod_add(node_cycles[k], cycle_count);

                // Same as above, but with first different possible starting points (no longer need to start at node)
                mod_add(full_cycle_count[k], cycle_count * (2 * first) % MOD);
            }

        return node_cycles;
    }

    vector<int> calculate_paths() {
        vector<int> full_cycle_count(K + 1, 0);
        dfs(0, -1, full_cycle_count);
        return full_cycle_count;
    }
};

int N1, N2, K;
tree tree1, tree2;

long long mod_inv(long long a, long long m = MOD) {
    return a == 1 ? 1 : m - mod_inv(m % a, a) * m / a;
}

long long choose(int n, int r) {
    long long result = 1;

    for (int i = 0; i < r; i++)
        result = result * (n - i) % MOD * mod_inv(i + 1) % MOD;

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N1 >> N2 >> K;

    if (K % 2 != 0) {
        cout << 0 << '\n';
        return 0;
    }

    K /= 2;
    tree1.init(N1, K);
    tree2.init(N2, K);

    tree1.read_input();
    tree2.read_input();

    vector<int> dp1 = tree1.calculate_paths();
    vector<int> dp2 = tree2.calculate_paths();

    long long total = 0;

    for (int k = 0; k <= K; k++)
        mod_add(total, choose(2 * K, 2 * k) * dp1[k] % MOD * dp2[K - k] % MOD);

    cout << total << '\n';
    return 0;
}