#include <bits/stdc++.h>

using namespace std;
#define int long long
#define loop1(from, n) for(int i = from; i < n;i++)
#define loop2(from, n) for(int i = from;i >= n;i--)
const int inf = 1e9 + 7;
const int max_n = 100005;
int n;
vector<int> gr[max_n];
int max_dp[max_n], max2_dp[max_n], verb1[max_n], verb2[max_n];
int v1, v2, len;
void dfs(int v, int pr) {
    verb1[v] = v;
    verb2[v] = v;
    for(int i : gr[v]) {
        if (i == pr) continue;
        dfs(i, v);
        if (max_dp[i] + 1 > max_dp[v]) {
            max_dp[v] = max_dp[i] + 1;
            verb1[v] = verb1[i];
        }else if (max2_dp[v] < max_dp[i] + 1) {
            max2_dp[v] = max_dp[i] + 1;
            verb2[v] = verb1[i];
        }
    }
    if (max_dp[v] + max2_dp[v] + 1 > len) {
        len = max_dp[v] + max2_dp[v] + 1;
        v1 = verb1[v];
        v2 = verb2[v];
    }
}
vector<int> path;
bool dfs1(int v, int pr) {
    path.emplace_back(v);
    if (v == v2) {
        return true;
    }
    for(int i : gr[v]) {
        if (i != pr) {
            if (dfs1(i, v)) return true;
        }
    }
    path.pop_back();
    return false;
}
bool solve(int start) {
    deque<int> bfs;
    bfs.emplace_back(start);
    vector<int> dist(n, -1);
    vector<int> degree(n, -1);
    dist[start] = 0;
    while(!bfs.empty()) {
        int v = bfs.back();
        bfs.pop_back();
        for(int to : gr[v]) {
            if (dist[to] != -1) continue;
            dist[to] = dist[v] + 1;
            if (degree[dist[to]] == -1) {
                degree[dist[to]] = gr[to].size();
            }
            if (degree[dist[to]] != gr[to].size()) return false;
            bfs.emplace_back(to);
        }
    }
    cout << start + 1;
    return true;
}
int32_t main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0;i < n - 1;i++) {
        int from, to;
        cin >> from >> to;
        from--; to--;
        gr[from].emplace_back(to);
        gr[to].emplace_back(from);
    }
    dfs(0, -1);
    dfs1(v1, -1);
    if (solve(v1)) return 0;
    if (solve(v2)) return 0;
    if (path.size() % 2 == 0) {
        cout << -1;
    }else{
        int mid = path.size() / 2;
        if (solve(path[mid])) return 0;
        int id = -1;
        for(int i : gr[path[mid]]) {
            int now = i;
            int prev = path[mid];
            int dist = 1;
            while(gr[now].size() != 1) {
                if (gr[now].size() > 2) break;
                int next = gr[now][0];
                if (next == prev) next = gr[now][1];
                prev = now;
                now = next;
                dist++;
            }
            if (dist != mid && gr[now].size() == 1 && now != v1 && now != v2) {
                if (id != -1) {
                    cout << -1;
                    return 0;
                }
                id = now;
            }
        }
        if (id == -1) cout << -1;
        else if (!solve(id)) cout << -1;
    }
}