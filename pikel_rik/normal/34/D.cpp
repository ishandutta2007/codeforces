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
const int N = 5e4 + 5;

int n, r1, r2, p[N], newp[N];
vector<int> g[N];

void dfs(int x, int p = -1) {
    newp[x] = p;
    for (int &i : g[x]) {
        if (i == p) continue;
        dfs(i, x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> r1 >> r2;
    for (int i = 1; i <= n; i++) {
        if (i == r1) continue;
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++) {
        if (i == r1) continue;

        g[i].push_back(p[i]);
        g[p[i]].push_back(i);
    }

    dfs(r2);
    for (int i = 1; i <= n; i++) {
        if (i == r2) continue;
        cout << newp[i] << " ";
    }
    return 0;
}