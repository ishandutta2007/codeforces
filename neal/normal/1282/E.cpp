#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N;
vector<array<int, 3>> triangle;
vector<bool> alive;
vector<int> vert_freq;
vector<vector<int>> triangles_for_vert;
map<pair<int, int>, int> edge_freq;

pair<int, int> ordered_pair(int a, int b) {
    if (a > b) swap(a, b);
    return {a, b};
}

void run_case() {
    cin >> N;
    triangle.resize(N - 2);
    alive.assign(N - 2, true);
    vert_freq.assign(N + 1, 0);
    triangles_for_vert.assign(N + 1, {});
    edge_freq.clear();

    for (int i = 0; i < N - 2; i++) {
        for (int t = 0; t < 3; t++) {
            cin >> triangle[i][t];
            vert_freq[triangle[i][t]]++;
            triangles_for_vert[triangle[i][t]].push_back(i);
        }

        for (int a = 0; a < 3; a++)
            for (int b = a + 1; b < 3; b++)
                edge_freq[ordered_pair(triangle[i][a], triangle[i][b])]++;
    }

    vector<vector<int>> neighbors(N + 1);

    for (auto it : edge_freq)
        if (it.second == 1) {
            int a = it.first.first, b = it.first.second;
            neighbors[a].push_back(b);
            neighbors[b].push_back(a);
            // cerr << "neighbors: " << a << ' ' << b << endl;
        }

    vector<int> cycle;
    int current = 1, previous = 0;

    do {
        cycle.push_back(current);
        // cerr << current << ' ' << previous << endl;

        for (int neighbor : neighbors[current])
            if (neighbor != previous) {
                previous = current;
                current = neighbor;
                break;
            }
    } while (current != 1);

    // for (int x : cycle)
    //     cerr << x << ' ';

    // cerr << endl;

    vector<int> ones;

    for (int i = 1; i <= N; i++)
        if (vert_freq[i] == 1)
            ones.push_back(i);

    vector<int> Q;

    for (int i = 0; i < N - 2; i++) {
        assert(!ones.empty());
        current = ones.back(); ones.pop_back();
        // cerr << "current: " << current << endl;
        int tri_index = -1;

        for (int tri : triangles_for_vert[current])
            if (alive[tri]) {
                tri_index = tri;
                break;
            }

        assert(tri_index >= 0);
        Q.push_back(tri_index + 1);
        alive[tri_index] = false;

        for (int t = 0; t < 3; t++)
            if (--vert_freq[triangle[tri_index][t]] == 1)
                ones.push_back(triangle[tri_index][t]);
    }

    for (int i = 0; i < N; i++)
        cout << cycle[i] << (i < N - 1 ? ' ' : '\n');

    for (int i = 0; i < N - 2; i++)
        cout << Q[i] << (i < N - 3 ? ' ' : '\n');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        run_case();
}