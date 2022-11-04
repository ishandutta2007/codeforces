#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9;
const ll LINF = (ll) 1e18 + 1;
const ld EPS = 1e-9;

const int N = (int) 2e5 + 123;
const int L = (int) log2(N) + 2;

int n;
int a[N], dp[N], ans[N];
vector<int> g[N];
pair<int, ll> up[N][L];

void dfs(int v) {
    for (int i = 1; i < L; i++) {
        up[v][i].first = up[up[v][i - 1].first][i - 1].first;
        up[v][i].second = up[v][i - 1].second + up[up[v][i - 1].first][i - 1].second;
    }
    
    for (int u : g[v]) {
        dfs(u);
    }
}

int solve(int v) {
    int res = 0;
    
    for (int u : g[v]) {
        res += solve(u);
    }
        
    ans[v] = res;
    res++;
    res += dp[v];
    return res;
}

void run() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int p, w;
        cin >> p >> w;
        p--;
        g[p].push_back(i);
        up[i][0] = {p, w};
    }
    
    dfs(0);
    
    for (int i = 0; i < n; i++) {
        int v = i;
        ll cur_sum = 0;
        
        for (int j = L - 1; j >= 0; j--) {
            ll nsum = cur_sum + up[v][j].second;
            if (nsum <= a[i]) {
                cur_sum = nsum;
                v = up[v][j].first;
            }
        }
        
        dp[v]--;
    }
    
    solve(0);
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}