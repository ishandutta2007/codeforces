#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 2e5 + 10;
vector<int> g[N];
vector<int> h(N);
int ans = 0;

int dfs(int v, int p) {
    multiset<int> u;
    for (auto to : g[v]) {
        if (to != p) {
            u.insert(dfs(to, v));
        }
    }
    if (u.size() == 0) {
        ans += h[v];
        return h[v];
    }
    if (p == -1 && u.size() > 1) {
        auto it = *u.rbegin();
        ans += h[v] - it;
        u.erase(u.find(it));
        it = *u.rbegin();
        ans += h[v] - it;
        return -1;
    }
    if (p == -1) ans += h[v];
    int mx = *u.rbegin();
    if (mx >= h[v]) return mx;
    else {
        ans += h[v] - mx;
        return h[v];
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    int r = 0;
    for (int i = 1; i < n; i++) {
        if (h[i] > h[r]) {
            r = i;
        }
    }
    dfs(r, -1);
    cout << ans << endl;
    return 0;
}