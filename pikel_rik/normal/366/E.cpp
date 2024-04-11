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
const int N = 2000 + 5;
const int S = 1e5 + 5;

int n, m, k, s, q[S], dist[10][10];
pair<int, int> pos[10][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k >> s;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            pos[i][j].first = INT_MAX;
            pos[i][j].second = INT_MIN;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int num;
            cin >> num;
            pos[num][i].first = min(pos[num][i].first, j);
            pos[num][i].second = max(pos[num][i].second, j);
        }
    }

    for (int i = 0; i < s; i++)
        cin >> q[i];

    for (int x = 1; x <= k; x++) {
        for (int y = x; y <= k; y++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (pos[x][i].first == INT_MAX or pos[y][j].first == INT_MAX) continue;
                    dist[x][y] = max(dist[x][y], abs(i - j) + abs(pos[x][i].first - pos[y][j].first));
                    dist[x][y] = max(dist[x][y], abs(i - j) + abs(pos[x][i].first - pos[y][j].second));
                    dist[x][y] = max(dist[x][y], abs(i - j) + abs(pos[x][i].second - pos[y][j].first));
                    dist[x][y] = max(dist[x][y], abs(i - j) + abs(pos[x][i].second - pos[y][j].second));
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i < s; i++) {
        if (q[i - 1] <= q[i])
            ans = max(ans, dist[q[i - 1]][q[i]]);
        else ans = max(ans, dist[q[i]][q[i - 1]]);
    }

    cout << ans << "\n";
    return 0;
}