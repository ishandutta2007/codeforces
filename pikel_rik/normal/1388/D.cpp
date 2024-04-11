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
const int N = 2e5 + 5;

ll n, a[N], b[N];
vector<int> v, g[N];

bool visited[N];

void dfs(int x) {
    visited[x] = true;

    for (int &i : g[x]) {
        if (!visited[i])
            dfs(i);
    }
    v.push_back(x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i <= n; i++) {
        if (b[i] != -1) {
            g[i].push_back(b[i]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            dfs(i);
    }

    ll score = 0;
    reverse(all(v));

    vector<int> ans, ans1;
    for (int i : v) {
        if (a[i] >= 0) {
            score += a[i];
            if (b[i] != -1)
                a[b[i]] += a[i];
            ans.push_back(i);
        }
        else {
            score += a[i];
            ans1.push_back(i);
        }
    }

    cout << score << "\n";
    for (int i : ans) cout << i << " ";

    reverse(all(ans1)); for (int i : ans1) cout << i << " ";
    cout << "\n";
    return 0;
}