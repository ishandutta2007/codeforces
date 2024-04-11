#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

int N;
vector<int> degree;
vector<vector<int>> adj;

vector<int> depth;
vector<int> parent;

void dfs(int node, int par) {
    depth[node] = par < 0 ? 0 : depth[par] + 1;
    parent[node] = par;

    for (int neighbor : adj[node])
        if (neighbor != par)
            dfs(neighbor, node);
}

int find_farthest(int node) {
    dfs(node, -1);
    int far = -1;

    for (int i = 0; i < N; i++)
        if (degree[i] >= 3 && (far == -1 || depth[i] > depth[far]))
            far = i;

    return far;
}

void erase_edge(int a, int b) {
    adj[a].erase(find(adj[a].begin(), adj[a].end(), b));
    adj[b].erase(find(adj[b].begin(), adj[b].end(), a));
}

struct dp_state {
    int deep;
    int far_sum;
    int far1, far2;
    int other_far1, other_far2;

    dp_state() : deep(-INF), far_sum(-INF), far1(-INF), far2(-INF), other_far1(-INF), other_far2(-INF) {}

    bool operator<(const dp_state &other) const {
        return make_pair(deep, far_sum) < make_pair(other.deep, other.far_sum);
    }

    dp_state operator+(const dp_state &other) const {
        dp_state sum;
        sum.deep = deep + other.deep;
        sum.far_sum = far_sum + other.far_sum;
        sum.far1 = far1;
        sum.far2 = far2;
        sum.other_far1 = other.far1;
        sum.other_far2 = other.far2;
        return sum;
    }
};

dp_state best;

int get_depth(int num) {
    return num < 0 ? -INF : depth[num];
}

bool better(int candidate, int far) {
    return get_depth(candidate) > get_depth(far);
}

dp_state extend(dp_state state) {
    state.deep++;
    state.far_sum += 2;
    return state;
}

dp_state attach(dp_state root, const dp_state &child, int node) {
    best = max(best, root + child);

    if (child.deep >= 0 && root < child) {
        root = child;
    } else if (root.deep < 0) {
        if (better(child.far1, root.far1)) {
            root.far2 = root.far1;
            root.far1 = child.far1;
        } else if (better(child.far1, root.far2)) {
            root.far2 = child.far1;
        }

        root.far_sum = get_depth(root.far1) + get_depth(root.far2) - 2 * depth[node];
    }

    return root;
}

dp_state solve(int node, int par) {
    dp_state root;
    root.far1 = node;

    for (int neighbor : adj[node])
        if (neighbor != par) {
            dp_state child = solve(neighbor, node);
            root = attach(root, extend(child), node);
        }

    if (degree[node] >= 3)
        root.deep = max(root.deep, 0);

    return root;
}

int main() {
    scanf("%d", &N);
    degree.assign(N + 1, 0);
    adj.assign(N + 1, {});

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    depth.resize(N + 1);
    parent.resize(N + 1);
    int index = -1;

    for (int i = 0; i < N; i++)
        if (degree[i] >= 3)
            index = i;

    assert(index >= 0);
    int A = find_farthest(index);
    int B = find_farthest(A);
    assert(depth[A] == 0);
    assert(A != B);
    int center = B;

    for (int iter = 0; iter < depth[B] / 2; iter++)
        center = parent[center];

    // Check if A and B are neighbors.
    if (parent[B] == A) {
        erase_edge(A, B);
        adj[N].push_back(A);
        adj[N].push_back(B);
        center = N;
    }

    best = dp_state();
    dfs(center, -1);
    solve(center, -1);
    printf("%d %d\n", best.far1 + 1, best.other_far1 + 1);
    printf("%d %d\n", best.far2 + 1, best.other_far2 + 1);
}