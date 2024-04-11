#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair <int, int> two;
typedef pair <int, two> three;
const int N = 3e3;

int g[N][N], p[N], deep[N];
vector <two> edges[N];

int find_parent(int x) {
    if (p[x] != x) p[x] = find_parent(p[x]);
    return p[x];
}

bool check(int nom, int x, int prev, long long dist) {
    if (g[nom][x] != dist) return false;
    bool res = true;
    for (int i = 0; i < edges[x].size(); i++) {
        int to = edges[x][i].first;
        if (prev == to) continue;
        res &= check(nom, to, x, dist + edges[x][i].second);
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) scanf("%d", &g[i][j]);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (g[i][j] != g[j][i]) {
        puts("NO");
        return 0;
    }
    vector <three> x;
    for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) x.push_back(make_pair(g[i][j], make_pair(i, j)));
    sort(x.begin(), x.end());
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 0; i < x.size(); i++) {
        int v1 = x[i].second.first, p1 = find_parent(v1);
        int v2 = x[i].second.second, p2 = find_parent(v2);
        if (p1 == p2) continue;
        if (rand() % 2) p[p2] = p1; else p[p1] = p2;
        if (x[i].first == 0) {
            puts("NO");
            return 0;
        }
        edges[v1].push_back(make_pair(v2, x[i].first));
        edges[v2].push_back(make_pair(v1, x[i].first));
    }
    bool ans = true;
    for (int i = 1; i <= n; i++) ans &= check(i, i, i, 0);
    puts((ans) ? "YES" : "NO");
    return 0;
}