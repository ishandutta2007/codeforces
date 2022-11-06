#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2000 + 5;

int N, K;
int vis[MAX_N], dis[MAX_N][MAX_N];
set<pair<int,int>> e;

void query(int x) {
    printf("? %d\n", x);
    fflush(stdout);
    for (int i = 1, d; i <= N; i ++) {
        scanf("%d", &d);
        dis[x][i] = dis[i][x] = d;
    }
}
bool cmp_by_dis1(int i, int j) {
    return dis[1][i] < dis[1][j];
}
void add_edge(int x, int y) {
    if (x > y) swap(x, y);
    vis[x] = vis[y] = 1;
    e.insert(make_pair(x, y));
}

int main() {
    scanf("%d", &N);
    vis[1] = 1;
    query(1);
    for (int i = 1; i <= N; i ++) {
        if (dis[1][i] == 1) {
            add_edge(1, i);
        }
    }
    while ((int) e.size() < N - 1) {
        int k = 0, d = 0;
        for (int i = 1; i <= N; i ++) {
            if (!vis[i] && d < dis[1][i]) {
                d = dis[1][i], k = i;
            }
        }
        query(k);
        vector<int> p, q;
        for (int i = 1; i <= N; i ++) {
            if (dis[1][i] + dis[k][i] == dis[1][k]) {
                p.push_back(i);
            }
            if (dis[1][i] + dis[k][i] == dis[1][k] + 2) {
                q.push_back(i);
            }
        }
        sort(p.begin(), p.end(), cmp_by_dis1);
        sort(q.begin(), q.end(), cmp_by_dis1);
        for (int i = 1; i < (int) p.size(); i ++) {
            add_edge(p[i - 1], p[i]);
        }
        for (int i = 0; i < (int) q.size(); i ++) {
            int x = q[i], j = dis[1][x] - 1;
            add_edge(x, p[j]);
        }
    }
    printf("!\n");
    for (auto t: e) {
        printf("%d %d\n", t.first, t.second);
    }
    return 0;
}