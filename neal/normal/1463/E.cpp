#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
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

    int N, K;
    cin >> N >> K;
    vector<int> parent(N);
    vector<vector<int>> children(N);

    for (int i = 0; i < N; i++) {
        cin >> parent[i];
        parent[i]--;

        if (parent[i] >= 0)
            children[parent[i]].push_back(i);
    }

    vector<int> comes_from(N, -1), goes_to(N, -1);

    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        assert(goes_to[x] < 0 && comes_from[y] < 0);
        goes_to[x] = y;
        comes_from[y] = x;
    }

    vector<int> which_path(N, -1);
    vector<vector<int>> paths;

    for (int start = 0; start < N; start++)
        if (comes_from[start] < 0) {
            vector<int> path;

            for (int x = start; x >= 0; x = goes_to[x]) {
                path.push_back(x);
                which_path[x] = int(paths.size());
            }

            paths.push_back(path);
        }

    for (int i = 0; i < N; i++)
        if (which_path[i] < 0) {
            cout << 0 << '\n';
            return 0;
        }

    int P = int(paths.size());
    vector<int> dependencies(P, 0);

    for (int i = 0; i < N; i++)
        if (parent[i] >= 0 && which_path[i] != which_path[parent[i]])
            dependencies[which_path[parent[i]]]++;

    queue<int> q;

    for (int p = 0; p < P; p++)
        if (dependencies[p] == 0)
            q.push(p);

    vector<int> solution;

    while (!q.empty()) {
        int p = q.front(); q.pop();
        vector<int> &path = paths[p];
        solution.insert(solution.end(), path.rbegin(), path.rend());

        for (int x : path)
            if (parent[x] >= 0 && --dependencies[which_path[parent[x]]] == 0)
                q.push(which_path[parent[x]]);
    }

    reverse(solution.begin(), solution.end());

    if (int(solution.size()) != N) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> location(N, -1);

    for (int i = 0; i < N; i++)
        location[solution[i]] = i;

    for (int i = 0; i < N; i++)
        if (parent[i] >= 0 && location[parent[i]] > location[i]) {
            cout << 0 << '\n';
            return 0;
        }

    output_vector(solution, true);
}