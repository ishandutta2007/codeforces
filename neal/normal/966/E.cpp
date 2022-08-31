// Solution to https://codeforces.com/contest/966/problem/E
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

int N, M;
int B_SIZE, N_BUCKETS;
vector<int> parent;
vector<vector<int>> children;
vector<int> subtree_size;
vector<int> heavy_top;
vector<int> tour_start;
int tour;

vector<int> threshold;
vector<bool> vacation;
vector<int> sorted;

vector<int> change;

int which_bucket(int index) {
    return index / B_SIZE;
}

int get_bucket_start(int b) {
    return B_SIZE * b;
}

int get_bucket_end(int b) {
    return min(B_SIZE * (b + 1), N);
}

void dfs(int node) {
    subtree_size[node] = 1;

    for (int child : children[node]) {
        dfs(child);
        subtree_size[node] += subtree_size[child];
    }
}

void heavy_dfs(int node, int h_top) {
    heavy_top[node] = h_top;

    // Reorder children so that the largest subtree is first. This helps keep Euler tour indices consecutive in paths.
    for (int &child : children[node])
        if (subtree_size[child] > subtree_size[children[node].front()])
            swap(child, children[node].front());

    tour_start[node] = tour++;
    bool heavy = true;

    for (int child : children[node]) {
        heavy_dfs(child, heavy ? h_top : child);
        heavy = false;
    }
}

void build(int b) {
    int bucket_start = get_bucket_start(b), bucket_end = get_bucket_end(b);

    for (int i = bucket_start; i < bucket_end; i++) {
        threshold[i] += change[b];
        sorted[i] = vacation[i] ? INF : threshold[i];
    }

    change[b] = 0;
    sort(sorted.begin() + bucket_start, sorted.begin() + bucket_end);
}

// Updates the nodes whose tour values are in the range [start, end).
void bucket_update(int start, int end, int add) {
    int start_b = which_bucket(start), end_b = which_bucket(end - 1);

    if (start_b == end_b) {
        for (int i = start; i < end; i++)
            threshold[i] += add;

        build(start_b);
        return;
    }

    int bucket_end = get_bucket_end(start_b);

    for (int i = start; i < bucket_end; i++)
        threshold[i] += add;

    build(start_b);

    int bucket_start = get_bucket_start(end_b);

    for (int i = bucket_start; i < end; i++)
        threshold[i] += add;

    build(end_b);

    for (int b = start_b + 1; b < end_b; b++)
        change[b] += add;
}

void update(int node, int add) {
    // We only need to update O(log n) contiguous ranges of Euler tour indices. Each range update is ~sqrt(N) time.
    while (node >= 0) {
        bucket_update(tour_start[heavy_top[node]], tour_start[node] + 1, add);
        node = parent[heavy_top[node]];
    }
}

int query() {
    int total = 0;

    for (int b = 0; b < N_BUCKETS; b++) {
        int bucket_start = get_bucket_start(b), bucket_end = get_bucket_end(b);
        total += lower_bound(sorted.begin() + bucket_start, sorted.begin() + bucket_end, -change[b]) - (sorted.begin() + bucket_start);
    }

    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    B_SIZE = 1.8 * sqrt(N / log(N + 1)) + 1;
    N_BUCKETS = (N + B_SIZE - 1) / B_SIZE;
    cerr << "Bucket size: " << B_SIZE << endl;
    cerr << "Number of buckets: " << N_BUCKETS << endl;

    parent.assign(N, -1);
    children.assign(N, {});

    for (int i = 1; i < N; i++) {
        cin >> parent[i];
        parent[i]--;
        children[parent[i]].push_back(i);
    }

    subtree_size.resize(N);
    heavy_top.assign(N, -1);
    tour_start.assign(N, -1);
    tour = 0;
    dfs(0);
    heavy_dfs(0, 0);

    threshold.resize(N);

    for (int i = 0; i < N; i++)
        cin >> threshold[tour_start[i]];

    vacation.assign(N, false);
    sorted.assign(N, INF);
    change.assign(N_BUCKETS, 0);

    for (int b = 0; b < N_BUCKETS; b++)
        build(b);

    for (int i = 0; i < M; i++) {
        int q;
        cin >> q;

        if (q > 0) {
            q--;
            vacation[tour_start[q]] = true;
            update(q, -1);
        } else {
            q = -q;
            q--;
            vacation[tour_start[q]] = false;
            update(q, +1);
        }

        cout << query() << (i < M - 1 ? ' ' : '\n');
    }
}