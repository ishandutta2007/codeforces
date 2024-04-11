#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstring>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second

using namespace std;

int n, u, v;
vector <vector <int> > graph;
vector <bool> init, goal, used;
vector <int> ans;

int dfs(int v, bool inv1, bool inv2, int d) {
    //cout << v << endl;
    used[v] = true;
    if (d % 2) {
        if (inv1 ^ (init[v] ^ goal[v])) {
            inv1 = !inv1;
            ans.puba(v);
        }
    } else {
        if (inv2 ^ (init[v] ^ goal[v])) {
            inv2 = !inv2;
            ans.puba(v);
        }
    }
    
    for (int i = 0; i < (int) graph[v].size(); ++i) {
        if (!used[graph[v][i]]) {
            dfs(graph[v][i], inv1, inv2, d + 1);
        }
    }
    return 0;
}

int main() {
    cin >> n;
    graph.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        //cout << i << " " << u << " " << v << endl;
        --u;
        --v;
        graph[v].puba(u);
        graph[u].puba(v);
    }                    
    
    used.resize(n);
    
    int num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        init.puba(num);
    }
    for (int i = 0; i < n; ++i) {
        cin >> num;
        goal.puba(num);
    }
    
    dfs(0, false, false, 0);  
    cout << ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); ++i) {
        cout << ans[i] + 1 << endl;
    }

    return 0;
}