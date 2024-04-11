#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e3+10, MOD = 1e9+7;

#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Edge {
    int next;
    long long capacity;
    Edge(const int n, const long long c) : next(n), capacity(c) {}
};
class Dinic {
private:
    const int n;
    vector<int> idx;
    vector<int> dist;
public:
    vector<vector<int>> adj;
    vector<Edge> edges;
    Dinic(const int n)
        : n(n)
        , idx(n)
        , dist(n)
        , adj(n)
    {
    }
    void add_arc(const int u, const int v, const long long capacity) {
        if (u != v && capacity != 0) {
            const int uv = edges.size();
            edges.emplace_back(v, capacity);
            const int vu = edges.size();
            edges.emplace_back(u, 0);
            adj[u].push_back(uv);
            adj[v].push_back(vu);
        }
    }
    void add_edge(const int u, const int v, const long long capacity) {
        if (u != v && capacity != 0) {
            const int uv = edges.size();
            edges.emplace_back(v, capacity);
            const int vu = edges.size();
            edges.emplace_back(u, capacity);
            adj[u].push_back(uv);
            adj[v].push_back(vu);
        }
    }
    long long dfs(const int u, const int t, const long long delta) {
        if (delta == 0)
            return 0;
        if (u == t)
            return delta;
        int& i = idx[u];
        while (i >= 0) {
            const int uv = adj[u][i];
            const int v = edges[uv].next;
            if (dist[v] == dist[u]+1) {
                const long long bottleneck = dfs(v, t, min(delta, edges[uv].capacity));
                if (bottleneck > 0) {
                    const int vu = uv ^ 1;
                    edges[uv].capacity -= bottleneck;
                    edges[vu].capacity += bottleneck;
                    return bottleneck;
                }
            }
            --i;
        };
        return 0;
    }
    long long solve(const int s, const int t) {
        long long total_flow = 0;
        for (;;) {
            // Run a BFS
            queue<int> q;
            for (int v = 0; v < n; ++v)
                dist[v] = -1;
            dist[s] = 10;
            q.push(s);
            while (!q.empty()) {
                const int u = q.front();
                q.pop();
                for (const int i : adj[u]) {
                    const Edge& uv = edges[i];
                    const int v = uv.next;
                    if (uv.capacity > 0 && dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
            if (dist[t] == -1)
                break;
            // Find a blocking flow
            for (int v = 0; v < n; ++v)
                idx[v] = adj[v].size()-1;
            for (;;) {
                const long long flow = dfs(s, t, numeric_limits<long long>::max());
                if (flow == 0)
                    break;
                total_flow += flow;
            }
        }
        return total_flow;
    }
};
class LRDinic {
protected:
    int n;
    vector<long long> from_source, to_sink, outgoing_capacity;
    long long total_demand;
public:
    Dinic dinic;
    LRDinic(const int n)
        : n(n)
        , from_source(n)
        , to_sink(n)
        , outgoing_capacity(n)
        , total_demand(0)
        , dinic(n+2)
    {
    }
    void add_arc(const int u, const int v, const long long demand, const long long capacity) {
        assert(capacity >= demand);
        if (u != v) {
            from_source[v] += demand;
            to_sink[u] += demand;
            dinic.add_arc(u, v, capacity-demand);
            total_demand += demand;
            outgoing_capacity[u] += capacity;
        }
    }
    long long compute(const int s, const int t) {
        // Add extra edges
        const int source = n;
        const int sink = n+1;
        int extra_edges = 0;
        for (int v = 0; v < n; ++v) {
            if (from_source[v] != 0) {
                ++extra_edges;
                dinic.add_arc(source, v, from_source[v]);
            }
            if (to_sink[v] != 0) {
                ++extra_edges;
                dinic.add_arc(v, sink, to_sink[v]);
            }
        }
        dinic.add_arc(t, s, std::numeric_limits<long long>::max());
        ++extra_edges;
        // Compute a feasible flow in G (by computing a saturating flow in G')
        long long flow_aux = dinic.solve(source, sink);
        if (flow_aux != total_demand)
            return 0;
        // Remove extra edges
        while (extra_edges--) {
            dinic.adj[dinic.edges.back().next].pop_back();
            dinic.edges.pop_back();
            dinic.adj[dinic.edges.back().next].pop_back();
            dinic.edges.pop_back();
        }
        // Extend the current flow to a maximum flow
        dinic.solve(s, t);
        long long flow = outgoing_capacity[s];
        for (const int idx : dinic.adj[s])
            flow -= dinic.edges[idx].capacity;
        return flow;
    }
};
class LRDinicRetrieval : public LRDinic {
private:
    vector<map<int, long long>> original_capacity;
public:
    LRDinicRetrieval(const int n)
        : LRDinic(n)
        , original_capacity(n)
    {
    }
    int compute(const int source, const int sink) {
        return LRDinic::compute(source, sink);
    }
    void add_arc(const int u, const int v, const long long demand, const long long capacity) {
        LRDinic::add_arc(u, v, demand, capacity);
        original_capacity[u][v] += capacity;
        original_capacity[v][u] -= capacity;
    }
    vector<map<int, long long>> retrieve_skew_flow() {
        vector<map<int, long long>> ans = original_capacity;
        for (int u = 0; u < n; ++u) {
            for (const int idx : dinic.adj[u]) {
                if ((idx&1) == 0) {
                    const Edge& e = dinic.edges[idx];
                    const int v = e.next;
                    ans[u][v] -= e.capacity;
                    ans[v][u] += e.capacity;
                }
            }
        }
        for (int u = 0; u < n; ++u) {
            for (auto it = ans[u].begin(), end=ans[u].end(); it != end; )
                if (it->second == 0)
                    it = ans[u].erase(it);
                else
                    ++it;
        }
        return ans;
    }
    vector<map<int, long long>> retrieve_gross_flow() {
        // Note: returns skew-symmetric flow
        vector<map<int, long long>> ans = original_capacity;
        for (int u = 0; u < n; ++u) {
            for (const int idx : dinic.adj[u]) {
                if ((idx&1) == 0) {
                    const Edge& e = dinic.edges[idx];
                    const int v = e.next;
                    ans[u][v] -= e.capacity;
                    ans[v][u] += e.capacity;
                }
            }
        }
        for (int u = 0; u < n; ++u) {
            for (auto it = ans[u].begin(), end=ans[u].end(); it != end; )
                if (it->second <= 0)
                    it = ans[u].erase(it);
                else
                    ++it;
        }
        return ans;
    }
};

const int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
const char dc[4]={'D', 'R', 'U', 'L'};

vector<pair<int, int>> solve_match(int L, int R, vector<pair<int, int>> edges, vector<int> left, vector<int> right) {
    LRDinicRetrieval flower(L+R+2);
    const int S = L+R, T = L+R+1;

    vector<bool> needL(L), needR(R);
    for (auto l : left) needL[l] = 1;
    for (auto r : right) needR[r] = 1;

    for (int i = 0; i < L; i++) flower.add_arc(S, i, needL[i], 1);
    for (auto e : edges) {
        flower.add_arc(e.first, L+e.second, 0, 1);
    }
    for (int i = 0; i < R; i++) flower.add_arc(L+i, T, needR[i], 1);

    if (!flower.compute(S, T)) return {};
    auto flow = flower.retrieve_gross_flow();

    vector<pair<int, int>> match;
    for (int i = 0; i < L; i++) {
        for (auto it : flow[i]) {
            if (it.second) {
                match.push_back({i, it.first-L});
            }
        }
    }
    return match;
}
void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        cin >> a[i][j];
    }
    int L=0, R=0;
    vector<vector<int>> col(n, vector<int>(m));
    vector<int> left, right;
    vector<pair<int, int>> edges;

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if ((i+j)&1) col[i][j]=L++;
        else col[i][j]=R++;
    }
    vector<pair<int, int>> li(L), ri(R);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        bool bad=1;
        for (int k = 0; k < 4; k++) {
            int ni = i+dx[k], nj = j+dy[k];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

            if (a[ni][nj] < a[i][j])
                bad=0;

            if (a[ni][nj] == a[i][j] && make_pair(i, j) < make_pair(ni, nj)) {
                if ((i+j)&1) edges.push_back({col[i][j], col[ni][nj]});
                else edges.push_back({col[ni][nj], col[i][j]});
            }
        }
        if ((i+j)&1) li[col[i][j]] = {i, j};
        else ri[col[i][j]] = {i, j};

