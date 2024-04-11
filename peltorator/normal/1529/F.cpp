#ifdef ONPC
    #define _GLIBCXX_DEBUG
    #define deb(a) cerr << "@@@@@@@ " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
#define char unsigned char

using namespace std;
mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    int m;
    cin >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    for (int i = 0; i < n; i++) {
        sort(g[i].begin(), g[i].end());
        int bst = 0;
        for (int j = 1; j < sz(g[i]); j++) {
            if (g[i][j].second < g[i][bst].second) {
                bst = j;
            }
        }
        rotate(g[i].begin(), g[i].begin() + bst, g[i].end());
        int curpos = g[i][0].first;
        int curcost = g[i][0].second;
        vector<pair<int, int>> nw;
        nw.push_back(g[i][0]);
        for (int j = 1; j < sz(g[i]); j++) {
            while (curpos != g[i][j].first) {
                curpos = (curpos + 1) % n;
                curcost++;
            }
            if (g[i][j].second < curcost) {
                nw.push_back(g[i][j]);
                curcost = g[i][j].second;
            }
        }
        g[i] = nw;
    }
    for (int i = 0; i < n; i++) {
        vector<ll> dist(n, 1e18);
        dist[i] = 0;
        set<pair<ll, int>> q;
        for (auto [b, c] : g[i]) {
            for (int z = 0; z <= 1; z++) {
                int u = (b + z) % n;
                if (dist[u] > c + z) {
                    q.erase({dist[u], u});
                    dist[u] = c + z;
                    q.insert({dist[u], u});
                }
            }
        }
        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());
            for (auto [b, c] : g[v]) {
                for (int z = 0; z <= 1; z++) {
                    int u = (b + dist[v] + z) % n;
                    if (dist[u] > dist[v] + c + z) {
                        q.erase({dist[u], u});
                        dist[u] = dist[v] + c + z;
                        q.insert({dist[u], u});
                    }
                }
            }
            for (int z = 1; z <= 2; z++) {
                int u = (z + v) % n;
                if (dist[u] > dist[v] + z) {
                    q.erase({dist[u], u});
                    dist[u] = dist[v] + z;
                    q.insert({dist[u], u});
                }
            }
        }
        for (int j = 0; j < n; j++) {
            cout << dist[j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    //cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}