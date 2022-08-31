#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N_MAX = 100005;

int N, degree[N_MAX];
vector<int> adj[N_MAX];
vector<int> path_list;

void dfs(int node, int parent) {
    bool leaf = true;

    for (int i = 0; i < (int) adj[node].size(); i++) {
        int neighbor = adj[node][i];

        if (neighbor == parent)
            continue;

        leaf = false;
        dfs(neighbor, node);
    }

    if (leaf) {
        path_list.push_back(node);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }

    int highest = 0, second_highest = 0;
    int highest_index = -1, second_index = -1;

    for (int i = 0; i < N; i++) {
        if (degree[i] > second_highest) {
            second_highest = degree[i];
            second_index = i;

            if (second_highest > highest) {
                swap(highest, second_highest);
                swap(highest_index, second_index);
            }
        }
    }

    if (second_highest > 2) {
        cout << "No\n";
        return 0;
    }

    dfs(highest_index, -1);
    cout << "Yes\n";
    cout << path_list.size() << '\n';

    for (int i = 0; i < (int) path_list.size(); i++) {
        cout << highest_index + 1 << ' ' << path_list[i] + 1 << '\n';
    }

    return 0;
}