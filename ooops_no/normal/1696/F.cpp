#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

vector<pair<int,int>> ans;
vector<vector<int>> g;

void graph(int n) {
    ans.clear();
    g.clear();
    g.resize(n);
}

void add_edge(int a, int b) {
    ans.pb({a + 1, b + 1});
    g[a].pb(b);
    g[b].pb(a);
}

vector<vector<int>> get(int n) {
    vector<vector<int>> d;
    vector<int> q(n);
    for (int i = 0; i < n; i++) {
        vector<int> dd(n, -1);
        dd[i] = 0;
        int ind = 0;
        q[ind++] = i;
        for (int j = 0; j < n; j++) {
            int v = q[j];
            for (auto to : g[v]) {
                if (dd[to] == -1) {
                    dd[to] = dd[v] + 1;
                    q[ind++] = to;
                }
            }
        }
        d.pb(dd);
    }
    return d;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<vector<bool>>> edge(n, vector<vector<bool>>(n, vector<bool>(n)));
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            for (int k = 0; k < n; k++) {
                char c;
                cin >> c;
                edge[i][j + i + 1][k] = c - '0';
                edge[j + i + 1][i][k] = edge[i][j + i + 1][k];
            }
        }
    }
    for (int i = 1; i < n; i++) {
        //edge 0 -> i;
        vector<bool> used(n);
        graph(n);
        used[0] = used[i] = 1;
        deque<pair<int,int>> q{{0, i}};
        for (int j = 1; j < n; j++) {
            if (j != i && edge[j][i][0]) {
                used[j] = 1;
                q.pb({0, j});
            }
        }
        int cnt = 0;
        while (q.size() > 0) {
            int u = q.front().first, v = q.front().second;
            q.pop_front();
            cnt++;
            add_edge(u, v);
            for (int k = 0; k < n; k++) {
                if (used[k]) continue;
                if (edge[u][k][v]) {
                    used[k] = 1;
                    q.pb({v, k});
                }
            }
        }
        if (cnt != n - 1) {
            continue;
        }
        auto d = get(n);
        bool good = 1;
        for (int a = 0; a < n && good; a++) {
            for (int b = a + 1; b < n && good; b++) {
                for (int c = 0; c < n; c++) {
                    bool val = (d[a][c] == d[b][c]);
                    good &= (val == edge[a][b][c]);
                }
            }
        }
        if (good) {
            cout << "Yes\n";
            for (auto to : ans) {
                cout << to.first << ' ' << to.second << endl;
            }
            return;
        }
    }
    cout << "No\n";
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}