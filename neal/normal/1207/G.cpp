#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

template<typename T>
struct fenwick_tree {
    int tree_n = 0;
    vector<T> tree;

    fenwick_tree(int n = 0) {
        if (n > 0)
            init(n);
    }

    void init(int n) {
        tree_n = n;
        tree.assign(tree_n + 1, 0);
    }

    // O(n) initialization of the Fenwick tree.
    template<typename T_array>
    void build(const T_array &initial) {
        assert((int) initial.size() == tree_n);

        for (int i = 1; i <= tree_n; i++) {
            tree[i] = initial[i - 1];

            for (int k = (i & -i) >> 1; k > 0; k >>= 1)
                tree[i] += tree[i - k];
        }
    }

    // index is in [0, tree_n).
    void update(int index, const T &change) {
        for (int i = index + 1; i <= tree_n; i += i & -i)
            tree[i] += change;
    }

    // Returns the sum of the range [0, count).
    T query(int count) const {
        T sum = 0;

        for (int i = count; i > 0; i -= i & -i)
            sum += tree[i];

        return sum;
    }
};

template<typename T>
struct subtree_sum_DS {
    int n = 0;
    bool vertex_mode;
    vector<vector<int>> adj;
    vector<int> parent;
    vector<int> tour_start, tour_end;
    vector<T> values;
    fenwick_tree<T> tree;

    subtree_sum_DS() {}

    subtree_sum_DS(int _n, bool _vertex_mode) {
        init(_n, _vertex_mode);
    }

    void init(int _n, bool _vertex_mode) {
        n = _n;
        vertex_mode = _vertex_mode;
        adj.assign(n, {});
        parent.resize(n);

        tour_start.assign(n, -INF);
        tour_end.assign(n, -INF);

        values.assign(n, 0);
        tree.init(n);
    }

    void init(const vector<vector<int>> &_adj, bool _vertex_mode) {
        init(_adj.size(), _vertex_mode);
        adj = _adj;
    }

    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void dfs(int node, int par) {
        static int tour;

        if (par < 0)
            tour = 0;

        parent[node] = par;
        tour_start[node] = tour++;

        for (int neighbor : adj[node])
            if (neighbor != par)
                dfs(neighbor, node);

        tour_end[node] = tour;
    }

    void build() {
        if (n == 0) return;
        dfs(0, -1);
    }

    void update_node(int node, T change) {
        values[node] += change;
        tree.update(tour_start[node], change);
    }

    void update_edge(int a, int b, T change) {
        // Edge values are stored at the deeper node.
        if (parent[a] == b)
            swap(a, b);

        assert(a == parent[b]);
        update_node(b, change);
    }

    // Returns the sum of tree values for all nodes / edges in the subtree of `node`, inclusive when in `vertex_mode`.
    T query_subtree(int node) const {
        return tree.query(tour_end[node]) - tree.query(tour_start[node]) - (vertex_mode ? 0 : values[node]);
    }
};

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

    vector<node> nodes;
    vector<string> words;
    vector<int> word_location;
    vector<int> word_indices_by_depth;
    vector<int> defer;

    aho_corasick(const vector<string> &_words = {}) {
        if (!_words.empty())
            build(_words);
    }

    // Builds the adj list based on suffix parents. Often we want to perform DP and/or queries on this tree.
    vector<vector<int>> build_suffix_adj() const {
        vector<vector<int>> adj(nodes.size());

        for (int i = 1; i < (int) nodes.size(); i++)
            adj[nodes[i].suff].push_back(i);

        return adj;
    }

    int get_or_add_child(int current, char c) {
        if (nodes[current][c] >= 0)
            return nodes[current][c];

        int index = nodes.size();
        nodes[current][c] = index;
        nodes.emplace_back();
        nodes.back().depth = nodes[current].depth + 1;
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

    void build(const vector<string> &_words) {
        nodes.assign(1, node());
        words = _words;
        stable_sort(words.begin(), words.end());
        word_location.resize(words.size());
        defer.resize(words.size());
        int max_depth = 0;

        for (int i = 0; i < (int) words.size(); i++) {
            word_location[i] = add_word(words[i], i);
            max_depth = max(max_depth, nodes[word_location[i]].depth);
            defer[i] = i;

            if (i > 0 && words[i] == words[i - 1])
                defer[i] = defer[i - 1];
        }

        // Create a list of word indices in decreasing order of depth, in linear time.
        vector<vector<int>> indices_by_depth(max_depth + 1, vector<int>());
        word_indices_by_depth.clear();

        for (int i = 0; i < (int) words.size(); i++)
            indices_by_depth[nodes[word_location[i]].depth].push_back(i);

        for (int depth = max_depth; depth >= 0; depth--)
            for (int index : indices_by_depth[depth])
                word_indices_by_depth.push_back(index);

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
        vector<int> matches(words.size(), 0);
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

        for (int i = 0; i < (int) words.size(); i++)
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


const int NM_MAX = 4e5 + 5;

struct trie_node {
    map<char, trie_node*> children;
    vector<int> queries;
};

int N, M;
trie_node *root = nullptr;
vector<trie_node*> S;

vector<string> words;
vector<int> answers;

aho_corasick AC;
subtree_sum_DS<int> tree;

trie_node* add_child(trie_node *node, char c) {
    if (node->children.find(c) == node->children.end())
        node->children[c] = new trie_node();

    return node->children[c];
}

void dfs(trie_node *node, int location) {
    for (int q : node->queries) {
        int ac_index = lower_bound(AC.words.begin(), AC.words.end(), words[q]) - AC.words.begin();
        int word_loc = AC.word_location[ac_index];
        answers[q] = tree.query_subtree(word_loc);
    }

    for (pair<char, trie_node*> p : node->children) {
        int next_location = AC.get_suffix_link(location, p.first);
        tree.update_node(next_location, +1);
        dfs(p.second, next_location);
        tree.update_node(next_location, -1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    root = new trie_node();
    S.assign(N, nullptr);

    for (int i = 0; i < N; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            char c;
            cin >> c;
            S[i] = add_child(root, c);
        } else {
            int j;
            char c;
            cin >> j >> c;
            j--;
            S[i] = add_child(S[j], c);
        }
    }

    cin >> M;
    words.resize(M);
    answers.resize(M);

    for (int i = 0; i < M; i++) {
        int index;
        cin >> index >> words[i];
        index--;
        S[index]->queries.push_back(i);
    }

    AC.build(words);
    tree.init(AC.build_suffix_adj(), true);
    tree.build();
    dfs(root, 0);

    for (int answer : answers)
        cout << answer << '\n';
}