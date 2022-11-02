#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e5 + 10;
vector<int> g[N];
vector<int> l(N), r(N);
vector<int> dp_min(N), dp_max(N);

void dfs(int v, int p){
    for (auto to : g[v]){
        if (to != p){
            dfs(to, v);
            dp_min[v] += max(abs(l[v] - l[to]) + dp_min[to], abs(l[v] - r[to]) + dp_max[to]);
            dp_max[v] += max(abs(r[v] - l[to]) + dp_min[to], abs(r[v] - r[to]) + dp_max[to]);
        }
    }
}

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            g[i].clear();
            dp_min[i] = dp_max[i] = 0;
        }
        for (int i = 1; i <= n; i++){
            cin >> l[i] >> r[i];
        }
        for (int i = 0; i < n - 1; i++){
            int a, b;
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        dfs(1, -1);
        cout << max(dp_min[1], dp_max[1]) << endl;
    }
    return 0;
}