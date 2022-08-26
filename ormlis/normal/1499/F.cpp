#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

typedef long long ll;

using namespace std;
//using namespace __gnu_pbds;

const int INFi = 2e9 + 5;
const int maxN = 5e3 + 5;
const int md = 998244353;
const ll INF = 2e18;

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

vector<int> g[maxN];
int k;

vector<int> merge_dp(vector<int> &a, vector<int> &b) {
    vector<int> c(k + 1);
    int sb = 0;
    int l = 0, r = -1;
    for (int i = k; i >= 0; --i) {
        int j = k - i;
        if (j <= i) {
            sb = add(sb, b[j]);
            r = j;
        }
        while(r > i) {
            sb = sub(sb, b[r]);
            r--;
        }
        c[i] = add(c[i], mul(a[i], sb));
    }
    sb = 0;
    l = 0, r = -1;
    for (int j = k; j >= 0; --j) {
        int i = k - j;
        if (i < j) {
            sb = add(sb, a[i]);
            r = i;
        }
        while(r >= j) {
            sb = sub(sb, a[r]);
            r--;
        }
        c[j] = add(c[j], mul(b[j], sb));
    }
    return c;
}

vector<int> dfs(int v, int p) {
    vector<int> dp(k + 1);
    dp[0] = 1;
    for (auto &u : g[v]) {
        if (u == p) continue;
        auto b = dfs(u, v);
        auto c = merge_dp(dp, b);
        swap(dp, c);
    }
    vector<int> res(k + 1);
    range(i, k + 1) res[0] = add(res[0], dp[i]);
    range(i, k) res[i + 1] = dp[i];
    return res;
}

void solve() {
    int n; cin >> n >> k;
    range(_, n - 1) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dp(k + 1);
    dp[0] = 1;
    for(auto &u : g[1]) {
        auto b = dfs(u, 1);
        auto c = merge_dp(dp, b);
        swap(dp, c);
    }
    int answer = 0;
    range(i, k + 1) answer = add(answer, dp[i]);
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}