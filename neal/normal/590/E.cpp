#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// This version of aho_corasick uses more memory and depends on a small constant-sized alphabet, but it's slightly
// faster in runtime.
template<char MIN_CHAR = 'a', int ALPHABET = 26>
struct aho_corasick {
    struct node {
        // suff = the index of the node of the longest suffix of the current node that's also in the tree.
        //   Also see "blue arcs" on Wikipedia: https://en.wikipedia.org/wiki/Aho%E2%80%93Corasick_algorithm
        // dict = the index of the node of the longest suffix of the current node that's in the word list.
        //   Also see "green arcs" on Wikipedia.
        // depth = normal trie depth (root is 0).
        // word_index = the index of the *first* word ending at this node. -1 if none.
        // word_count = the total number of words ending at this node.
        // link = the trie connections and/or suffix connections from this node.
        int suff = -1, dict = -1, depth = 0;
        int word_index = -1, word_count = 0;
        int link[ALPHABET];

        node() {
            fill(link, link + ALPHABET, -1);
        }

        int& operator[](char c) {
            return link[c - MIN_CHAR];
        }
    };

    int N, W;
    vector<node> nodes;
    vector<int> word_location;
    vector<int> word_indices_by_depth;
    vector<int> defer;

    aho_corasick(const vector<string> &words = {}) {
        if (!words.empty())
            build(words);
    }

    // Builds the adj list based on suffix parents. Often we want to perform DP and/or queries on this tree.
    vector<vector<int>> build_suffix_adj() const {
        vector<vector<int>> adj(N);

        for (int i = 1; i < N; i++)
            adj[nodes[i].suff].push_back(i);

        return adj;
    }

    int get_or_add_child(int current, char c) {
        if (nodes[current][c] >= 0)
            return nodes[current][c];

        int index = N;
        nodes[current][c] = index;
        nodes[N++].depth = nodes[current].depth + 1;
        return index;
    }

    int add_word(const string &word, int word_index) {
        assert(!nodes.empty());
        int current = 0;

        for (char c : word)
            current = get_or_add_child(current, c);

        if (nodes[current].word_index < 0)
            nodes[current].word_index = word_index;

        nodes[current].word_count++;
        return current;
    }

    // Returns where in the trie we should end up after starting at `location` and adding char `c`.
    int get_suffix_link(int location, char c) const {
        if (location >= 0)
            location = nodes[location].link[c - MIN_CHAR];

        return max(location, 0);
    }

    void build(const vector<string> &words) {
        nodes.resize(1e7 + 5);
        N = 0;
        nodes[N++] = node();
        W = words.size();
        word_location.resize(W);
        defer.resize(W);
        int max_depth = 0;

        for (int i = 0; i < W; i++) {
            word_location[i] = add_word(words[i], i);
            max_depth = max(max_depth, (int) words[i].size());
            defer[i] = nodes[word_location[i]].word_index;
        }

        // Create a list of word indices in decreasing order of depth, in linear time via counting sort.
        word_indices_by_depth.resize(words.size());
        vector<int> depth_freq(max_depth + 1, 0);

        for (int i = 0; i < (int) words.size(); i++)
            depth_freq[words[i].size()]++;

        for (int i = max_depth - 1; i >= 0; i--)
            depth_freq[i] += depth_freq[i + 1];

        for (int i = 0; i < (int) words.size(); i++)
            word_indices_by_depth[--depth_freq[words[i].size()]] = i;

        // Solve suffix parents by traversing in order of depth (BFS order).
        vector<int> q = {0};

        for (int i = 0; i < (int) q.size(); i++) {
            int current = q[i];

            for (char c = MIN_CHAR; c < MIN_CHAR + ALPHABET; c++) {
                int &index = nodes[current][c];

                if (index >= 0) {
                    // Find index's suffix parent by traversing suffix parents of current until one of them has a child c.
                    int suffix_parent = get_suffix_link(nodes[current].suff, c);
                    nodes[index].suff = suffix_parent;
                    nodes[index].word_count += nodes[suffix_parent].word_count;
                    nodes[index].dict = nodes[suffix_parent].word_index >= 0 ? suffix_parent : nodes[suffix_parent].dict;
                    q.push_back(index);
                } else {
                    index = get_suffix_link(nodes[current].suff, c);
                }
            }
        }
    }

    // Counts the number of matches of each word in O(text length + num words).
    vector<int> count_matches(const string &text) const {
        vector<int> matches(W, 0);
        int current = 0;

        for (char c : text) {
            current = get_suffix_link(current, c);
            int dict_node = nodes[current].word_index >= 0 ? current : nodes[current].dict;

            if (dict_node >= 0)
                matches[nodes[dict_node].word_index]++;
        }

        // Iterate in decreasing order of depth.
        for (int word_index : word_indices_by_depth) {
            int location = word_location[word_index];
            int dict_node = nodes[location].dict;

            if (dict_node >= 0)
                matches[nodes[dict_node].word_index] += matches[word_index];
        }

        for (int i = 0; i < W; i++)
            matches[i] = matches[defer[i]];

        return matches;
    }

