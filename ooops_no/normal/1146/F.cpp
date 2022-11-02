#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int MOD = 998244353, N = 2e5 + 10;
vector<int> g[N];

int add(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}

int mul(int a, int b) {
    return (a * b % MOD);
}

int binpow(int a, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        int g = binpow(a, n / 2);
        return mul(g, g);
    } else {
        return mul(binpow(a, n - 1), a);
    }
}

int inv(int a) {
    return binpow(a, MOD - 2);
}

vector<int> dfs(int v, int p) {
    vector<int> dp(3);
    if (g[v].size() == 0) {
        return {1, 1};
    }
    dp[0] = 1;
    for (auto to : g[v]) {
        vector<int> dpp = dfs(to, v), nw(3);
        for (int i = 0; i <= 2; i++) {
            nw[i] = add(nw[i], mul(dp[i], dpp[0]));
            nw[min(i + 1, 2ll)] = add(nw[min(i + 1, 2ll)], mul(dp[i], dpp[1]));
        }
        dp = nw;
    }
    return {add(dp[0], dp[2]), add(dp[1], dp[2])};
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
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        g[p].pb(i);
    }
    vector<int> dp = dfs(0, -1);
    cout << dp[0] << endl;
    return 0;
}