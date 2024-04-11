#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define ll long long
#define pb push_back
#define ld long double

const int N = 1e6 + 10;
int bal = 0;
vector<int> g[N], mt(N, -1);
vector<bool> used(N);

bool dfs(int v) {
    if (used[v]) return 0;
    used[v] = 1;
    shuffle(g[v].begin(), g[v].end(), rnd);
    for (auto to : g[v]) {
        if (mt[to] == -1) {
            mt[to] = v;
            return 1;
        }
    }
    for (auto to : g[v]) {
        if (dfs(mt[to])) {
            mt[to] = v;
            return 1;
        }
    }
    return 0;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), u;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 1; j <= n; j++) {
            u.pb(a[i] * j);
        }
    }
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            int pos = lower_bound(u.begin(), u.end(), a[i] * j) - u.begin();
            g[pos].pb(i);
        }
    }
    int cnt = 0;
    ll ans = 0;
    for (int i = 0; i < u.size(); i++) {
        bal++;
        if (dfs(i)) {
            ans += u[i];
            cnt++;
            for (int j = 0; j < u.size(); j++) {
                used[j] = 0;
            }
        }
    }
    assert(cnt == n);
    cout << ans << endl;
    return 0;
}