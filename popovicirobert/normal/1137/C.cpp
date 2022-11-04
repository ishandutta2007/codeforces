#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

vector < vector <int> > g, gr;

const int MAXN = 50 * 1e5;

int comp[MAXN + 1], dp[MAXN + 1], cnt[MAXN + 1];
int top[MAXN + 1], sz;
bool vis[MAXN + 1];

void dfs(int id, int d) {
    vis[id] = 1;

    int nod = id / d, t = id - (id / d) * d;

    for(auto it : g[nod]) {
        int cur = it * d + (t + 1) % d;
        if(vis[cur] == 0) {
            dfs(cur, d);
        }
    }
    top[sz++] = id;
}

void dfs1(int id, int idc, int d) {
    comp[id] = idc;

    int nod = id / d, t = id - (id / d) * d;

    for(auto it : gr[nod]) {
        int cur = it * d + (t + d - 1) % d;
        if(comp[cur] == 0) {
            dfs1(cur, idc, d);
        }
    }
}

vector <string> open;

inline bool get(int nod, int d) {
    return open[nod / d][nod - (nod / d) * d] - '0';
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, m, d, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> d;

    vector <int> u(m), v(m);
    for(i = 0; i < m; i++) {
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;
    }

    open.resize(n);
    for(i = 0; i < n; i++) {
        cin >> open[i];
    }

    g.resize(n), gr.resize(n);
    for(i = 0; i < m; i++) {
        g[u[i]].push_back(v[i]);
        gr[v[i]].push_back(u[i]);
    }

    for(i = 0; i < n * d; i++) {
        if(vis[i] == 0) {
            dfs(i, d);
        }
    }

    int id = 0;
    for(i = n * d - 1; i >= 0; i--) {
        if(comp[top[i]] == 0) {
            dfs1(top[i], ++id, d);
        }
    }
    
    //

    for(i = 0; i < n * d; i += d) {
        for(int a = i; a < i + d; a++) {
            bool ok = get(a, d);
            for(int b = a - 1; b >= i && ok; b--) {
                if(comp[a] == comp[b] && get(b, d)) {
                    ok = 0;
                }
            }
            cnt[comp[a]] += ok;
        }
    }

    for(i = 0; i < n * d; i++) {
        int id = top[i];
        int nod = id / d, t = id - (id / d) * d;

        dp[comp[id]] = max(dp[comp[id]], cnt[comp[id]]);

        for(auto it : g[nod]) {
            int cur = it * d + (t + 1) % d;
            if(comp[cur] != comp[id]) {
                dp[comp[id]] = max(dp[comp[id]], dp[comp[cur]] + cnt[comp[id]]);
            }
        }
    }

    cout << dp[comp[0]];

    //cin.close();
    //cout.close();
    return 0;
}