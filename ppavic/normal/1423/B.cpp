#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 10005;
const int MAXM = 100005;

int n, m;
int par_u[MAXN], par_v[MAXN], dist[MAXN];
vector <int> v[MAXN];
vector < pair <int, pi> > e;
queue <int> q;

bool bfs () {
    for (int i = 1; i <= n; i++) {
        if (par_u[i] == 0) {
            dist[i] = 0;
            q.push(i);
        } else {
            dist[i] = 1e9;
        }
    }
    dist[0] = 1e9;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (dist[x] < dist[0]) {
            for (int sus : v[x]) {
                if (dist[par_v[sus]] == 1e9) {
                    dist[par_v[sus]] = dist[x] + 1;
                    q.push(par_v[sus]);
                }
            }
        }
    }
    return dist[0] != 1e9;
}

bool dfs (int x) {
    if (x != 0) {
        for (auto sus : v[x]) {
            if (dist[par_v[sus]] == dist[x] + 1 && dfs(par_v[sus])) {
                par_v[sus] = x;
                par_u[x] = sus;
                return 1;
            }
        }
        dist[x] = 1e9;
        return 0;
    }
    return 1;
}

int matching (int ind) {
    if (ind == m) return n;
    for (int i = 1; i <= n; i++) {
        v[i].clear();
    }
    for (int i = 0; i <= ind; i++) {
        int a = e[i].second.first, b = e[i].second.second;
        v[a].push_back(b);
    }
    memset(par_u, 0, sizeof par_u);
    memset(par_v, 0, sizeof par_v);
    int res = 0;
    while (bfs()) {
        for (int i = 1; i <= n; i++) {
            if (par_u[i] == 0 && dfs(i)) res++;
        }
    }
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        e.push_back({c, {a, b}});
    }
    sort(e.begin(), e.end());
    int lo = 0, hi = m;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (matching(mid) == n) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    if (lo == m) cout << -1; else cout << e[lo].first;
    return 0;
}