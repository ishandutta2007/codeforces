#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e9 + 7;
const int N = 2e5 + 3;

int n, k, x, y;
int a[N];
vector<int> gr[N];
int par[N], dp[N], cnt[N], tin[N], tout[N], T = 0;

void dfs(int v, int pr = -1) {
    tin[v] = T++;

    par[v] = pr;
    dp[v] = 0;
    cnt[v] = a[v];
    for (int to : gr[v]) {
        if (to == pr) continue;
        dfs(to, v);
        dp[v] += dp[to] + 2;
        cnt[v] += cnt[to];
    }
    if (dp[v] == 0 && !a[v]) dp[v] = -2;

    tout[v] = T++;
}


void run() {
    cin >> n >> k >> x >> y; --x, --y;
    for (int i = 0; i < n; ++i) {
        a[i] = 0; gr[i].clear();
    }
    for (int i = 0; i < k; ++i) {
        int val; cin >> val; a[val-1] = 1;
    }
    for (int i = 0; i < n-1; ++i) {
        int v1, v2; cin >> v1 >> v2; --v1, --v2;
        gr[v1].eb(v2); gr[v2].eb(v1);
    }
    
    T = 0;
    dfs(y);
    
    int res = 0, lst = -1;
    while (x != -1) {
        for (int to : gr[x]) {
            if (to != par[x] && to != lst) {
                res += 2 + dp[to];
            }
        }
        lst = x;
        x = par[x];
        ++res;
    }
    cout << res-1 << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}