    // Counts the total number of matches of all words within text in O(text length).
    long long count_total_matches(const string &text) const {
        long long matches = 0;
        int current = 0;

        for (char c : text) {
            current = get_suffix_link(current, c);
            matches += nodes[current].word_count;
        }

        return matches;
    }
};

struct dinic_matching {
    static const int INF = 1e9 + 5;

    int N = -1, M = -1;
    vector<vector<int>> adj;
    vector<int> dist;
    vector<int> prev;
    vector<int> q;
    int q_start, q_end;
    vector<bool> matched;
    vector<int> edge_index;

    dinic_matching(int n = -1, int m = -1) {
        if (n >= 0 && m >= 0)
            init(n, m);
    }

    void init(int n, int m) {
        N = n;
        M = m;

        adj.assign(N, {});
        dist.resize(N);
        q.resize(N);
        matched.resize(N);
        edge_index.resize(N);

        prev.resize(M);
    }

    void add_edge(int a, int b) {
        adj[a].push_back(b);
    }

    bool bfs() {
        fill(dist.begin(), dist.end(), INF);
        q_start = q_end = 0;

        for (int i = 0; i < N; i++)
            if (!matched[i])
                bfs_check(i, 0);

        bool has_path = false;

        while (q_start < q_end) {
            int num = q[q_start++];

            for (int next : adj[num])
                if (prev[next] < 0)
                    has_path = true;
                else
                    bfs_check(prev[next], dist[num] + 1);
        }

        return has_path;
    }

    void bfs_check(int num, int potential_dist) {
        if (potential_dist < dist[num]) {
            dist[num] = potential_dist;
            q[q_end++] = num;
        }
    }

    bool dfs(int num) {
        // Because we are only performing DFS in increasing order of dist, we don't have to revisit fully searched edges
        // again later.
        while (edge_index[num] < (int) adj[num].size()) {
            int next = adj[num][edge_index[num]];
            bool solved = false;

            if (prev[next] < 0 || (dist[num] + 1 == dist[prev[next]] && dfs(prev[next]))) {
                prev[next] = num;
                matched[num] = true;
                solved = true;
            }

            edge_index[num]++;

            if (solved)
                return true;
        }

        dist[num] = INF;
        return false;
    }

    int match() {
        assert(N >= 0 && M >= 0);

        for (int i = 0; i < N; i++)
            matched[i] = false;

        for (int j = 0; j < M; j++)
            prev[j] = -1;

        int matches = 0;

        while (bfs()) {
            for (int i = 0; i < N; i++)
                edge_index[i] = 0;

            for (int i = 0; i < N; i++)
                if (!matched[i] && dfs(i))
                    matches++;
        }

        return matches;
    }

    vector<bool> reachable_left, reachable_right;

    void reachable_dfs(int left) {
        reachable_left[left] = true;

        for (int right : adj[left])
            if (prev[right] != left && !reachable_right[right]) {
                reachable_right[right] = true;
                int next_left = prev[right];

                if (next_left >= 0 && !reachable_left[next_left])
                    reachable_dfs(next_left);
            }
    }

    // The min vertex cover in a bipartite graph corresponds to the min cut in its flow graph.
    vector<int> min_vertex_cover() {
        int size = match();
        reachable_left.assign(N, false);
        reachable_right.assign(M, false);

        for (int i = 0; i < N; i++)
            if (!matched[i] && !reachable_left[i])
                reachable_dfs(i);

        vector<int> cover;

        for (int i = 0; i < N; i++)
            if (!reachable_left[i])
                cover.push_back(i);

        for (int i = 0; i < M; i++)
            if (reachable_right[i])
                cover.push_back(N + i);

        assert((int) cover.size() == size);
        return cover;
    }

    // The max independent set is the complement of the min vertex cover.
    vector<int> max_independent_set() {
        int cover_size = min_vertex_cover().size();
        vector<int> independent_set;

        for (int i = 0; i < N; i++)
            if (reachable_left[i])
                independent_set.push_back(i);

        for (int i = 0; i < M; i++)
            if (!reachable_right[i])
                independent_set.push_back(N + i);

        assert((int) independent_set.size() == N + M - cover_size);
        return independent_set;
    }
};


int N;
vector<string> greetings;
aho_corasick<'a', 2> AC;
vector<vector<bool>> contains;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    greetings.resize(N);

    for (string &greeting : greetings)
        cin >> greeting;

    AC.build(greetings);
    contains.assign(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        vector<int> matches = AC.count_matches(greetings[i]);

        for (int j = 0; j < N; j++)
            contains[i][j] = matches[j] > 0;
    }

    // https://en.wikipedia.org/wiki/Dilworth%27s_theorem#Proof_via_K%C5%91nig's_theorem
    dinic_matching graph(N, N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i != j && contains[i][j])
                graph.add_edge(i, j);

    vector<int> vertex_cover = graph.min_vertex_cover();
    vector<bool> in_cover(N, false);

    for (int v : vertex_cover)
        in_cover[v % N] = true;

    vector<int> independent_set;

    for (int i = 0; i < N; i++)
        if (!in_cover[i])
            independent_set.push_back(i);

    cout << independent_set.size() << '\n';

    for (int i = 0; i < (int) independent_set.size(); i++)
        cout << independent_set[i] + 1 << (i < (int) independent_set.size() - 1 ? ' ' : '\n');
}