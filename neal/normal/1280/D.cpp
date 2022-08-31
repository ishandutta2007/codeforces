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

const int MAX = 3005;
const int INF = 1e9 + 5;

using dp_pair = pair<int, long long>;

struct result {
    dp_pair dp[MAX];
    int maximum = 0;

    result() {
        init();
    }

    void init() {
        maximum = 0;

        for (int i = 0; i < MAX; i++)
            dp[i] = {-INF, 0};
    }
};

int N, M;
vector<long long> D;
vector<vector<int>> adj;
result results[MAX];

int final_score(const dp_pair &dp) {
    return dp.first + (dp.second > 0);
}

void extend(result &) {
    return;
}

void attach(result &root, const result &child) {
    result combined;
    combined.maximum = root.maximum + child.maximum;

    for (int m_root = 1; m_root <= root.maximum; m_root++)
        for (int m_child = 1; m_child <= child.maximum; m_child++) {
            const dp_pair &root_dp = root.dp[m_root];
            const dp_pair &child_dp = child.dp[m_child];

            // Finalize child, add separately.
            maximize(combined.dp[m_root + m_child], dp_pair(root_dp.first + final_score(child_dp), root_dp.second));

            // Combine the two partitions.
            maximize(combined.dp[m_root + m_child - 1], dp_pair(root_dp.first + child_dp.first, root_dp.second + child_dp.second));
        }

    root = combined;
}

void dfs(int node, int parent) {
    result &answer = results[node];
    answer.maximum = 1;
    answer.dp[1] = {0, D[node]};

    for (int neighbor : adj[node])
        if (neighbor != parent) {
            dfs(neighbor, node);
            extend(results[neighbor]);
            attach(answer, results[neighbor]);
        }
}

void solve_case() {
    cin >> N >> M;
    vector<int> B(N), W(N);

    for (int &b : B)
        cin >> b;

    for (int &w : W)
        cin >> w;

    D.resize(N);

    for (int i = 0; i < N; i++)
        D[i] = W[i] - B[i];

    adj.assign(N, {});

    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 0; i < N; i++)
        results[i].init();

    dfs(0, -1);
    cout << final_score(results[0].dp[M]) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}