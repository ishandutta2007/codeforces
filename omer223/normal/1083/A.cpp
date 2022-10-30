#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-pointer-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int sz = 5e5;
int n, w[sz];
vector<pii> adj[sz];
ll dp[sz];

void dfs(int src, int prv) {
    dp[src] = w[src];
    for (pii ii : adj[src]) {
        int x = ii.ff;
        if (x != prv) {
            dfs(x, src);
            dp[src] = max(dp[src], dp[x] - ii.ss + w[src]);
        }
    }
}

ll dfs2(int src, int prv) {
    ll ret = dp[src];
    set<ll, greater<ll>> opts;
    for (pii ii : adj[src]) {
        int x = ii.ff;
        if (x != prv) {
            ret = max(ret, dfs2(x, src));
            opts.insert(dp[x] - ii.ss);
        }
    }
    if (opts.size() <= 1)return ret;
    else {
        auto x = opts.begin();
        ll f = *x;
        x++;
        ll s = *x;
        ret = max(ret, f + s + w[src]);
        return ret;
    }
}

int main() {
    fast;
    cin >> n;
    foru(i, 0, n)cin >> w[i];
    foru(i, 0, n - 1) {
        int x, y, mw;
        cin >> x >> y >> mw;
        adj[--x].push_back({ --y,mw });
        adj[y].push_back({ x,mw });
    }
    dfs(0, -1);
    cout << dfs2(0, -1);
    return 0;
}