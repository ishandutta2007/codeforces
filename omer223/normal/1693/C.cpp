#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

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

const int sz = 5e5;
int n, m;
vector<int> adj[sz], radj[sz]; //can be mult edges, no self loops
int indeg[sz], outdeg[sz];
ll dist[sz];
const ll INF = 1e18;
int disc[sz];

int main() {
    fast;
    cin >> n >> m;
    map<pii, int> e;
    foru(i, 0, m) {
        int x, y;
        cin >> x >> y;
        e[{--x, --y}]++;
        adj[x].push_back(y);
        radj[y].push_back(x);
        indeg[y]++;
        outdeg[x]++;
    }
    foru(i, 0, n)dist[i] = INF;
    dist[n - 1] = 0;
    vector<bool> done(n, false);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({ 0 ,  n- 1});
    while (!pq.empty()) { //my brain is frozen
        auto ii = pq.top(); pq.pop();
        ll d = ii.ff;
        int idx = ii.ss;
        if (done[idx])continue;
        done[idx] = 1;
        for (auto jj : radj[idx])disc[jj]++;
        for (auto jj : radj[idx]) {
            ll nd = d + 1 + outdeg[jj] - disc[jj];
            if (dist[jj] > nd) {
                dist[jj] = nd;
                pq.push({ nd,jj });
            }
        }
    }
    cout << dist[0] << '\n';
    return 0;
}