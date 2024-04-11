#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> degree;
vector<vector<int>> adj;

int no() {
    puts("No");
    return 0;
}

int main() {
    scanf("%d %d", &N, &K);
    adj.assign(N, vector<int>());
    degree.assign(N, 0);

    if (K > N || K > 32 - __builtin_clz(N))
        return no();

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    int removed_count = 0;

    for (int k = 0; k < K; k++) {
        vector<int> counts(N, 0);
        int leaves = 0;
        vector<int> to_remove;
        vector<int> to_decrement;

        for (int i = 0; i < N; i++)
            if (degree[i] == 1) {
                leaves++;
                to_remove.push_back(i);
                // cerr << k << ": remove " << i + 1 << endl;

                for (int neighbor : adj[i])
                    if (degree[neighbor] > 0)
                        to_decrement.push_back(neighbor);
            }

        if (leaves == 0) {
            // cerr << "leaves 0 " << k << endl;
            return no();
        }

        for (int v : to_remove) {
            degree[v]--;
            removed_count++;
        }

        for (int v : to_decrement) {
            degree[v]--;
            counts[v]++;
        }

        for (int i = 0; i < N; i++)
            if (counts[i] > 0) {
                if (counts[i] < 3) {
                    // cerr << "counts less than 3 " << k << endl;
                    return no();
                }

                if (degree[i] != 1 && k < K - 1) {
                    // cerr << "degree not 1 " << k << endl;
                    return no();
                }
            }
    }

    if (removed_count != N - 1) {
        // cerr << "removed not N - 1" << endl;
        return no();
    }

    puts("Yes");
}