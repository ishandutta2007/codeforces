#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5 + 10;
vector<int> g[N];
vector<bool> used(N);
vector<int> d(N, 1);
int ans = 0;

int dfs(int v){
    used[v] = 1;
    vector<int> a;
    for (auto to : g[v]){
        if (!used[to]){
            a.pb(dfs(to));
        }
    }
    if (a.size() == 0) return 1;
    sort(a.begin(), a.end());
    if (a.size() > 1){
        if (v == 1) ans = max({ans, a[a.size() - 1], a[a.size() - 2] + 1});
        else ans = max(ans, a[a.size() - 1] + 1);
    }
    ans = max(ans, a[0]);
    return a[0] + 1;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            used[i] = 0;
            g[i].clear();
        }
        for (int i = 0; i < n - 1; i++){
            int a, b;
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        ans = 0;
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}