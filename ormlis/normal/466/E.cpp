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
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 1e5+1;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};

int dsu[maxN];

void init_dsu(int n) {
    range(i, n) dsu[i] = i;
}

int get_dsu(int a) {
    if (dsu[a] == a) return a;
    int d = get_dsu(dsu[a]);
    dsu[a] = d;
    return d;
}

void unio(int a, int b) {
    a = get_dsu(a);
    b = get_dsu(b);
    if (a == b) return;
    if (rand() % 2) swap(a, b);
    dsu[a] = b;
}

vector<int> g[maxN];
int docs = 0;
vector<pair<int, int>> req[maxN];
int getted_doc[maxN];
int ans[maxN];
int cntreqs=0;

vector<int> curreq[maxN];

void dfs(int v) {
    for(auto p: req[v]) {
        curreq[p.first].push_back(p.second);
    }
    for(auto numreq: curreq[v]) ans[numreq] = 1;
    for(auto u: g[v]) {
        dfs(u);
    }
    for(auto p: req[v]) {
        curreq[p.first].pop_back();
    }
}

int used[maxN];

vector<vector<int>> get_reqs(int m) {
    vector<vector<int>> res;
    range(i, m) {
        int t; cin >> t;
        int x; cin >> x;
        res.push_back({t, x});
        if (t != 2) {
            cin >> x;
            res.back().push_back(x);
        }
        if (t == 3) {
            res.back().push_back(cntreqs);
            cntreqs++;
        }
    }
    vector<vector<int>> res2;
    vector<vector<vector<int>>> tores3(maxN);
    range(i, m) {
        if (res[i][0] == 3) tores3[res[i][2]].push_back(res[i]);
    }
    int cnts = 1;
    range(i, m) {
        if (res[i][0] == 1) res2.push_back(res[i]);
        else if (res[i][0] == 2) {
            res2.push_back(res[i]);
            for(auto p: tores3[cnts]) res2.push_back(p);
            cnts++;
        }
    }
    return res2;
}

void solve() {
    int n, m; cin >> n >> m;
    init_dsu(n+1);
    auto reque = get_reqs(m);
    range(i, m) {
        int t = reque[i][0];
        if (t == 1) {
            int x = reque[i][1], y = reque[i][2];
            used[x] = 1;
            g[y].push_back(x);
            unio(x, y);
        }
        if (t == 2) {
            int x = reque[i][1];
            getted_doc[docs] = x;
            docs++;
        }
        if (t == 3) {
            int x = reque[i][1], j = reque[i][2];
            int e = reque[i][3];
            if (get_dsu(x) != get_dsu(getted_doc[j-1])) {
                ans[e] = 0;
            } else {
                req[x].emplace_back(getted_doc[j - 1], e);
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        if (!used[i]) dfs(i);
    }
    range(i, cntreqs) {
        if (ans[i]) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}