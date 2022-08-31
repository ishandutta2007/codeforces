#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2006;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> d(m);
    range(i, m) cin >> d[i];
    sort(all(d));
    int g, r;
    cin >> g >> r;
    vector<vector<int>> dist(m, vector<int> (g, INFi));
    ll ans = INF;
    deque<pair<int, int>> q;
    dist[0][0] = 0;
    q.push_back({0, 0});
    while(!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop_front();
        if (i != m - 1) {
            int to = j + d[i+1] - d[i];
            if (to == g) to = 0;
            if (to < g && dist[i+1][to] > dist[i][j] + (to == 0)) {
                dist[i+1][to] = dist[i][j] + (to == 0);
                if (to) q.push_front({i+1, to});
                else q.push_back({i+1, to});
            }
        }
        if (i) {
            int to = j + d[i] - d[i-1];
            if (to == g) to = 0;
            if (to < g && dist[i-1][to] > dist[i][j] + (to == 0)) {
                dist[i-1][to] = dist[i][j] + (to == 0);
                if (to) q.push_front({i-1, to});
                else q.push_back({i-1, to});
            }
        }
    }
    range(i, g) {
        if (dist[m-1][i] == INFi) continue;
        ans = min(ans, 1ll * dist[m-1][i] * (r + g) + i);
        if (i == 0) ans = 1ll * (dist[m-1][i] - 1) * (r + g) + g;
    }
    cout << (ans != INF ? ans : -1);
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