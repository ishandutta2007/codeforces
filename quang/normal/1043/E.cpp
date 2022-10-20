#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n, m;
vector<int> adj[N];
// int pos[N];

struct Data {
    int x, y, id;
} a[N];

bool cmp(const Data& u, const Data &v) {
    return u.x - u.y < v.x - v.y;
}

long long pre[N], suf[N];
long long res[N];
int x[N], y[N];

long long get(int u, int v) {
    return min(x[u] + y[v], x[v] + y[u]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
        x[i] = a[i].x;
        y[i] = a[i].y;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    sort(a + 1, a + n + 1, cmp);
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i].id << endl;
    // }
    // for (int i = 1; i <= n; i++) {
    //     pos[a[i].id] = i;
    // }
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i].x;
    }
    for (int i = n; i; i--) {
        suf[i] = suf[i + 1] + a[i].y;
    }
    for (int i = 1; i <= n; i++) {
        long long foo = 1ll * a[i].y * (i - 1) + pre[i - 1];
        long long bar = 1ll * a[i].x * (n - i) + suf[i + 1];
        // cout << i << " " << foo << " " << bar << endl;
        res[a[i].id] = foo + bar;
        for (int v : adj[a[i].id]) {
            res[a[i].id] -= get(v, a[i].id);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}