#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
const int C = 26;

int n, m;
int pos[N];
vector<pair<int, int>> queries[N];
int res[N];

struct BIT {
    int t[N];

    void add(int x, int v) {
        while (x < N) {
            t[x] += v;
            x += x & -x;
        }
    }

    int get(int x) {
        int res = 0;
        while (x) {
            res += t[x];
            x -= x & -x;
        }
        return res;
    }

    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

struct AC {
    int len[N];
    int nxt[N][C];
    int link[N];
    int cnt;
    vector<int> songs[N];
    vector<int> adj[N];
    int in[N], out[N], cntEuler;
    BIT t;

    AC() {
        memset(nxt, -1, sizeof nxt);
        memset(link, -1, sizeof link);
        cnt = cntEuler = 0;
    }

    int add(int cur, char now) {
        if (nxt[cur][now - 'a'] != -1) {
            return nxt[cur][now - 'a'];
        }
        nxt[cur][now - 'a'] = ++cnt;
        len[cnt] = len[cur] + 1;
        return cnt;
    }

    void dfs(int u) {
        in[u] = ++cntEuler;
        for (int v : adj[u]) {
            dfs(v);
        }
        out[u] = cntEuler;
    }

    void build() {
        queue<int> q;
        q.push(0);
        link[0] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < C; i++) {
                int foo = u ? nxt[link[u]][i] : u;
                if (nxt[u][i] == -1) nxt[u][i] = foo;
                else {
                    adj[foo].push_back(nxt[u][i]);
                    link[nxt[u][i]] = foo;
                    q.push(nxt[u][i]);
                }
            }
        }
        dfs(0);
    }

    void dfsCalc(int u) {
        t.add(in[u], 1);

        for (auto song : songs[u]) {
            for (auto query : queries[song]) {
                res[query.second] = t.get(in[query.first], out[query.first]);
            }
        }

        for (int i = 0; i < C; i++) {
            if (len[nxt[u][i]] != len[u] + 1) continue;
            dfsCalc(nxt[u][i]);
        }

        t.add(in[u], -1);
    }
} ac;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            char u;
            cin >> u;
            pos[i] = ac.add(0, u);
        } else {
            char u;
            int id;
            cin >> id >> u;
            pos[i] = ac.add(pos[id], u);
        }
        ac.songs[pos[i]].push_back(i);
    }  

    cin >> m;
    for (int i = 1; i <= m; i++) {
        int id;
        string s;
        cin >> id >> s;
        int last = 0;
        for (char u : s) {
            last = ac.add(last, u);
        }
        queries[id].push_back({last, i});
    }

    ac.build();
    ac.dfsCalc(0);
    for (int i = 1; i <= m; i++) {
        cout << res[i] << '\n';
    }
    return 0;
}