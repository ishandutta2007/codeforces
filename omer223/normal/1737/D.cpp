#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

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
#include <complex>
#include <random>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;

const ll inf = 1e9;
const int sz = 5e2 + 5;
int adjm[sz][sz];
vector<pii> adj[sz];
ll dist[sz][sz];
int n, m;

void bfs(int src) {
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (pii ii : adj[x]) {
            int y = ii.ff;
            if (dist[src][y] > dist[src][x] + 1) {
                dist[src][y] = dist[src][x] + 1;
                q.push(y);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    vector<pair<pii, int>> ed;
    foru(i, 0, n) {
        adj[i].clear();
        foru(j, 0, n) {
            dist[i][j] = inf;
            adjm[i][j] = 0;
        }
    }
    foru(i, 0, m) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[--x].push_back({ --y,w });
        adj[y].push_back({ x,w });
        adjm[x][y] = adjm[y][x] = w;
        ed.push_back({ {x,y},w });
    }
    queue<pii> q;
    foru(i, 0, n) {
        foru(j, 0, n)dist[i][j] = inf;
        dist[i][i] = 0;
        bfs(i);
    }
    ll bst = 1e15;
    for (auto ii : ed) {
        int x = ii.ff.ff, y = ii.ff.ss;
        ll w = ii.ss;
        ll c = 1e9;
        c = min(c, dist[x][0] + dist[n - 1][y]);
        c = min(c, dist[x][n - 1] + dist[0][y]);
        foru(i, 0, n) {
            if (dist[i][0] + dist[i][n - 1] == dist[0][n - 1]) {
                ll ce = min(dist[x][i], dist[y][i]) + 1;
                c = min(c, ce + dist[0][n - 1]);
            }
        }
        bst = min(bst, w * (c+1));
    }
    cout << bst << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}