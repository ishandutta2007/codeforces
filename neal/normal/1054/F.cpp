#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

struct dinic_matching {
    int n, m;
    vector<vector<int>> adj;
    vector<int> dist;
    vector<bool> matched;
    vector<int> edge_index;
    vector<int> prv;

    dinic_matching() {
        init(0, 0);
    }

    dinic_matching(int _n, int _m) {
        init(_n, _m);
    }

    void init(int _n, int _m) {
        n = _n;
        m = _m;
        adj.assign(n, {});
        dist.resize(n);
        matched.resize(n);
        edge_index.resize(n);
        prv.resize(m);
    }

    void add_edge(int a, int b) {
        assert(0 <= a && a < n);
        assert(0 <= b && b < m);
        adj[a].push_back(b);
    }

    void bfs_check(queue<int> &q, int left, int new_dist) {
        if (new_dist < dist[left]) {
            dist[left] = new_dist;
            q.push(left);
        }
    }

    bool bfs() {
        dist.assign(n, INF);
        queue<int> q;

        for (int i = 0; i < n; i++)
            if (!matched[i])
                bfs_check(q, i, 0);

        bool has_path = false;

        while (!q.empty()) {
            int left = q.front(); q.pop();

            for (int right : adj[left])
                if (prv[right] < 0)
                    has_path = true;
                else
                    bfs_check(q, prv[right], dist[left] + 1);
        }

        return has_path;
    }

    bool dfs(int left) {
        // Because we are only performing DFS in increasing order of dist, we don't have to revisit fully searched edges
        // again later.
        while (edge_index[left] < int(adj[left].size())) {
            int right = adj[left][edge_index[left]];
            bool solved = false;

            if (prv[right] < 0 || (dist[left] + 1 == dist[prv[right]] && dfs(prv[right]))) {
                prv[right] = left;
                matched[left] = true;
                solved = true;
            }

            edge_index[left]++;

            if (solved)
                return true;
        }

        dist[left] = INF;
        return false;
    }

    int match() {
        matched.assign(n, false);
        prv.assign(m, -1);
        int matches = 0;

        while (bfs()) {
            edge_index.assign(n, 0);

            for (int i = 0; i < n; i++)
                if (!matched[i] && dfs(i))
                    matches++;
        }

        return matches;
    }

    vector<bool> reachable_left, reachable_right;

    void reachable_dfs(int left) {
        reachable_left[left] = true;

        for (int right : adj[left])
            if (prv[right] != left && !reachable_right[right]) {
                reachable_right[right] = true;
                int next_left = prv[right];

                if (next_left >= 0 && !reachable_left[next_left])
                    reachable_dfs(next_left);
            }
    }

    // The min vertex cover in a bipartite graph corresponds to the min cut in its flow graph.
    vector<int> min_vertex_cover() {
        int match_size = match();
        reachable_left.assign(n, false);
        reachable_right.assign(m, false);

        for (int i = 0; i < n; i++)
            if (!matched[i] && !reachable_left[i])
                reachable_dfs(i);

        vector<int> cover;

        for (int i = 0; i < n; i++)
            if (!reachable_left[i])
                cover.push_back(i);

        for (int i = 0; i < m; i++)
            if (reachable_right[i])
                cover.push_back(n + i);

        assert(int(cover.size()) == match_size);
        return cover;
    }

    // The max independent set is the complement of the min vertex cover.
    vector<int> max_independent_set() {
        int cover_size = int(min_vertex_cover().size());
        vector<int> independent_set;

        for (int i = 0; i < n; i++)
            if (reachable_left[i])
                independent_set.push_back(i);

        for (int i = 0; i < m; i++)
            if (!reachable_right[i])
                independent_set.push_back(n + i);

        assert(int(independent_set.size()) + cover_size == n + m);
        return independent_set;
    }
};


int N, A, B;
vector<int> X, Y;
map<int, vector<pair<int, int>>> x_map, y_map;
vector<pair<int, int>> x_segments, y_segments;

bool interior_intersect(pair<int, int> x_indices, pair<int, int> y_indices) {
    int x = X[x_indices.first], y1 = Y[x_indices.first], y2 = Y[x_indices.second];
    int y = Y[y_indices.first], x1 = X[y_indices.first], x2 = X[y_indices.second];
    assert(y1 < y2 && x1 < x2);
    bool strict_x = x1 < x && x < x2;
    bool strict_y = y1 < y && y < y2;
    bool nonstrict_x = x1 <= x && x <= x2;
    bool nonstrict_y = y1 <= y && y <= y2;
    return nonstrict_x && nonstrict_y && (strict_x || strict_y);
}

vector<pair<int, int>> get_segments(auto &coord_map) {
    vector<pair<int, int>> segments;

    for (auto &p : coord_map) {
        auto &vec = p.second;
        sort(vec.begin(), vec.end());
        int n = vec.size();

        for (int i = 0; i < n - 1; i++)
            segments.emplace_back(vec[i].second, vec[i + 1].second);
    }

    return segments;
}

vector<int> fusable_segments() {
    dinic_matching graph(A, B);

    for (int i = 0; i < A; i++)
        for (int j = 0; j < B; j++)
            if (interior_intersect(x_segments[i], y_segments[j]))
                graph.add_edge(i, j);

    return graph.max_independent_set();
}

void mark_index(auto &pairs, int index) {
    for (auto &p : pairs)
        if (p.second == index)
            p.second = -1;
}

void output_segments(auto &coord_map, auto &&output) {
    for (auto &p : coord_map) {
        int coord = p.first;
        auto &vec = p.second;
        int n = vec.size(), start = 0;

        while (start < n) {
            int end = start;

            while (end < n && vec[end].second == -1)
                end++;

            output(coord, vec[start].first, vec[end].first);
            start = end + 1;
        }
    }
}

int main() {
    cin >> N;
    X.resize(N);
    Y.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        x_map[X[i]].emplace_back(Y[i], i);
        y_map[Y[i]].emplace_back(X[i], i);
    }

    x_segments = get_segments(x_map);
    y_segments = get_segments(y_map);
    A = x_segments.size();
    B = y_segments.size();
    vector<int> fusable = fusable_segments();
    int x_fuses = 0, y_fuses = 0;

    for (int index : fusable)
        if (index < A) {
            int first = x_segments[index].first;
            mark_index(x_map[X[first]], first);
            x_fuses++;
        } else {
            int first = y_segments[index - A].first;
            mark_index(y_map[Y[first]], first);
            y_fuses++;
        }

    cout << N - y_fuses << '\n';

    output_segments(y_map, [](int y, int x1, int x2) {
        cout << x1 << ' ' << y << ' ' << x2 << ' ' << y << '\n';
    });

    cout << N - x_fuses << '\n';

    output_segments(x_map, [](int x, int y1, int y2) {
        cout << x << ' ' << y1 << ' ' << x << ' ' << y2 << '\n';
    });
}