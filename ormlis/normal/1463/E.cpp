#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
typedef long long ll;

using namespace std;

const ll INF = 2e18 + 5;
const int INFi = 1e9;
const int maxN = 3e5 + 5;
const int md2 = 998244353;
const int md = 999999001;
vector<int> g[maxN];
int px[maxN];
int ny[maxN];
bool can[maxN];
int need[maxN];
int P[maxN];
int pX[maxN];
int cur[maxN];
bool was[maxN];
int t = 0;

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        g[p].push_back(i);
        P[i] = p;
    }
    range(_, k) {
        int x, y;
        cin >> x >> y;
        px[y] = x;
        ny[x] = y;
    }
    function<void(int, int)> dfs = [&](int v, int p) {
        pX[v] = p;
        if (cur[P[v]] != t) need[p]--;
        cur[v] = t;
        if (ny[v] != 0) {
            dfs(ny[v], p);
        }
    };
    range(i, n + 1) {
        if (px[i] == 0 && ny[i] != 0) {
            cur[i] = ++t;
            dfs(ny[i], i);
        }
    }
    range(i, n + 1) {
        if (px[i] != 0 && pX[i] == 0) {
            cout << "0\n";
            return;
        }
    }
    deque<int> q;
    vector<int> ans;
    q.push_back(0);
    can[0] = true;
    was[0] = true;
    while(!q.empty()) {
        int v = q.front();
        q.pop_front();
        ans.push_back(v);
        for(auto &u : g[v]) {
            can[u] = true;
            if (pX[u] != 0) {
                need[pX[u]]++;
                if (need[pX[u]] == 0 && can[pX[u]]) {
                    was[pX[u]] = true;
                    q.push_back(pX[u]);
                }
                continue;
            }
            if (need[u] == 0 && !was[u]) {
                q.push_back(u);
                was[u] = true;
                continue;
            }
        }
        if (ny[v] != 0) {
            assert(can[ny[v]]);
            q.push_front(ny[v]);
            was[ny[v]] = true;
        }
    }
    if (ans.size() != n + 1) {
        cout << "0\n";
        return;
    }
    for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}