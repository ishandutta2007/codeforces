#include <bits/stdc++.h>

using namespace std;

long long const INFLL = 1LL << 60;
int const N = 1234567;
struct edge {
    int from;
    int to;
    int w;
    int id;
};

long long d[N];
int ans[N];
vector<edge> edges[N];

struct comp {
    bool operator () (int x, int y) const {
        if (d[x] != d[y]) return d[x] < d[y];
        return x < y;
    }
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, u, w;
        scanf("%d%d%d", &v, &u, &w);
        --v;
        --u;
        edges[v].push_back({v, u, w, i});
        edges[u].push_back({u, v, w, i});
    }
    int start;
    scanf("%d", &start);
    --start;
    set<int, comp> q;
    fill(d, d + n, INFLL);
    d[start] = 0;
    q.insert(start);
    int ac = 0;
    long long sum = 0;
    while (!q.empty()) {
        int v = *q.begin();
        q.erase(q.begin());
        int me = -1;
        int best = 1 << 30;
        for (edge & e : edges[v]) {
            if (d[e.to] + e.w == d[v]) {
                if (me < 0 || best > e.w) {
                    me = e.id;
                    best = e.w;
                }
            }
            if (d[v] + e.w < d[e.to]) {
                q.erase(e.to);
                d[e.to] = d[v] + e.w;
                q.insert(e.to);
            }
        }
        if (me >= 0) {
            ans[ac++] = me;
            sum += best;
        }
    }
    printf("%lld\n", sum);
    for (int i = 0; i < ac; i++) {
        if (i > 0) putchar(' ');
        printf("%d", ans[i] + 1);
    }
    puts("");
}