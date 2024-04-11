#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const int LOG = 20;

struct trie_node {
    int link[10];
    int ancestor[LOG];
    int what;
    int depth = 0;

    trie_node() {
        memset(link, -1, sizeof(link));
        memset(ancestor, -1, sizeof(ancestor));
    }
};

vector<trie_node> trie(1);

void create_node(int parent, int c) {
    trie.emplace_back();
    trie.back().what = c;
    trie.back().depth = trie[parent].depth + 1;
    trie.back().ancestor[0] = parent;

    for (int k = 0; k + 1 < LOG; k++) {
        int first = trie.back().ancestor[k];
        trie.back().ancestor[k + 1] = first < 0 ? -1 : trie[first].ancestor[k];
    }
}

int get_or_create_node(int current, int c) {
    if (trie[current].link[c] < 0) {
        trie[current].link[c] = trie.size();
        create_node(current, c);
    }

    return trie[current].link[c];
}

int insert_str(int current, const string &str) {
    for (char c : str)
        current = get_or_create_node(current, c - '0');

    return current;
}

bool compare_str(int a, int b) {
    if (a == b)
        return false;

    if (a < 0 || b < 0)
        return a >= 0;

    if (trie[a].depth != trie[b].depth)
        return trie[a].depth < trie[b].depth;

    for (int k = LOG - 1; k >= 0; k--)
        if (trie[a].ancestor[k] != trie[b].ancestor[k]) {
            a = trie[a].ancestor[k];
            b = trie[b].ancestor[k];
            assert(trie[a].depth == trie[b].depth);
        }

    assert(a != b);
    assert(trie[a].ancestor[0] == trie[b].ancestor[0]);
    return trie[a].what < trie[b].what;
}


const int MOD = 1e9 + 7;

vector<int> save;

int compute_mod(int current) {
    if (current == 0)
        return 0;

    if (save[current] >= 0)
        return save[current];

    return save[current] = (10LL * compute_mod(trie[current].ancestor[0]) + trie[current].what) % MOD;
}


struct edge {
    int node;
    int index;
    string index_str;

    edge() {}

    edge(int _node, int _index) : node(_node), index(_index) {
        index_str = to_string(index);
    }
};

struct dijkstra_state {
    int trie_node;
    int node;

    dijkstra_state() {}

    dijkstra_state(int _trie_node, int _node) : trie_node(_trie_node), node(_node) {}

    bool operator<(const dijkstra_state &other) const {
        return compare_str(other.trie_node, trie_node);
        // return dist > other.dist;
    }
};

int N, M;
vector<vector<edge>> adj;
vector<int> dist;

void dijkstra_check(priority_queue<dijkstra_state> &pq, int node, int current_dist) {
    if (compare_str(current_dist, dist[node])) {
        dist[node] = current_dist;
        pq.emplace(current_dist, node);
    }
}

void dijkstra(const vector<int> &source) {
    dist.assign(N, -1);
    priority_queue<dijkstra_state> pq;

    for (int src : source)
        dijkstra_check(pq, src, 0);

    while (!pq.empty()) {
        dijkstra_state top = pq.top();
        pq.pop();

        if (compare_str(dist[top.node], top.trie_node))
            continue;

        for (edge &e : adj[top.node]) {
            int next_trie_node = insert_str(top.trie_node, e.index_str);
            dijkstra_check(pq, e.node, next_trie_node);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    adj.assign(N, {});

    for (int i = 1; i <= M; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].emplace_back(y, i);
        adj[y].emplace_back(x, i);
    }

    dijkstra({0});
    save.assign(trie.size(), -1);

    for (int i = 1; i < N; i++)
        cout << compute_mod(dist[i]) << '\n';
}