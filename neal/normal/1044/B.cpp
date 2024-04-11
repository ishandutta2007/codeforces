#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> adj;
vector<int> my_tree, li_tree;
vector<bool> in_mine, in_li;
vector<int> touched;

int query(char type, int v) {
    cout << type << ' ' << v + 1 << endl;
    int x;
    cin >> x;
    return x - 1;
}

void answer(int v) {
    cout << "C " << (v == -1 ? -1 : v + 1) << endl;
}

void read_tree(vector<int> &tree, vector<bool> &in) {
    tree.clear();
    int n;
    cin >> n;
    in.assign(N, false);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        tree.push_back(x);
        in[x] = true;
    }
}

void dfs(int node, int parent) {
    if (in_mine[node]) {
        touched.push_back(node);
        return;
    }

    for (int neighbor : adj[node])
        if (neighbor != parent)
            dfs(neighbor, node);
}

void solve_case() {
    cin >> N;
    adj.assign(N, {});

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    read_tree(my_tree, in_mine);
    read_tree(li_tree, in_li);

    touched.clear();
    int li = query('B', li_tree[0]);
    dfs(li, -1);
    assert(touched.size() == 1);
    int potential = query('A', touched[0]);
    answer(in_li[potential] ? touched[0] : -1);
}

int main() {
    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}