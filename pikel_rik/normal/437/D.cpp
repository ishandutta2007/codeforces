#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ordered_set = tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 1;

int n, p[N], r[N], val[N];
vector<int> g[N];
pair<int, int> a[N];

int find(int x) {
    if (x != p[x])
        return p[x] = find(p[x]);
    return x;
}

ll total = 0;

void union_find(int x, int y) {
    int s1 = find(x), s2 = find(y);
    if (s1 == s2) return;

    if (r[s1] >= r[s2]) {
        p[s2] = s1;
        total += r[s1] * (ll)r[s2] * min(val[x], val[y]);
        r[s1] += r[s2];
    }
    else {
        p[s1] = s2;
        total += r[s1] * (ll)r[s2] * min(val[x], val[y]);
        r[s2] += r[s1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;

        val[i] = a[i].first;
        p[i] = i; r[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    sort(a + 1, a + n + 1, greater<>());

    for (int i = 1; i <= n; i++) {
        int u = a[i].second;
        for (int &v : g[u]) {
            if (val[v] >= val[u]) {
                union_find(v, u);
            }
        }
    }

    cout << fixed << setprecision(10);
    cout << ((double)total * 2) / ((double)n * (n - 1)) << "\n";
    return 0;
}