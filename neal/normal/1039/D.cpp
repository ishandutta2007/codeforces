#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int N_MAX = 1e5 + 5;

int N;
vector<int> adj[N_MAX];
vector<int> postorder, parent_list;
int longest[N_MAX], second_longest[N_MAX];
int answers[N_MAX];

void dfs(int node, int parent) {
    for (int child : adj[node])
        if (child != parent)
            dfs(child, node);

    postorder.push_back(node);
    parent_list.push_back(parent);
}

int solve(int k) {
    for (int i = 0; i < N; i++)
        longest[i] = second_longest[i] = 0;

    int paths = 0;

    for (int i = 0; i < N; i++) {
        int node = postorder[i];
        int parent = parent_list[i];

        if (longest[node] + second_longest[node] + 1 >= k) {
            paths++;
        } else if (parent != -1 && longest[node] + 1 > second_longest[parent]) {
            second_longest[parent] = longest[node] + 1;

            if (second_longest[parent] > longest[parent])
                swap(longest[parent], second_longest[parent]);
        }
    }

    return paths;
}

map<int, int> save;

int get_answer(int k) {
    if (save.find(k) == save.end())
        save[k] = solve(k);

    return save[k];
}

void recurse(int a, int b) {
    answers[a] = get_answer(a);
    answers[b] = get_answer(b);

    if (a + 1 >= b)
        return;

    if (answers[a] == answers[b]) {
        for (int i = a; i <= b; i++)
            answers[i] = answers[a];

        return;
    }

    int mid = (a + b) / 2;
    recurse(a, mid);
    recurse(mid, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);
    recurse(1, N);

    for (int k = 1; k <= N; k++)
        cout << answers[k] << '\n';
}