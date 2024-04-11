#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int N = 1e3 + 10;
vector<int> mt(N, -1), g[N];
vector<bool> used(N);

bool dfs(int v) {
    if (used[v]) return 0;
    used[v] = 1;
    for (auto to : g[v]) {
        if (mt[to] == -1 || dfs(mt[to])) {
            mt[to] = v;
            mt[v] = to;
            return 1;
        }
    }
    return 0;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LCOAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> t(n), was(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    sort(t.rbegin(), t.rend());
    for (int i = 0; i < n && t[i] > m / 3; i++) {
        for (int j = n - 1; j >= 0 && t[j] <= m / 3; j--) {
            if (t[i] % t[j] == 0 && t[i] * 2 + t[j] <= m) {
                g[i].pb(j);
            }
        }
    }
    for (int i = 0; i < n && t[i] > m / 3; i++) {
        fill(used.begin(), used.end(), 0);
        if (!dfs(i)) {
            cout << -1 << endl;
            return 0;
        }
    }
    vector<pair<int,int>> ans;
    for (int i = 0; i < n && t[i] > m / 3; i++) {
        int j = mt[i];
        was[i] = was[j] = 1;
        ans.pb({t[i] * 2 + t[j], t[i] + t[j]});
    }
    for (int i = 0; i < n; i++) {
        if (!was[i]) {
            ans.pb({t[i] * 2, t[i] * 3});
        }
    }
    cout << ans.size() << endl;
    for (auto to : ans) {
        cout << to.first << ' ' << to.second << endl;
    }
    return 0;
}