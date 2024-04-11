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
const int N = 3e5 + 5;

int n, p[N], r[N], ans[N];
vector<int> g[N];

int find(int x) {
    if (x == p[x])
        return x;
    return p[x] = find(p[x]);
}

void union_find(int u, int v) {
    int s1 = find(u);
    int s2 = find(v);

    if (s1 == s2) return;
    if (r[s1] > r[s2]) {
        p[s2] = s1;
        ans[s1] = max(max(ans[s1], ans[s2]), (ans[s1] + 1) / 2 + 1 + (ans[s2] + 1) / 2);
    }
    else if (r[s2] > r[s1]) {
        p[s1] = s2;
        ans[s2] = max(max(ans[s2], ans[s1]), (ans[s2] + 1) / 2 + 1 + (ans[s1] + 1) / 2);
    }
    else {
        p[s2] = s1;
        ans[s1] = max(max(ans[s1], ans[s2]), (ans[s1] + 1) / 2 + 1 + (ans[s2] + 1) / 2);
        r[s1]++;
    }
}

bool visited[N];
int diameter, f1[N], f2[N];

void dfs(int x, int f) {
    p[x] = f;
    visited[x] = true;

    int temp1 = -1, temp2 = -1;

    for (int &i : g[x]) {
        if (visited[i]) continue;
        dfs(i, f);

        if (f1[i] >= temp1) {
            temp2 = temp1;
            temp1 = f1[i];
        }
        else if (f1[i] > temp2)
            temp2 = f1[i];
    }

    f1[x] = 1 + temp1;
    if (temp2 != -1)
        f2[x] = 2 + temp1 + temp2;
    diameter = max(diameter, max(f1[x], f2[x]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            diameter = 0;
            dfs(i, i);

            ans[i] = diameter;
            if (g[i].empty())
                r[i] = 1;
            else r[i] = 2;
        }
    }

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int x;
            cin >> x;

            cout << ans[find(x)] << "\n";
        }
        else {
            int x, y;
            cin >> x >> y;
            union_find(x, y);
        }
    }
    return 0;
}