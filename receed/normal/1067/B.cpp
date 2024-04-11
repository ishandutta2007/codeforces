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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int N = 100002;
vector<int> g[N];
int n, k;

int dfs(int v,  int p, int dd) {
    for (int u : g[v])
        if (u != p && dfs(u, v, dd + 1))
            return 1;
    if (g[v].size() == 1)
        return dd != k;
    if (p == -1)
        return g[v].size() < 3;
    return g[v].size() < 4;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#else
    //freopen("f.in", "r", stdin); 
    //freopen("f.out", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int u, v;
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> d(n + 1, N);
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (g[i].size() == 1) {
            d[i] = 0;
            q.push(i);
        }
    int r = -1;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        if (d[v] == k)
            r = v;
        for (int i : g[v])
            if (d[i] == N) {
                d[i] = d[v] + 1;
                q.push(i);
            }
    }
    if (r == -1 || dfs(r, -1, 0))
        printf("No");
    else
        printf("Yes");
}