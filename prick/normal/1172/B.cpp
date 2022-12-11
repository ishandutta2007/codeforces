#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

const int maxn = 2e5 + 42;
const int mod = 998244353;

int fac[maxn];
int n;
vector<int> graph[maxn];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    fac[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }
    
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ans = n;
    for (int i = 1; i <= n; ++i) {
        ans *= fac[sz(graph[i])];
        ans %= mod;
    }
    
    cout << ans << '\n';
}