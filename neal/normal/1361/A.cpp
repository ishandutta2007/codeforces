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

template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> T(N);

    for (auto &t : T) {
        cin >> t;
        t--;
    }

    vector<int> T_order(N);

    for (int i = 0; i < N; i++)
        T_order[i] = i;

    sort(T_order.begin(), T_order.end(), [&](int a, int b) {
        return T[a] < T[b];
    });

    vector<bool> published(N, false);
    vector<int> seen(N + 1, -1);
    int seen_index = 0;
    bool valid = true;

    for (int x : T_order) {
        for (int neigh : adj[x])
            if (published[neigh])
                seen[T[neigh]] = seen_index;

        int minimum = 0;

        while (seen[minimum] == seen_index)
            minimum++;

        if (minimum != T[x])
            valid = false;

        published[x] = true;
        seen_index++;
    }

    if (!valid) {
        cout << -1 << '\n';
        return 0;
    }

    output_vector(T_order, true);
}