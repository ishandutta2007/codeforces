#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-pointer-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int sz = 3e5;
vector<int> adj[sz];
ll dpl[sz], dpr[sz];
pll lr[sz];
int n;

void reset() {
    foru(i, 0, n)
        adj[i].clear(), dpl[i] = 0, dpr[i] = 0;
}

void dfs(int src, int prv) {
    for (int x : adj[src]) {
        if (x != prv) {
            dfs(x, src);
            dpl[src] += max(abs(lr[src].ff - lr[x].ff) + dpl[x], abs(lr[src].ff - lr[x].ss) + dpr[x]);
            dpr[src] += max(abs(lr[src].ss - lr[x].ff) + dpl[x], abs(lr[src].ss - lr[x].ss) + dpr[x]);
        }
    }
}

void solve() {
    cin >> n;
    reset();
    foru(i, 0, n)cin >> lr[i].ff >> lr[i].ss;
    foru(i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        adj[--x].push_back(--y);
        adj[y].push_back(x);
    }
    dfs(0, -1);
    cout << max(dpl[0], dpr[0]) << '\n';
}

int main() {
	fast;
    int t;
    cin >> t;
    while (t--)solve();
	return 0;
}