#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define rep(i, k, n) foru(i, k, n)
#define sz(a) (int)(a.size())

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <numeric>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;


const int sz = 5e5 + 5;
int n, m;
vector<pii> adj[sz];
int ans[sz];
vector<pii> ed;

void reset() {
    ed.clear();
    foru(i, 0, n)adj[i].clear();
}
bitset<sz> vis;
vector<int> be;

void dfs(int src, int prv) {
    vis[src] = 1;
    for (pii ii : adj[src]) {
        if (ii.ff == prv)continue;
        else if (vis[ii.ff]) {
            be.push_back(ii.ss);
        }
        else {
            dfs(ii.ff, src);
        }
    }
}

void solve() {
    cin >> n >> m;
    reset();
    foru(i, 0, m) {
        ans[i] = 0;
        int x, y;
        cin >> x >> y;
        adj[--x].push_back({ --y,i });
        adj[y].push_back({ x,i });
        ed.push_back({ x,y });
    }
    std::random_device rd;
    std::mt19937 g(rd());
    while (true) {
        foru(i, 0, n)std::shuffle(adj[i].begin(), adj[i].end(), g);
        int rt = g() % n;
        foru(i, 0, n)vis[i] = 0;
        be.clear();
        dfs(rt, -1);
        set<int> ep;
        for (int idx : be) {
            ep.insert(ed[idx].ff);
            ep.insert(ed[idx].ss);
        }
        if (ep.size() > 3 || m < n + 2)break;
    }
    foru(i, 0, m)ans[i] = 0;
    for (int i : be)ans[i] = 1;
    foru(i, 0, m)cout << ans[i];
    cout << '\n';
}

int main() {
    srand(time(NULL));
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}