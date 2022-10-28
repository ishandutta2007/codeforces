#include <bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()

using namespace std;

vector <vector <int> > edge;
vector <ll> a;
vector <int> b, used;
vector <int> order[2];
ll ans;
inline void dfs (int v) {
    used[v] = 1;
    for (int to : edge[v]) {
        if (!used[to]) dfs(to);
    }
    ans += a[v];
    if (b[v] != -1 && a[v] > 0) {
        a[b[v]] += a[v];
    }
    if (a[v] > 0) {
        order[0].push_back(v);
    }
    else {
        order[1].push_back(v);
    }
}
inline void solve () {
    for (auto &i : edge) i.clear();
    edge.clear();
    a.clear();
    order[0].clear();
    order[1].clear();
    b.clear();
    used.clear();
    int n, x;
    cin >> n;
    edge.resize(n);
    a.resize(n);
    b.resize(n);
    for (auto &i : a) cin >> i;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x != -1) {
            --x;
            edge[x].push_back(i);
        }
        b[i] = x;
    }
    ans = 0;
    used.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    cout << ans << '\n';
    reverse(all(order[1]));
    for (auto &i : order[0]) cout << i + 1 << ' ';
    for (auto &i : order[1]) cout << i + 1 << ' ';
    cout << '\n';
}
main()
{
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}