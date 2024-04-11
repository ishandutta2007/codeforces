#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

struct Edge {
    int to, cost;
};

int n;
vector<vector<Edge>> graph;

int good, bad;

int solve_bad(int v, int p) {
    int sumsize = 1;
    for (auto e: graph[v]) {
        if (e.to == p) continue;
        int size = solve_bad(e.to, v);
        bad += e.cost * min(size, n - size);
        sumsize += size;
    }
    return sumsize;
}

bool solve_good(int v, int p) {
    bool odd = true;
    for (auto e: graph[v]) {
        if (e.to == p) continue;
        if (solve_good(e.to, v)) {
            good += e.cost;
            odd = !odd;
        }
    }
    return odd;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int T;
    cin >> T;
    for (int it = 0; it < T; ++it) {
        graph.clear();
        int k;
        cin >> k;
        n = k * 2;
        graph.resize(n + 1);
        for (int i = 1; i < n; ++i) {
            int a, b, cost;
            cin >> a >> b >> cost;
            graph[a].push_back({b, cost});
            graph[b].push_back({a, cost});
        }
        
        good = bad = 0;
        solve_good(1, -1);
        solve_bad(1, -1);
        cout << good << ' ' << bad << '\n';
    }
}