        if (bad) {
            if ((i+j)&1) left.push_back(col[i][j]);
            else right.push_back(col[i][j]);
        }
    }

    auto match = solve_match(L, R, edges, left, right);
    if (!sz(match)){ cout << "NO\n"; return; }
    else cout << "YES\n";


    vector<vector<pair<int, int>>> cyc(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<int>> cost(n, vector<int>(m));
    for (auto e : match) {
        auto f = li[e.first], s = ri[e.second];
        cyc[f.first][f.second] = s;
        cyc[s.first][s.second] = f;

        cost[f.first][f.second] = a[f.first][f.second]-1, cost[s.first][s.second] = 1;
    }

    vector<vector<char>> dir(n, vector<char>(m, '?'));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cyc[i][j] == make_pair(-1, -1)) {
                for (int k = 0; k < 4; k++) {
                    int ni = i+dx[k], nj = j+dy[k];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

                    if (a[ni][nj] < a[i][j]) {
                        cost[i][j] = a[i][j]-a[ni][nj];
                        dir[i][j] = dc[k];
                        break;
                    }
                }
            } else {
                for (int k = 0; k < 4; k++) {
                    int ni = i+dx[k], nj = j+dy[k];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m || ni != cyc[i][j].first || nj != cyc[i][j].second) continue;
                    dir[i][j] = dc[k];
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << cost[i][j] << ' ';
        }
        cout << '\n';
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dir[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}