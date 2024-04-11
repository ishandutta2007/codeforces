#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
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

auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));

template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


const int ATTEMPTS = 50;

int N, M;
vector<vector<int>> adj;
vector<int> tour_index;
vector<array<int, 2>> low_link;
vector<bool> in_stack;
int tour;
vector<int> tour_list;

array<int, 2> combine(array<int, 2> x, int y) {
    array<int, 3> a = {x[0], x[1], y};
    sort(a.begin(), a.end());
    return {a[0], a[1]};
}

array<int, 2> combine(array<int, 2> x, array<int, 2> y) {
    array<int, 4> a = {x[0], x[1], y[0], y[1]};
    sort(a.begin(), a.end());
    return {a[0], a[1]};
}

bool interesting_dfs(int node) {
    tour_index[node] = tour++;
    tour_list.push_back(node);
    low_link[node] = {tour_index[node], tour_index[node]};
    in_stack[node] = true;

    for (int neighbor : adj[node])
        if (tour_index[neighbor] < 0) {
            // neighbor is part of our subtree.
            if (!interesting_dfs(neighbor))
                return false;

            low_link[node] = combine(low_link[node], low_link[neighbor]);
        } else if (in_stack[neighbor]) {
            // neighbor is a candidate for low_link.
            low_link[node] = combine(low_link[node], tour_index[neighbor]);
        } else {
            // neighbor is either a down-edge or a cross-edge; immediately fail.
            return false;
        }

    in_stack[node] = false;
    return true;
}

vector<int> save_interesting;

bool check_interesting(int node) {
    if (save_interesting[node] >= 0)
        return save_interesting[node];

    tour_index.assign(N, -1);
    low_link.resize(N);
    in_stack.assign(N, false);
    tour = 0;
    tour_list.clear();
    return (save_interesting[node] = interesting_dfs(node));
}

void run_case() {
    cin >> N >> M;
    adj.assign(N, {});

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }

    save_interesting.assign(N, -1);
    int root = -1;

    for (int iter = 0; iter < ATTEMPTS; iter++) {
        root = int(rng() % N);

        if (check_interesting(root))
            break;

        root = -1;
    }

    if (root < 0) {
        cout << -1 << '\n';
        return;
    }

    vector<bool> bad(N, false);

    for (int x : tour_list)
        if (low_link[x][0] < tour_index[x] && low_link[x][1] < tour_index[x]) {
            bad[x] = true;
        } else {
            assert(low_link[x][1] == tour_index[x]);
            int above = tour_list[low_link[x][0]];
            bad[x] = bad[above];
        }

    vector<int> interesting;

    for (int i = 0; i < N; i++)
        if (!bad[i])
            interesting.push_back(i);

    if (5 * int(interesting.size()) < N)
        cout << -1 << '\n';
    else
        output_vector(interesting, true);
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}