#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e2+10, MOD = 1e9+7;

bool eq[N][N][N];
int store[N][N];
int last[N];
int dist[N];

void dfs_dist(int c, int p, const vector<vector<int>>& adj, int d) {
    dist[c] = d;
    for (auto nxt : adj[c]) if (nxt != p)
        dfs_dist(nxt, c, adj, d + 1);
}

struct DSU {
	vector<int> p, sz;
	void init(int n) { 
        p.resize(n); iota(p.begin(), p.end(), 0);
        sz.assign(n, 1);
    }
	int find_set(int v) { 
        return v == p[v] ? v : p[v] = find_set(p[v]);
    }
	bool union_sets(int a, int b) {
        a = find_set(a), b = find_set(b);
        if (a == b) return false;
		if (sz[a] < sz[b]) swap(a, b);
		p[b] = a, sz[a] += sz[b], sz[b] = 0;
		return true;
	}
} d;


void solve() {
    int n; cin >> n; // special case n = 2

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int k = 0; k < n; k++)
        eq[i][j][k] = 0;

    for (int i = 1; i <= n-1; i++) {
        for (int j = 1; j <= n - i; j++) {
            string s; cin >> s;
            for (int k = 1; k <= sz(s); k++) {
                eq[k - 1][i - 1][i + j - 1] = eq[k - 1][i + j - 1][i - 1] = s[k - 1] == '1';
            }
        }
    }

    for (int i = 0; i < n; i++) for (int a = 0; a < n; a++) eq[i][a][a] = 1;

    for (int i = 0; i < n; i++) {
        d.init(n);
        for (int j = 0; j < n; j++) for (int k = 0; k < n; k++) {
            if (eq[i][j][k])
                d.union_sets(j, k);
        }
        for (int j = 0; j < n; j++) if (d.p[j] == j) {
            vector<int> v;
            for (int k = 0; k < n; k++) if (d.find_set(k) == j)
                v.push_back(k);

            for (int a : v) for (int b : v) if (!eq[i][a][b]) {
                cout << "No\n";
                return;
            }
            for (int k = 0; k < sz(v); k++) {
                store[i][v[k]] = (k == 0 ? -1 : v[k-1]);
            }
        }
    }

    for (int b = 1; b < n; b++) {
        int a = 0;
        vector<bool> vis(n);
        vis[a] = 1, vis[b] = 1;
        vector<pair<int, int>> q;

        auto add = [&](int x, int y) {
            for (int k = 0; k < n; k++) if (!vis[k] && eq[y][x][k]) {
                q.push_back({y, k});
                vis[k] = 1;
            }
        };

        add(a, b), add(b, a);

        for (int rep = 0; rep < sz(q); rep++) {
            auto e = q[rep];
            add(e.first, e.second);
        }
        q.push_back({a, b});

        vector<vector<int>> adj(n);
        for (auto [x, y] : q) {
            adj[x].push_back(y), adj[y].push_back(x);
        }
        bool bad = 0;
        for (int i = 0; i < n && !bad; i++) {
            dfs_dist(i, -1, adj, 0);
            memset(last, -1, sizeof(last));
            for (int j = 0; j < n && !bad; j++) {
                if (store[i][j] != last[dist[j]]) {
                    bad = 1;
                    break;
                }
                last[dist[j]] = j;
            }
        }
        if (!bad) {
            cout << "Yes\n";
            for (auto [a, b] : q) cout << a+1 << ' ' << b+1 << '\n';
            return;
        }
    }
    cout << "No\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}