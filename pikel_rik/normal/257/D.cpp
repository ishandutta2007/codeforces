#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, a[N], ans[2*N];
vector<int> g[2*N];

void dfs(int x, int sign = 0) {
    if (g[x].empty()) {
        if (sign)
            ans[x] = -ans[x];
        return;
    }

    if (ans[g[x][0]] >= ans[g[x][1]]) {
        dfs(g[x][0], sign);
        dfs(g[x][1], 1 - sign);
    }
    else {
        dfs(g[x][0], 1 - sign);
        dfs(g[x][1], sign);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], ans[i] = a[i];

    priority_queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        q.emplace(a[i], i);

    int next = n - 1;
    vector<pair<int, int>> dep;

    while (q.size() > 1) {
        next++;
        auto p1 = q.top(); q.pop();
        auto p2 = q.top(); q.pop();

        g[next].push_back(p1.second);
        g[next].push_back(p2.second);
        q.emplace(abs(p1.first - p2.first), next);
        ans[next] = abs(p1.first - p2.first);
    }

    dfs(next);
    for (int i = 0; i < n; i++) {
        if (ans[i] < 0)
            cout << '-';
        else cout << '+';
    }
    cout << "\n";
    return 0;
}