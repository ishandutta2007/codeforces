#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const int N = 3e5 + 10;
vector<int> g[N], dp(N), c(N), ok(N);
int cnt = 0;

void zhfs(int v, int p) {
    dp[v] = c[v];
    if (c[v] == 1) {
        ok[v] = 1;
    }
    for (auto to : g[v]) {
        if (to != p) {
            zhfs(to, v);
            dp[v] += dp[to];
        }
        if (dp[to] >= 2 || c[to] == 1) {
            ok[v] |= ok[to];
        }
    }
}

void dfs(int v, int p, bool up) {
    if (p != -1) {
        if (!(cnt - dp[v] >= 2 || c[p] == 1)) {
            up = 0;
        } else if (c[p] == 1) {
            up = 1;
        }
    }
    ok[v] |= up;
    int cnt_good = 0;
    for (auto to : g[v]) {
        if (to != p) {
            if (dp[to] >= 2 || c[to] == 1) {
                cnt_good += ok[to];
            }
        }
    }
    for (auto to : g[v]) {
        if (to != p) {
            int val = 0;
            if (dp[to] >= 2 || c[to] == 1) {
                val += ok[to];
            }
            if (cnt_good - val > 0) dfs(to, v, 1);
            else dfs(to, v, up);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        cnt += c[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    zhfs(0, -1);
    dfs(0, -1, 0);
    for (int i = 0; i < n; i++) {
        cout << ok[i] << " ";
    }
    cout << endl;
    return 0;
}