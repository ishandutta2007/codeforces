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

int n, x;
vector<int> g[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        for (int i = 1; i <= 1000; i++)
            g[i].clear();

        cin >> n >> x;
        for (int i = 1; i < n; i++) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        if (g[x].size() <= 1) {
            cout << "Ayush\n";
            continue;
        }

        n -= 2;
        if (n % 2 == 0)
            cout << "Ayush\n";
        else cout << "Ashish\n";
    }
    return 0;
}