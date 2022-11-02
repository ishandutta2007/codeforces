#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

#define x first
#define y second

using namespace std;
typedef pair <int, int> pii;
const int N = 1000 + 10;
const int INF = 2147483647;

pii a[N], b[N];
vector <int> edges[N];
int g[N][N], r[N], real[N];
queue <int> q;

int position(int n1, int n2) {
    if (n2 == 0) {
        return 1;
    }
    long long dist = 1LL * (b[n1].x - b[n2].x) * (b[n1].x - b[n2].x) + 1LL * (b[n1].y - b[n2].y) * (b[n1].y - b[n2].y);
    if (dist > 1LL * (r[n1] + r[n2]) * (r[n1] + r[n2])) {
        return 3;
    }
    return (r[n1] < r[n2] ? 1 : 2);
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            g[i][j] = INF;
        }
    }
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &r[i], &b[i].x, &b[i].y);
    }
    for (int i = 1; i <= m; i++) {
        int nom = 0;
        for (int j = 1; j <= m; j++) {
            if (i == j) {
                continue;
            }
            int pos = position(i, j);
            if (pos != 1) {
                continue;
            }
            int placement = position(j, nom);
            if (placement != 1) {
                continue;
            }
            nom = j;
        }
        edges[i].push_back(nom);
        edges[nom].push_back(i);
    }
    for (int i = 0; i <= m; i++) {
        g[i][i] = 0;
        q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (size_t j = 0; j < edges[x].size(); j++) {
                int to = edges[x][j];
                if (g[i][x] + 1 < g[i][to]) {
                    g[i][to] = g[i][x] + 1;
                    q.push(to);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int nom = 0;
        for (int j = 1; j <= m; j++) {
            long long dist = 1LL * (a[i].x - b[j].x) * (a[i].x - b[j].x) + 1LL * (a[i].y - b[j].y) * (a[i].y - b[j].y);
            if (dist > 1LL * r[j] * r[j]) {
                continue;
            }
            int pos = position(j, nom);
            if (pos != 1) {
                continue;
            }
            nom = j;
        }
        real[i] = nom;
    }
    for (int i = 1; i <= k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x = real[x];
        y = real[y];
        printf("%d\n", g[x][y]);
    }
    return 0;
}