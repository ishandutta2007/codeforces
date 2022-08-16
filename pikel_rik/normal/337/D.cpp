#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 5;

int n, m, d, p[N], distD[N], distU[N];
vector<int> g[N];

bool mark[N];

void dfs1(int x = 1, int par = 0) {
    distD[x] = -inf;
    if (mark[x]) distD[x] = 0;

    for (int &i : g[x]) {
        if (i == par) continue;
        dfs1(i, x);
        if (distD[i] != -inf)
            distD[x] = max(distD[x], distD[i] + 1);
    }
}

void dfs(int x = 1, int par = 0, int max1 = -inf, int max2 = -inf) {
    distU[x] = -inf;
    if (mark[par]) distU[x] = 1;

    if (par) {
        if (distD[x] < max1)
            distU[x] = max(distU[x], max1 + 2);
        else if (max2 != -inf)
            distU[x] = max(distU[x], max2 + 2);

        if (distU[par] != -inf)
            distU[x] = max(distU[x], distU[par] + 1);
    }

    int temp1 = -inf, temp2 = -inf;
    for (int &i : g[x]) {
        if (i == par) continue;
        if (distD[i] > temp1) {
            temp2 = temp1;
            temp1 = distD[i];
        }
        else if (distD[i] > temp2) {
            temp2 = distD[i];
        }
    }

    for (int &i : g[x]) {
        if (i == par) continue;
        dfs(i, x, temp1, temp2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> d;
    for (int i = 0; i < m; i++) {
        cin >> p[i];
        mark[p[i]] = true;
    }

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs1();
    dfs();

    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (distD[i] <= d and distU[i] <= d)
            c++;
    }

    cout << c << "\n";
    return 0;
}