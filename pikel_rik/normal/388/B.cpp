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
const int N = 1e3 + 5;

vector<int> g[N];
bool adj[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int k;
    cin >> k;

    g[1] = {3, 4};
    g[3] = g[4] = {1, 5};
    g[5] = {3, 4};
    for (int i = 5; i < 92; i += 3) {
        g[i].push_back(i + 1);
        g[i].push_back(i + 2);
        g[i + 1] = g[i + 2] = {i, i + 3};
        g[i + 3] = {i + 1, i + 2};
    }

    int n;
    for (n = 0; k >> n; n++) {}
    n--;
    int last = 92, cur = 93;

    for (int i = 0; i < n; i++) {
        if (k & (1 << i)) {
            g[1].push_back(cur);
            g[cur].push_back(1);
            for (int j = 0; j < 2 * (n - i) - 1; j++) {
                g[cur].push_back(cur + 1);
                g[cur + 1].push_back(cur);
                cur++;
            }
            g[cur].push_back(last - 3 * i);
            g[last - 3 * i].push_back(cur);
            cur++;
        }
    }

    g[1].push_back(last - 3 * n);
    g[last - 3 * n].push_back(1);

    cur--;
    g[2].push_back(last);
    g[last].push_back(2);

    for (int i = 1; i <= cur; i++) {
        for (int &j : g[i]) {
            adj[i][j] = true;
            adj[j][i] = true;
        }
    }

    cout << cur << "\n";
    for (int i = 1; i <= cur; i++) {
        for (int j = 1; j <= cur; j++) {
            if (adj[i][j])
                cout << 'Y';
            else cout << 'N';
        }
        cout << "\n";
    }
    return 0;
}