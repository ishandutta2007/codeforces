#include <bits/stdc++.h>

using namespace std;

const int N = 600010;
const int CHAR = 26;

int n, m;
vector<pair<int, int>> a[N];
int op[N];
int res[N];

struct SegmentTree {
    int t[N << 2];
    vector<pair<int, int>> st;

    SegmentTree() {
        memset(t, -1, sizeof t);
    }

    void update(int node, int l, int r, int x, int y, int val) {
        if (x > r || y < l) return;
        if (x <= l && r <= y) {
            st.push_back({node, t[node]});
            t[node] = max(t[node], val);
            return;
        }
        int m = l + r >> 1;
        update(node << 1, l, m, x, y, val);
        update(node << 1 | 1, m + 1, r, x, y, val);
    }

    int get(int node, int l, int r, int x) {
        if (x > r || x < l) return -1;
        int res = t[node];
        if (l < r) {
            int m = l + r >> 1;
            res = max(res, get(node << 1, l, m, x));
            res = max(res, get(node << 1 | 1, m + 1, r, x));
        }
        return res;
    }

    void rollback(int timestamp) {
        while (st.size() > timestamp) {
            pair<int, int> now = st.back(); st.pop_back();
            t[now.first] = now.second;
        }
    }
} st;

struct AC {
    int cnt;
    int nxt[CHAR][N];
    int suf[N];
    vector<int> ls[N];
    vector<int> queries[N];

    AC() {
        cnt = 1;
        memset(nxt, 0, sizeof nxt);
        memset(suf, 0, sizeof suf);
    }

    int add(const string &s) {
        int cur = 1;
        for (char u : s) {
            if (!nxt[u - 'a'][cur]) nxt[u - 'a'][cur] = ++cnt;
            cur = nxt[u - 'a'][cur];
        }
        return cur;
    }

    vector<int> adj[N];


    void build() {
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < CHAR; i++) {
                int v = u == 1 ? u : nxt[i][suf[u]];
                if (!nxt[i][u]) nxt[i][u] = v;
                else {
                    suf[nxt[i][u]] = v;
                    adj[v].push_back(nxt[i][u]);
                    q.push(nxt[i][u]);
                    // cout << "adj " << v << ' ' << nxt[i][u] << endl;
                }
            }
        }
    }

    void dfs(int u) {
        // cout << "# " << u << endl;
        int timestamp = st.st.size();
        for (int val : ls[u]) {
            for (int i = 0; i + 1 < a[val].size(); i++) {
                st.update(1, 1, m, a[val][i].first, a[val][i + 1].first - 1, a[val][i].second);
            }
            st.update(1, 1, m, a[val].back().first, m, a[val].back().second);
        }

        for (int q : queries[u]) {
            res[q] = max(res[q], st.get(1, 1, m, q));
        }

        for (int v : adj[u]) dfs(v);

        st.rollback(timestamp);
    }

    void solve() {
        dfs(1);
    }
} ac;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int pos = ac.add(s);
        ac.ls[pos].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        a[i].push_back({1, 0});
    }

    for (int i = 1; i <= m; i++) {
        cin >> op[i];
        if (op[i] == 1) {
            int id, x;
            cin >> id >> x;
            a[id].push_back({i, x});
        } else {
            string s;
            cin >> s;
            ac.add(s);
            int cur = 1;
            for (char u : s) {
                cur = ac.nxt[u - 'a'][cur];
                ac.queries[cur].push_back(i);
            }
        }
    }
    ac.build();
    fill(res + 1, res + m + 1, -1);
    ac.solve();
    for (int i = 1; i <= m; i++) {
        if (op[i] == 2) cout << res[i] << '\n';
    }
    return 0;
}