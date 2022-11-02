#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

const int MOD = 998244353, N = 1010;
vector<int> g[N], gr[N], arr, used(N);
int res = 0;

int add(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}

int mul(int a, int b) {
    return (1ll * a * b % MOD);
}

void dfs(int v) {
    used[v] = 1;
    for (auto to : gr[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
    arr.pb(v);
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> good(n, 1), dp(n), a(n);
        for (int i = 0; i < n; i++) {
            g[i].clear();
            gr[i].clear();
            used[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            good[a] = 0;
            g[a].pb(b);
            gr[b].pb(a);
        }
        int r = -1;
        for (int i = 0; i < n; i++) {
            if (good[i]) {
                assert(r == -1);
                r = i;
            }
        }
        arr.clear();
        dfs(r);
        dp[r] = 1;
        reverse(arr.begin(), arr.end());
        int ans = 0;
        for (auto v : arr) {
            for (auto u : gr[v]) {
                dp[u] = add(dp[u], dp[v]);
            }
            ans = add(ans, mul(dp[v], a[v]));
        }
        for (int i = 0; i < n; i++) {
            if (*max_element(a.begin(), a.end()) == 0) {
                ans = i;
                break;
            }
            if (a[r] == 0) {
                ans = add(ans, 1);
            }
            vector<int> aa = a;
            for (int v = 0; v < n; v++) {
                if (a[v] > 0) {
                    aa[v]--;
                    for (auto to : g[v]) {
                        aa[to]++;
                        aa[to] = min(aa[to], MOD);
                    }
                }
            }
            swap(a, aa);
        }
        cout << ans << endl;
    }
    return 0;
}