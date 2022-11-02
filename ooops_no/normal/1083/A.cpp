#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define F first
#define S second
#define int long long
typedef long long ll;

mt19937 rnd(51);

const int N = 3e5 + 10;
vector<int> dp(N), w(N);
vector<pair<int,int>> g[N];
int ans = 0;

void dfs(int v, int p){
    dp[v] = w[v];
    vector<int> a;
    for (auto to : g[v]){
        if (to.first != p){
            dfs(to.first, v);
            a.pb(dp[to.first] - to.second);
            dp[v] = max(dp[v], w[v] + dp[to.first] - to.second);
        }
    }
    sort(a.rbegin(), a.rend());
    if (a.size() >= 2) ans = max(ans, a[0] + a[1] + w[v]);
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> w[i];
    }
    for (int i = 0; i < n - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].pb({b, c});
        g[b].pb({a, c});
    }
    dfs(0, -1);
    cout << max(ans, *max_element(dp.begin(), dp.end())) << endl;
    return 0;
}