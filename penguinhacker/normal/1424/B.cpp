#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;

struct Edge {
    int a;
    int b;
    int w;
    Edge(int aa = 0, int bb = 0, int ww = 0) : a(aa), b(bb), w(ww) {}
};
vector<Edge> edges;
bool cmp(Edge e1, Edge e2) {
    return e1.w < e2.w;
}

bool work(int x) {
    bool vis1[10005] = { false };
    bool vis2[10005] = { false };
    for (int i = x; i >= 0; --i) {
        vis1[edges[i].a] = true;
        vis2[edges[i].b] = true;
    }
    for (int i = 1; i <= n; ++i) if (!vis1[i] || !vis2[i]) return false;
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        edges.push_back(Edge(u, v, d));
    }
    sort(edges.begin(), edges.end(), cmp);
    bool vis1[10005];
    bool vis2[10005];
    for (int i = 0; i < m; ++i) {
        vis1[edges[i].a] = true;
        vis2[edges[i].b] = true;
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis1[i] || !vis2[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    int low = 0;
    int high = m - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (work(mid)) high = mid;
        else low = mid + 1;
    }
    cout << edges[low].w << endl;
}