#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

struct solution {
    int value, a, b, c;

    solution(int _value = -INF, int _a = -INF, int _b = -INF, int _c = -INF) : value(_value), a(_a), b(_b), c(_c) {}

    bool operator<(const solution &other) const {
        return value < other.value;
    }
};

struct result {
    solution choice[4];
};

int N;
vector<vector<int>> adj;

result extend(result root) {
    root.choice[1].value++;
    root.choice[2].value++;
    return root;
}

result attach(result root, result child) {
    result answer = root;

    for (int i = 1; i <= 3; i++)
        answer.choice[i] = max(answer.choice[i], child.choice[i]);

    answer.choice[2] = max(answer.choice[2], solution(root.choice[1].value + child.choice[1].value,
                                                      root.choice[1].a, child.choice[1].a));
    answer.choice[3] = max(answer.choice[3], solution(root.choice[2].value + child.choice[1].value,
                                                      root.choice[2].a, root.choice[2].b, child.choice[1].a));
    answer.choice[3] = max(answer.choice[3], solution(root.choice[1].value + child.choice[2].value,
                                                      root.choice[1].a, child.choice[2].a, child.choice[2].b));

    return answer;
}

result dfs(int node, int parent) {
    result answer;
    answer.choice[1] = solution(0, node);

    for (int neighbor : adj[node])
        if (neighbor != parent) {
            result child = dfs(neighbor, node);
            answer = attach(answer, extend(child));
        }

    return answer;
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

    solution sol = dfs(0, -1).choice[3];
    cout << sol.value << '\n';
    cout << sol.a + 1 << ' ' << sol.b + 1 << ' ' << sol.c + 1 << '\n';
}