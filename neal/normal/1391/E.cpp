#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <set>
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

template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));


int N, M;
vector<vector<int>> adj;
vector<vector<int>> sorted_adj;
vector<int> path;
vector<array<int, 2>> pairings;
vector<int> which_pair;
vector<int> path_index;

bool edge_exists(int a, int b) {
    return binary_search(sorted_adj[a].begin(), sorted_adj[a].end(), b);
}

bool valid(array<int, 2> p0, array<int, 2> p1) {
    assert(!edge_exists(p0[0], p0[1]));
    assert(!edge_exists(p1[0], p1[1]));
    int count = 0;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            count += edge_exists(p0[i], p1[j]);

    return count <= 2;
}

void run_case() {
    cin >> N >> M;
    adj.assign(N, {});

    vector<int> perm(N), rev_perm(N);

    for (int i = 0; i < N; i++)
        perm[i] = i;

    shuffle(perm.begin(), perm.end(), rng);

    for (int i = 0; i < N; i++)
        rev_perm[perm[i]] = i;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        a = perm[a]; b = perm[b];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < N; i++)
        sort(adj[i].begin(), adj[i].end());

    sorted_adj = adj;
    path.clear();
    pairings.clear();
    which_pair.assign(N, -1);
    path_index.assign(N, -1);
    set<int> nodes;

    for (int i = 0; i < N; i++)
        nodes.insert(i);

    int pairs = 0;

    auto &&add_to_path = [&](int node) {
        path.push_back(node);
        nodes.erase(node);
        path_index[node] = int(path.size()) - 1;
    };

    while (int(path.size()) < (N + 1) / 2 && 2 * pairs < (N + 1) / 2) {
        dbg(path, pairs, pairings);
        assert(!nodes.empty());

        if (path.empty()) {
            add_to_path(*nodes.begin());
            continue;
        }

        int node = path.back();
        int neigh = -1;

        int n = int(adj[node].size());

        for (int i = n - 1; i >= 0; i--) {
            swap(adj[node][i], adj[node][rng() % (i + 1)]);
            int x = adj[node][i];

            if (path_index[x] < 0 && which_pair[x] < 0) {
                neigh = x;
                break;
            }
        }

        if (neigh >= 0) {
            add_to_path(neigh);
            continue;
        }

        int other = *nodes.begin();
        array<int, 2> pairing = {node, other};
        nodes.erase(other);
        bool found = false;

        for (int x : adj[node])
            if (which_pair[x] >= 0 && !valid(pairing, pairings[which_pair[x]])) {
                array<int, 2> &other_pair = pairings[which_pair[x]];
                int which = -1;

                for (int mid : other_pair)
                    if (edge_exists(node, mid) && edge_exists(mid, other))
                        which = mid;

                assert(which >= 0);
                which_pair[other_pair[0]] = -1;
                which_pair[other_pair[1]] = -1;
                pairs--;

                add_to_path(which);
                add_to_path(other);
                nodes.insert(other_pair[0] ^ other_pair[1] ^ which);
                other_pair[0] = other_pair[1] = -1;
                found = true;
                break;
            }

        if (!found) {
            path.pop_back();
            path_index[node] = -1;
            pairings.push_back(pairing);
            which_pair[pairing[0]] = which_pair[pairing[1]] = int(pairings.size()) - 1;
            pairs++;
        }
    }

    dbg(path, pairs, pairings);

    if (int(path.size()) >= (N + 1) / 2) {
        cout << "PATH" << '\n';

        for (auto &x : path)
            x = rev_perm[x];

        cout << path.size() << '\n';
        output_vector(path, true);
        return;
    }

    assert(2 * pairs >= (N + 1) / 2);
    cout << "PAIRING" << '\n';
    cout << pairs << '\n';

    for (int i = 0; i < int(pairings.size()); i++)
        if (pairings[i][0] >= 0)
            cout << rev_perm[pairings[i][0]] + 1 << ' ' << rev_perm[pairings[i][1]] + 1 << '\n';
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