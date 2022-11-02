#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll __int128

mt19937 rnd(51);

const int N = 1e5 + 10;
vector<int> par(N);
vector<pair<int,int>> g[N];
vector<int> mp[N];

int find_set(int v) {
    if (v == par[v]) {
        return v;
    } else {
        return par[v] = find_set(par[v]);
    }
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    par[b] = a;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> arr(m);
    for (int i = 0; i < m; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        arr[i][0]--, arr[i][1]--;
        g[arr[i][0]].pb({arr[i][1], arr[i][2]});
        g[arr[i][1]].pb({arr[i][0], arr[i][2]});
    }
    int q;
    cin >> q;
    vector<pair<int,int>> u(q);
    vector<int> ans(q, 2);
    for (int i = 0; i < q; i++) {
        cin >> u[i].first >> u[i].second;
        u[i].first--, u[i].second--;
    }
    for (int j = 0; j < 30; j++) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
        for (int i = 0; i < m; i++) {
            if (arr[i][2] & (1 << j)) {
                union_set(arr[i][0], arr[i][1]);
            }
        }
        for (int i = 0; i < q; i++) {
            if (find_set(u[i].first) == find_set(u[i].second)) {
                ans[i] = 0;
            }
        }
    }
    for (int j = 1; j < 30; j++) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
        for (int i = 0; i < m; i++) {
            if ((arr[i][2] & 1) && (arr[i][2] & (1 << j))) {
                union_set(arr[i][0], arr[i][1]);
            }
        }
        for (int i = 0; i < n; i++) mp[i].clear();
        map<int,int> good;
        for (int i = 0; i < n; i++) {
            mp[find_set(i)].pb(i);
        }
        for (int i = 0; i < n; i++) {
            for (auto v : mp[i]) {
                for (auto edge : g[v]) {
                    if (!(edge.second & 1)) {
                        good[i] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < q; i++) {
            if (good[find_set(u[i].first)]) {
                ans[i] = min(ans[i], 1);
            }
        }
    }
    for (auto to : ans) {
        cout << to << endl;
    }
    return 0;
}