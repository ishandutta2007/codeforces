#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
typedef long long ll;
typedef long double ld;

using namespace std;

vector<vector<int>> g;
vector<int> used;

void dfs(int v) {
    used[v] = 1;
    for (int u : g[v])
        if (!used[u])
            dfs(u);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, q, u, v;
    scanf("%d%d%d", &n, &m, &q);
    g.resize(n + m);
    used.assign(n + m, 0);
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &u, &v);
        g[u - 1].push_back(n + v - 1);
        g[n + v - 1].push_back(u - 1);
    }
    int ans = 0;
    for (int i = 0; i < n + m; i++)
        if (!used[i]) {
            ans++;
            dfs(i);
        }
    printf("%d", ans - 1);
}