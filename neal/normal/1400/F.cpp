#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

// This version of aho_corasick uses more memory and depends on a small alphabet, but it provides O(1) suffix links.
template<char MIN_CHAR = 'a', int ALPHABET = 26>
struct aho_corasick {
    struct node {
        // suff = the index of the node of the longest strict suffix of the current node that's also in the tree.
        //   Also see "blue arcs" on Wikipedia: https://en.wikipedia.org/wiki/Aho%E2%80%93Corasick_algorithm
        // dict = the index of the node of the longest strict suffix of the current node that's in the word list.
        //   Also see "green arcs" on Wikipedia.
        // depth = normal trie depth (root is 0). Can be removed to save memory.
        // word_index = the index of the *first* word ending at this node. -1 if none.
        // word_count = the total number of words ending at this node. Used in count_total_matches().
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
    int W;
    vector<int> word_location;
    vector<int> word_indices_by_depth;
    vector<int> defer;

    aho_corasick(const vector<string> &words = {}) {
        if (!words.empty())
            build(words);
    }

    // Builds the adj list based on suffix parents. Often we want to perform DP and/or queries on this tree.
    vector<vector<int>> build_suffix_adj() const {
        vector<vector<int>> adj(nodes.size());

        for (int i = 1; i < int(nodes.size()); i++)
            adj[nodes[i].suff].push_back(i);

        return adj;
    }

    int get_or_add_child(int current, char c) {
        if (nodes[current][c] >= 0)
            return nodes[current][c];

        int index = int(nodes.size());
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

    // Returns where in the trie we should end up after starting at `location` and adding char `c`. Runs in O(1).
    int get_suffix_link(int location, char c) const {
        if (location >= 0)
            location = nodes[location].link[c - MIN_CHAR];

        return max(location, 0);
    }

    void build(const vector<string> &words) {
        nodes = {node()};
        W = int(words.size());
        word_location.resize(W);
        defer.resize(W);
        int max_depth = 0;

        for (int i = 0; i < W; i++) {
            word_location[i] = add_word(words[i], i);
            max_depth = max(max_depth, int(words[i].size()));
            defer[i] = nodes[word_location[i]].word_index;
        }

        // Create a list of word indices in decreasing order of depth, in linear time via counting sort.
        word_indices_by_depth.resize(W);
        vector<int> depth_freq(max_depth + 1, 0);

        for (int i = 0; i < W; i++)
            depth_freq[words[i].size()]++;

        for (int i = max_depth - 1; i >= 0; i--)
            depth_freq[i] += depth_freq[i + 1];

        for (int i = 0; i < W; i++)
            word_indices_by_depth[--depth_freq[words[i].size()]] = i;

        // Solve suffix parents by traversing in order of depth (BFS order).
        vector<int> q = {0};

        for (int i = 0; i < int(q.size()); i++) {
            int current = q[i];

            for (char c = MIN_CHAR; c < MIN_CHAR + ALPHABET; c++) {
                int &index = nodes[current][c];

                if (index >= 0) {
                    // Find index's suffix parent by traversing suffix parents of current until one of them has a child c.
                    int suffix_parent = get_suffix_link(nodes[current].suff, c);
                    nodes[index].suff = suffix_parent;
                    nodes[index].word_count += nodes[suffix_parent].word_count;
                    nodes[index].dict = nodes[suffix_parent].word_index < 0 ? nodes[suffix_parent].dict : suffix_parent;
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
            int dict_node = nodes[current].word_index < 0 ? nodes[current].dict : current;

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

    // Counts the number of matches over all words at each ending position in `text` in O(text length).
    vector<int> count_matches_by_position(const string &text) const {
        vector<int> matches(text.size());
        int current = 0;

        for (int i = 0; i < int(text.size()); i++) {
            current = get_suffix_link(current, text[i]);
            matches[i] = nodes[current].word_count;
        }

        return matches;
    }

    // Counts the total number of matches of all words within `text` in O(text length).
    int64_t count_total_matches(const string &text) const {
        int64_t matches = 0;
        int current = 0;

        for (char c : text) {
            current = get_suffix_link(current, c);
            matches += nodes[current].word_count;
        }

        return matches;
    }
};


const int INF = 1e9 + 5;

int N, X;
string S;
vector<string> prime;
aho_corasick<'1', 9> AC;

bool check(string str) {
    int n = int(str.size());

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += str[j] - '0';

            if (sum < X && X % sum == 0)
                return false;
        }
    }

    return true;
}

void generate(string str, int sum) {
    if (sum > X)
        return;

    if (sum == X) {
        if (check(str))
            prime.push_back(str);

        return;
    }

    for (int d = 1; d <= 9 && sum + d <= X; d++)
        generate(str + char(d + '0'), sum + d);
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> S >> X;
    N = int(S.size());
    generate("", 0);
    dbg(prime);
    AC.build(prime);
    int ST = int(AC.nodes.size());
    vector<int> dp(ST, INF);
    dp[0] = 0;

    for (auto &ch : S) {
        vector<int> next_dp(ST, INF);

        for (int state = 0; state < ST; state++)
            if (dp[state] < INF) {
                next_dp[state] = min(next_dp[state], dp[state] + 1);
                int transition = AC.get_suffix_link(state, ch);

                if (AC.nodes[transition].word_index < 0)
                    next_dp[transition] = min(next_dp[transition], dp[state]);
            }

        swap(dp, next_dp);
    }

    cout << *min_element(dp.begin(), dp.end()) << '\n';
}