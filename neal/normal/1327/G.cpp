#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


// This version of aho_corasick uses more memory and depends on a small alphabet, but it provides O(1) suffix links.
template<char MIN_CHAR = 'a', int ALPHABET = 14>
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
        int cost = 0;

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

    // aho_corasick(const vector<string> &words = {}) {
    //     if (!words.empty())
    //         build(words);
    // }

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

    // Returns where in the trie we should end up after starting at `location` and adding char `c`. Runs in O(1).
    int get_suffix_link(int location, char c) const {
        if (location >= 0)
            location = nodes[location].link[c - MIN_CHAR];

        return max(location, 0);
    }

    void build(vector<string> words, const map<string, int> &C) {
        nodes = {node()};
        stable_sort(words.begin(), words.end());
        words.erase(unique(words.begin(), words.end()), words.end());
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

        for (int i = 0; i < (int) q.size(); i++) {
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

        vector<int> nodes_by_depth(nodes.size());

        for (int i = 0; i < (int) nodes.size(); i++)
            nodes_by_depth[i] = i;

        sort(nodes_by_depth.begin(), nodes_by_depth.end(), [&](int a, int b) {
            return nodes[a].depth < nodes[b].depth;
        });

        for (int i : nodes_by_depth) {
            if (nodes[i].word_index >= 0)
                nodes[i].cost += C.at(words[nodes[i].word_index]);

            if (nodes[i].dict >= 0)
                nodes[i].cost += nodes[nodes[i].dict].cost;
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

        for (int i = 0; i < (int) text.size(); i++) {
            current = get_suffix_link(current, text[i]);
            matches[i] = nodes[current].word_count;
        }

        return matches;
    }

    // Counts the total number of matches of all words within `text` in O(text length).
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


const long long LL_INF = (long long) 2e18 + 5;
const int N = 14;
const int T_MAX = 1005;

int K;
vector<string> T;
int A;
aho_corasick AC;
vector<int> C;

int L;
string S;
int Q;
vector<int> questions;
vector<int> question_index;

// transition[index][node] = pair of the node we reach right before the next important point (questions, -1, and L)
// and the cost involved in getting there, when starting from node at index.
pair<int, long long> transition[N + 2][T_MAX];
pair<int, long long> fast_forward[N + 2];

void compute_transition(int index, int node) {
    int original_node = node;
    int start = questions[index];
    int next = questions[index + 1];
    long long cost = 0;

    for (int i = start + 1; i < next; i++) {
        node = AC.get_suffix_link(node, S[i]);
        cost += AC.nodes[node].cost;

        if (i == start + T_MAX) {
            if (fast_forward[index].first >= 0) {
                node = fast_forward[index].first;
                cost += fast_forward[index].second;
                transition[index][original_node] = {node, cost};
                return;
            }

            fast_forward[index].second = -cost;
        }
    }

    fast_forward[index].first = node;
    fast_forward[index].second += cost;
    transition[index][original_node] = {node, cost};
}

pair<int, long long> get_transition(int index, int node, int letter) {
    if (transition[index][node].first < 0)
        compute_transition(index, node);

    pair<int, long long> trans = transition[index][node];

    if (letter >= 0) {
        trans.first = AC.get_suffix_link(trans.first, 'a' + letter);
        trans.second += AC.nodes[trans.first].cost;
    }

    return trans;
}

long long dp[1 << N][T_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K;
    T.resize(K);
    C.resize(K);
    map<string, int> C_map;

    for (int k = 0; k < K; k++) {
        cin >> T[k] >> C[k];
        C_map[T[k]] += C[k];
    }

    AC.build(T, C_map);
    A = AC.nodes.size();
    cin >> S;
    L = S.size();
    question_index.assign(L, -1);
    questions = {-1};

    for (int i = 0; i < L; i++)
        if (S[i] == '?') {
            question_index[i] = Q++;
            questions.push_back(i);
        }

    questions.push_back(L);
    memset(transition, -63, sizeof(transition));
    memset(fast_forward, -63, sizeof(fast_forward));
    memset(dp, -63, sizeof(dp));
    dp[0][0] = 0;

    for (int mask = 0; mask < 1 << N; mask++)
        for (int node = 0; node < A; node++)
            if (__builtin_popcount(mask) < Q && dp[mask][node] > -LL_INF) {
                int bit_count = __builtin_popcount(mask);

                for (int next = 0; next < N; next++)
                    if ((mask >> next & 1) == 0) {
                        pair<int, long long> trans = get_transition(bit_count, node, next);
                        int next_mask = mask | 1 << next;
                        dp[next_mask][trans.first] = max(dp[next_mask][trans.first], dp[mask][node] + trans.second);
                    }
            }

    long long answer = -LL_INF;

    for (int mask = 0; mask < 1 << N; mask++)
        if (__builtin_popcount(mask) == Q)
            for (int node = 0; node < A; node++)
                answer = max(answer, dp[mask][node] + get_transition(Q, node, -1).second);

    cout << answer << '\n';
}