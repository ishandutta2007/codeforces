#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

vector<int> g[maxN];
int used[maxN];

void dfs(int v) {
    used[v] = 1;
    for(auto &u: g[v]) {
        if (used[u] == 1) {
            cout << -1;
            exit(0);
        }
        if (used[u] == 2) continue;
        dfs(u);
    }
    used[v] = 2;
}


vector<int> g2[maxN][2];

int n;

vector<int> get_min(int c) {
    vector<int> mins(n+1, -1);
    vector<int> deg(n+1, -1);
    queue<int> q;
    for(int i = 1; i <= n; ++i) {
        if (g2[i][c].empty()) q.push(i);
        deg[i] = g2[i][c].size();
        mins[i] = i;
    }
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(auto &u: g2[v][c^1]) {
            deg[u]--;
            if (deg[u] == 0) q.push(u);
            mins[u] = min(mins[u], mins[v]);
        }
    }
    return mins;
}

void solve() {
    int m; cin >> n >> m;
    vector<pair<int, int>> a(m);
    range(i, m) {
        cin >> a[i].first >> a[i].second;
        g[a[i].second].push_back(a[i].first);
    }
    for(int i = 1; i <= n; ++i) {
        if (!used[i]) dfs(i);
    }
    range(i, m) {
        g2[a[i].first][0].push_back(a[i].second);
        g2[a[i].second][1].push_back(a[i].first);
    }
    string answer = "";
    int ans = 0;
    auto min1 = get_min(0), min2 = get_min(1);
    for(int i = 1; i <= n; ++i) {
        if (min1[i] < i || min2[i] < i) {
            answer += "E";
        } else {
            answer += "A";
            ans++;
        }
    }
    cout << ans << "\n" << answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}