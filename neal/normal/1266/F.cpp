#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T1, typename T2>
bool maximize(T1 &a, const T2 &b) {
    if (a < b) {
        a = b;
        return true;
    }

    return false;
}

int N;
vector<vector<int>> adj;

// deepest_up[node] = distance from node to the farthest node in parent's subtree.
// deepest_down[node] = distance from node to the farthest node in its own subtree.
vector<int> deepest_up, deepest_down;
vector<int> second_deepest;

void solve_down(int node, int parent) {
    // Erase the edge from node to parent.
    if (parent >= 0)
        adj[node].erase(find(adj[node].begin(), adj[node].end(), parent));

    deepest_down[node] = 0;
    second_deepest[node] = 0;

    for (int child : adj[node]) {
        assert(child != parent);
        solve_down(child, node);
        int candidate = deepest_down[child] + 1;

        if (candidate > deepest_down[node]) {
            second_deepest[node] = deepest_down[node];
            deepest_down[node] = candidate;
        } else if (candidate > second_deepest[node]) {
            second_deepest[node] = candidate;
        }
    }
}

void solve_up(int node, int parent) {
    int n = adj[node].size();
    vector<int> prefix_max(n, 0), suffix_max(n, 0);

    // Note that both prefix_max[i] and suffix_max[i] exclude i.
    for (int i = 0; i < n - 1; i++)
        prefix_max[i + 1] = max(prefix_max[i], deepest_down[adj[node][i]] + 1);

    for (int i = n - 1; i > 0; i--)
        suffix_max[i - 1] = max(suffix_max[i], deepest_down[adj[node][i]] + 1);

    for (int i = 0; i < n; i++)
        deepest_up[adj[node][i]] = 1 + max({deepest_up[node], prefix_max[i], suffix_max[i]});

    for (int child : adj[node]) {
        assert(child != parent);
        solve_up(child, node);
    }
}

int solve_diameter(int node, int parent) {
    int best = 0;
    int maximum = 0, second_maximum = 0;

    for (int child : adj[node]) {
        assert(child != parent);
        best = max(best, solve_diameter(child, node));
        int candidate = deepest_down[child] + 1;

        if (candidate > second_maximum) {
            second_maximum = candidate;

            if (second_maximum > maximum)
                swap(maximum, second_maximum);
        }
    }

    best = max(best, maximum + second_maximum);
    return best;
}

vector<int> answers;

int count_children_at_least(int node, int d) {
    int low = 0, high = adj[node].size();

    while (low < high) {
        int mid = (low + high) / 2;

        if (deepest_down[adj[node][mid]] + 1 >= d)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

void solve_equal(int node, int parent) {
    sort(adj[node].begin(), adj[node].end(), [&](int a, int b) {
        return deepest_down[a] > deepest_down[b];
    });

    for (int d = 1, count = adj[node].size(); d <= second_deepest[node]; d++) {
        int parent_count = deepest_up[node] >= d;

        while (count > 0 && deepest_down[adj[node][count - 1]] + 1 < d)
            count--;

        // assert(count == count_children_at_least(node, d));
        maximize(answers[2 * d], parent_count + count);
        maximize(answers[2 * d - 1], parent_count + count);
    }

    for (int child : adj[node]) {
        assert(child != parent);
        solve_equal(child, node);
    }
}

void solve_odd(int node, int parent) {
    // special case for 1
    maximize(answers[1], (int) adj[node].size() + 1 + (parent >= 0));

    // parent node is smaller
    for (int d = 1, count = adj[node].size(); d <= second_deepest[node]; d++) {
        int parent_count = deepest_up[node] >= d - 1;

        while (count > 0 && deepest_down[adj[node][count - 1]] + 1 < d)
            count--;

        // cerr << node << ' ' << d << ": " << parent_count << ' ' << count << endl;

        // assert(count == count_children_at_least(node, d));
        maximize(answers[2 * d - 1], parent_count + count);
    }

    // parent node is normal
    for (int d = 1, count = adj[node].size(); d <= second_deepest[node] + 1; d++) {
        int parent_count = deepest_up[node] >= d;
        bool has_minus_one = false;

        while (count > 0 && deepest_down[adj[node][count - 1]] + 1 < d) {
            count--;
            has_minus_one = true;
        }

        // cerr << "now " << node + 1 << ' ' << d << ": " << parent_count << ' ' << count << ' ' << has_minus_one << endl;

        // assert(count == count_children_at_least(node, d));
        maximize(answers[2 * d - 1], parent_count + count + has_minus_one);
    }

    for (int child : adj[node]) {
        assert(child != parent);
        solve_odd(child, node);
    }
}

void solve_even(int node, int parent) {
    // vector<int> up_counts(second_deepest[node] + 1, 0);

    // for (int d = 1, count = adj[node].size(); d <= second_deepest[node]; d++) {
    //     int parent_count = deepest_up[node] >= d;

    //     while (count > 0 && deepest_down[adj[node][count - 1]] + 1 < d)
    //         count--;

    //     assert(count == count_children_at_least(node, d));
    //     up_counts[d] = parent_count + count;
    // }

    for (int child : adj[node]) {
        for (int d = 1, count = adj[child].size(); d <= second_deepest[child]; d++) {
            while (count > 0 && deepest_down[adj[child][count - 1]] + 1 < d)
                count--;

            // assert(count == count_children_at_least(child, d));
            int up_count = deepest_up[node] >= d;
            up_count += count_children_at_least(node, d) - 1;
            maximize(answers[2 * d], count + up_count);
        }
    }

    for (int child : adj[node]) {
        assert(child != parent);
        solve_even(child, node);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    adj.assign(N, {});

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    deepest_down.assign(N, 0);
    deepest_up.assign(N, 0);
    second_deepest.assign(N, 0);
    solve_down(0, -1);
    solve_up(0, -1);

    // for (int i = 0; i < N; i++)
    //     cerr << i + 1 << ": " << deepest_down[i] << ' ' << deepest_up[i] << ' ' << second_deepest[i] << endl;

    int diameter = solve_diameter(0, -1);
    answers.assign(N + 1, 1);

    for (int k = 1; k <= diameter; k++)
        answers[k] = 2;

    solve_equal(0, -1);
    solve_odd(0, -1);
    solve_even(0, -1);

    for (int k = 1; k <= N; k++)
        cout << answers[k] << (k < N ? ' ' : '\n');
}