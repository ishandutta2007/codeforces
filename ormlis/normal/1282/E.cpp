#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <cstring>
#include <map>
#include <bitset>
#include <iomanip>
#include <bits/unordered_set.h>

#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

struct Triple {
    int a = 0, b = 0, c = 0;
};

bool comp(Triple &a, Triple &b) {
    if (a.a != b.a) return a.a < b.a;
    if (a.b != b.b) return a.b < b.b;
    return a.c < b.c;
}


vector<unordered_set<int>> g;

void add_edge(int &a, int &b) {
    if(g[a].find(b) != g[a].end()) {
        g[b].erase(a);
        g[a].erase(b);
    } else {
        g[a].insert(b);
        g[b].insert(a);
    }
}

vector<int> used;
vector<int> ans;

void dfs(int v) {
    used[v] = 1;
    ans.emplace_back(v);
    for(auto u: g[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}

void solve() {
    int n; cin >> n;
    g.clear(); used.clear(); g.resize(n + 1); used.resize(n + 1); ans.clear();
    vector<int> q; vector<Triple> arr(n + 1); vector<ll> vertexes(n + 1, 0);
    for(int i = 1; i <= n - 2; ++i) {
        int a, b ,c;
        cin >> a >> b >> c;
        arr[i] = {a, b, c};
        vertexes[a] += n + i;
        vertexes[b] += n + i;
        vertexes[c] += n + i;
        add_edge(a, b);
        add_edge(a, c);
        add_edge(b, c);
    }
    for(int i = 1; i <= n; ++i) {
        if (vertexes[i] < 2 * n + 1) {
            q.push_back(i);
        }
    }
    vector<int> ans2; vector<int> used2(n + 1, 0);
    range(i, n - 2) {
        int u = q.back();
        used2[u] =  1;
        q.pop_back();
        vertexes[u] -= n;
        int p = vertexes[u];
        ans2.push_back(p);
        if (!used2[arr[p].a]) {
            vertexes[arr[p].a] -= p + n;
            if (vertexes[arr[p].a] < 2 * n + 1) {
                q.push_back(arr[p].a);
            }
        }
        if (!used2[arr[p].b]) {
            vertexes[arr[p].b] -= p + n;
            if (vertexes[arr[p].b] < 2 * n + 1) {
                q.push_back(arr[p].b);
            }
        }
        if (!used2[arr[p].c]) {
            vertexes[arr[p].c] -= p + n;
            if (vertexes[arr[p].c] < 2 * n + 1) {
                q.push_back(arr[p].c);
            }
        }
    }
    dfs(1);
    for(auto a: ans) {
        cout << a << ' ';
    }
    cout << '\n';
    for(auto a: ans2) {
        cout << a << ' ';
    }
    cout << '\n';
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tests;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}