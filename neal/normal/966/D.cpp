#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int NM_MAX = 300005, INF = 1000000005;

int N, M;
int dist[NM_MAX], prev[NM_MAX];
vector<int> adj[NM_MAX];

int q[NM_MAX];
int front, back;

bool is_edge(int a, int b) {
    int position = lower_bound(adj[a].begin(), adj[a].end(), b) - adj[a].begin();
    return position < (int) adj[a].size() && adj[a][position] == b;
}

void q_check(int node, int potential_dist, int parent) {
    if (potential_dist < dist[node]) {
        dist[node] = potential_dist;
        prev[node] = parent;
        q[back++] = node;
    }
}

void bfs(int start) {
    memset(dist, 63, sizeof(dist));
    memset(prev, -1, sizeof(prev));
    front = back = 0;
    q_check(start, 0, -1);

    while (front < back) {
        int current = q[front++];

        for (int i = 0; i < (int) adj[current].size(); i++) {
            int neighbor = adj[current][i];
            q_check(neighbor, dist[current] + 1, current);
        }
    }
}

void output(int answer, vector<int> order) {
    if (answer >= 100) {
        printf("-1\n");
        return;
    }

    assert((int) order.size() == answer + 1);
    printf("%d\n", answer);

    for (int i = 0; i <= answer; i++) {
        printf("%d%c", order[i], i < answer ? ' ' : '\n');
    }
}

int main() {
    assert(scanf("%d %d", &N, &M) == 2);

    for (int i = 0; i < M; i++) {
        int u, v;
        assert(scanf("%d %d", &u, &v) == 2);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    bfs(1);
    int answer = dist[N];
    vector<int> order;

    for (int node = N; node != -1; node = prev[node])
        order.push_back(node);

    reverse(order.begin(), order.end());

    if (answer <= 4) {
        output(answer, order);
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        if (dist[i] == 2) {
            answer = 4;
            order.clear();
            order.push_back(1);
            order.push_back(prev[i]);
            order.push_back(i);
            order.push_back(1);
            order.push_back(N);
            output(answer, order);
            return 0;
        }
    }

    vector<int> relevant = adj[1];
    // adj[1].clear();

    for (int i = 2; i <= N; i++) {
        if (!adj[i].empty() && adj[i][0] == 1) {
            adj[i].erase(adj[i].begin());
        }
    }

    for (int i = 0; i < (int) relevant.size(); i++) {
        for (int j = i + 1; j < (int) relevant.size(); j++) {
            if (!is_edge(relevant[i], relevant[j])) {
                int start = relevant[i];
                bfs(start);

                for (int k = 1; k <= N; k++) {
                    if (dist[k] == 2) {
                        answer = 5;
                        order.clear();
                        order.push_back(1);
                        order.push_back(start);
                        order.push_back(prev[k]);
                        order.push_back(k);
                        order.push_back(start);
                        order.push_back(N);
                        output(answer, order);
                        return 0;
                    }
                }
            }
        }
    }

    output(answer, order);
    return 0;
}