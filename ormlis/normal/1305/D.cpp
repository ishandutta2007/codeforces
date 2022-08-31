#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 1001;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};

unordered_set<int> g[maxN];
int deleted[maxN];

vector<int> cur;
int lca(int u, int v) {
    cout << "? " << u << " " << v << endl;
    int w; cin >> w;
    return w;
}


void delt(int v) {
    deleted[v] = 1;
}

void get_path(int v, int p, vector<int> &path, int find) {
    if (path.empty() || path.back() != find) path.push_back(v);
    for(auto u: g[v]) {
        if (u == p || deleted[u]) continue;
        get_path(u, v, path, find);
    }
    if (path.empty() || path.back() != find) path.pop_back();
}

void del_path(int v1, int v2) {
    vector<int> path;
    get_path(v1, -1, path, v2);
    range(i, path.size() - 1) {
        delt(path[i]);
    }
}

void upd_cur(int v, int p) {
    cur.push_back(v);
    for(auto u: g[v]) {
        if (u == p || deleted[u]) continue;
        upd_cur(u, v);
    }
}

bool tried(int v1, int v2) {
    if (g[v1].find(v2) != g[v1].end()) return false;
    int w = lca(v1, v2);
    del_path(v1, w);
    del_path(v2, w);
    cur.clear();
    upd_cur(w, -1);
    return true;
}

void solve() {
    int n; cin >> n;
    range(i, n-1) {
        int x, y; cin >> x >> y;
        g[x].insert(y);
        g[y].insert(x);
    }
    range(i, n) cur.push_back(i+1);
    while(cur.size() > 2) {
        int v0 = cur.back();
        cur.pop_back();
        int v1 = cur.back();
        cur.pop_back();
        int v2 = cur.back();
        cur.pop_back();
        if (tried(v1, v2) || tried(v2, v0) || tried(v1, v0)) {
            continue;
        }
    }
    if (cur.size() == 1) {
        cout << "! " <<  cur.back();
    } else {
        int w = lca(cur[0], cur[1]);
        cout << "! " << w;
    }
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
    int tests=1;
    range(_, tests) {
        solve();
    }
    return 0;
}