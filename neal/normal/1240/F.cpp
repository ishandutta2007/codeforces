#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));

const int INF = 1e9 + 5;

struct edge {
    int a, b, color, index;
};

int N, M, K;
vector<edge> edges;
vector<vector<int>> color_count;

void set_color(edge &e, int color) {
    color_count[e.a][e.color]--;
    color_count[e.b][e.color]--;
    e.color = color;
    color_count[e.a][e.color]++;
    color_count[e.b][e.color]++;
}

bool fix() {
    vector<int> minimum(N, INF), maximum(N, 0);

    for (int i = 0; i < N; i++)
        for (int k = 0; k < K; k++) {
            minimum[i] = min(minimum[i], color_count[i][k]);
            maximum[i] = max(maximum[i], color_count[i][k]);
        }

    bool change = false;

    for (edge &e : edges)
        if ((maximum[e.a] - minimum[e.a] > 2 && color_count[e.a][e.color] == maximum[e.a]) ||
            (maximum[e.b] - minimum[e.b] > 2 && color_count[e.b][e.color] == maximum[e.b])) {
            set_color(e, rng() % K);
            change = true;
        }

    return change;
}

int main() {
    cin >> N >> M >> K;
    color_count.assign(N, vector<int>(K, 0));

    for (int i = 0; i < N; i++) {
        int _;
        cin >> _;
    }

    edges.resize(M);

    for (int i = 0; i < M; i++) {
        edge &e = edges[i];
        cin >> e.a >> e.b;
        e.a--; e.b--;
        e.index = i;
        e.color = rng() % K;
        color_count[e.a][e.color]++;
        color_count[e.b][e.color]++;
    }

    bool bad;

    do {
        shuffle(edges.begin(), edges.end(), rng);
        bad = false;

        while (fix())
            bad = true;
    } while (bad);

    vector<int> answers(M);

    for (edge &e : edges)
        answers[e.index] = e.color + 1;

    for (int i = 0; i < M; i++)
        cout << answers[i] << '\n';
}