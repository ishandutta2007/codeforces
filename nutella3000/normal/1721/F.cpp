#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;
const ll infL = 1e18 + 7;
const int N = 4e5 + 3;

struct edge {
    int to, cap;
    edge(int to, int cap) : to(to), cap(cap) {}
};

int n;
vector<edge> ed;
vector<int> gr[N];
int cur[N];
int h[N];

void add_edge(int v1, int v2, int c) {
    gr[v1].emplace_back(size(ed));
    ed.emplace_back(v2, c);
    gr[v2].emplace_back(size(ed));
    ed.emplace_back(v1, 0);
}

bool bfs(int s, int t) {
    fill(h, h + n, -1);
    h[s] = 0;
    queue<int> que({s});
    while (size(que)) {
        int u = que.front(); que.pop();
        for (int i : gr[u]) {
            auto [v, c] = ed[i];
            if (c && h[v] == -1) {
                h[v] = h[u] + 1;
                if (v == t) return true;
                que.emplace(v);
            }
        }
    }
    return false;
}

int dfs(int u, int t, int f) {
    if (u == t) return f;
    int r = f;
    for (int& i = cur[u]; i < size(gr[u]); ++i) {
        int j = gr[u][i];
        auto [v, c] = ed[j];
        if (c && h[v] == h[u]+1) {
            int nf = dfs(v, t, min(r, c));
            r -= nf;
            ed[j].cap -= nf;
            ed[j^1].cap += nf;
            if (!r) return f;
        }
    }
    return f - r;
}

int flow(int s, int t) {
    int f = 0;
    while (bfs(s, t)) {
        fill(cur, cur+n, 0);
        f += dfs(s, t, inf);
    }
    return f;
}

void run() {
    int n1, n2, m, q; cin >> n1 >> n2 >> m >> q;
    int S = n1+n2, T = S+1; n = T+1;

    vector<int> x(m), y(m);
    for (int i = 0; i < m; ++i) {
        cin >> x[i] >> y[i]; --x[i], --y[i];
        add_edge(x[i], n1+y[i], 2);
    }
    for (int i = 0; i < n1; ++i)
        add_edge(S, i, 1);
    for (int i = 0; i < n2; ++i)
        add_edge(n1+i, T, 1);

    int F = flow(S, T);
    ll sum = 0;
    vector<int> e(n, -1);
    for (int i = 0; i < m; ++i) {
        if (ed[2*i].cap == 1) {
            e[x[i]] = e[y[i] + n1] = i;
            sum += i+1;
        }
    }

    vector<int> del;
    for (int i = 0; i < n1; ++i)
        if (h[i] == -1) del.emplace_back(i);
    for (int i = n1; i < n1+n2; ++i)
        if (h[i] != -1) del.emplace_back(i);

    while (q--) {
        int ty; cin >> ty;
        if (ty == 1) {
            int u = del.back(); del.pop_back();
            cout << 1 << '\n';
            cout << (u < n1 ? u+1 : -(u+1-n1)) << '\n';
            
            int j = e[u];
            e[x[j]] = e[n1 + y[j]] = -1;
            sum -= j+1;
            cout << sum << endl;
            --F;
        } else {
            cout << F << '\n';
            for (int i = 0; i < n1; ++i)
                if (e[i] != -1) cout << e[i]+1 << " ";
            cout << endl;
        }
    }
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}