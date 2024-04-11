#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int NM_MAX = 100005;
const int K_MAX = 105;
const int INF = 1000000005;

int N, M, K, S;
int goods_type[NM_MAX];
int dist[K_MAX][NM_MAX];
vector<int> adj[NM_MAX];

int q[NM_MAX];
int front, back;

void solve_distances(int k) {
    for (int i = 0; i < N; i++) {
        dist[k][i] = INF;
    }

    front = back = 0;

    for (int i = 0; i < N; i++) {
        if (goods_type[i] == k) {
            dist[k][i] = 0;
            q[back++] = i;
        }
    }

    while (front < back) {
        int top = q[front++];

        for (int neighbor : adj[top]) {
            if (dist[k][top] + 1 < dist[k][neighbor]) {
                dist[k][neighbor] = dist[k][top] + 1;
                q[back++] = neighbor;
            }
        }
    }
}

int best_fair(int node) {
    vector<int> distances;

    for (int k = 0; k < K; k++) {
        distances.push_back(dist[k][node]);
    }

    nth_element(distances.begin(), distances.begin() + S, distances.end());
    int sum = 0;

    for (int i = 0; i < S; i++) {
        sum += distances[i];
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K >> S;

    for (int i = 0; i < N; i++) {
        cin >> goods_type[i];
        goods_type[i]--;
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int k = 0; k < K; k++) {
        solve_distances(k);
    }

    for (int i = 0; i < N; i++) {
        cout << best_fair(i) << (i < N - 1 ? ' ' : '\n');
    }

    return 0;
}