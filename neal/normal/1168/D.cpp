#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int N_MAX = 1.5e5 + 5;
const int LETTERS = 26;
const int INF = 1e9 + 5;

struct solution {
    int counts[LETTERS + 1];
    int total = 0;

    bool valid() const {
        return counts[0] >= 0;
    }

    void add(int x) {
        assert(0 <= x && x <= LETTERS);
        counts[x]++;
        total++;
    }

    void remove(int x) {
        assert(0 <= x && x <= LETTERS);
        assert(counts[x] > 0);
        counts[x]--;
        total--;
    }

    void add(const solution &other) {
        for (int i = 0; i <= LETTERS; i++)
            counts[i] += other.counts[i];

        total += other.total;
    }

    bool merge(const solution &other) {
        if (!valid() || !other.valid()) {
            counts[0] = -INF;
            return false;
        }

        if (total == 0) {
            *this = other;
            return true;
        }

        assert(total == other.total);
        int sum = 0;

        for (int i = 1; i <= LETTERS; i++) {
            if (other.counts[i] > counts[i])
                counts[i] = other.counts[i];

            sum += counts[i];
        }

        counts[0] = total - sum;

        if (!valid())
            counts[0] = -INF;

        return valid();
    }

    int score() const {
        if (!valid())
            return -INF;

        int sum = 0;

        for (int i = 1; i <= LETTERS; i++)
            sum += (counts[0] + counts[i]) * i;

        return sum;
    }

    void print() const {
        cerr << "solution:" << endl;

        for (int i = 0; i <= LETTERS; i++)
            if (counts[i] > 0)
                cerr << i << ": " << counts[i] << endl;
    }
};

int N, Q;
int parent[N_MAX];
char edge[N_MAX];
int depth[N_MAX];
vector<int> children[N_MAX];
int closest_important[N_MAX];
solution up_solution[N_MAX];
solution subtree[N_MAX];
int down_to[N_MAX];

int convert(char c) {
    return c == '?' ? 0 : c - 'a' + 1;
}

bool is_leaf(int x) {
    return x != 0 && children[x].empty();
}

bool is_important(int x) {
    return x == 0 || children[x].size() == 2;
}

void dfs(int node, int important, solution sol) {
    closest_important[node] = important;
    up_solution[node] = sol;
    // cerr << node << ": " << closest_important[node] << endl;

    if (is_important(node)) {
        important = node;
        sol = solution();
    }

    for (int child : children[node]) {
        solution next_sol = sol;
        next_sol.add(convert(edge[child]));
        dfs(child, important, next_sol);
    }
}

int get_down_to(int x) {
    if (is_leaf(x) || is_important(x))
        return down_to[x] = x;

    if (down_to[x] >= 0)
        return down_to[x];

    assert(children[x].size() == 1);
    return down_to[x] = get_down_to(children[x].back());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    parent[0] = -1;
    depth[0] = 0;

    for (int i = 1; i < N; i++) {
        cin >> parent[i] >> edge[i];
        parent[i]--;
        depth[i] = depth[parent[i]] + 1;
        children[parent[i]].push_back(i);
    }

    int leaf_depth = -1;
    bool depth_mismatch = false;

    for (int i = 0; i < N; i++)
        if (is_leaf(i)) {
            if (leaf_depth < 0)
                leaf_depth = depth[i];
            else if (depth[i] != leaf_depth)
                depth_mismatch = true;
        }

    if (depth_mismatch) {
        for (int q = 0; q < Q; q++)
            cout << "Fou" << '\n';

        return 0;
    }

    dfs(0, 0, solution());

    for (int i = N - 1; i >= 0; i--)
        for (int child : children[i]) {
            solution child_sol = subtree[child];
            child_sol.add(convert(edge[child]));
            subtree[i].merge(child_sol);
        }

    memset(down_to, -1, sizeof(down_to));

    for (int i = 0; i < N; i++)
        down_to[i] = get_down_to(i);

    for (int q = 0; q < Q; q++) {
        int x;
        char c;
        cin >> x >> c;
        x--;
        char to_remove = edge[x];
        edge[x] = c;
        x = get_down_to(x);

        up_solution[x].remove(convert(to_remove));
        up_solution[x].add(convert(c));
        solution current = subtree[x];

        while (x != 0) {
            current.add(up_solution[x]);
            int y = closest_important[x];

            if (children[y].size() == 2) {
                int a = get_down_to(children[y][0]), b = get_down_to(children[y][1]);

                if (b == x)
                    swap(a, b);

                assert(a == x);
                assert(b != x);
                solution other = subtree[b];
                other.add(up_solution[b]);
                current.merge(other);
            }

            subtree[y] = current;
            x = y;
        }

        // subtree[0].print();
        int score = subtree[0].score();

        if (score < 0) {
            cout << "Fou" << '\n';
        } else {
            cout << "Shi " << score << '\n';
        }
    }
}