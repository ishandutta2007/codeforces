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
const int N = 3e3 + 5;

int n, k, a[N], pos1, pos2, lvl[N][N];
bool visited[N][N], e;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    pos1 = -1; pos2 = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (pos1 == -1 and a[i] == 100)
            pos1 = i;
        if (pos2 == -1 and a[i])
            pos2 = i;
    }

    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }

    queue<pair<int, int>> q;
    q.emplace(0, 1);
    visited[0][1] = true;
    lvl[0][1] = 0;

    int ans = 1;

    while (!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop();

        if (i >= n or j >= n or lvl[i][j] >= k) {
            e = true;
            continue;
        }

        if (a[i] and pos2 >= j and !visited[j + 1][j + 2]) {
            q.emplace(j + 1, j + 2);
            lvl[j + 1][j + 2] = 1 + lvl[i][j];
            visited[j + 1][j + 2] = true;
            ans++;
        }

        if (a[i] != 100 and pos2 >= j and !visited[j][j + 1]) {
            q.emplace(j, j + 1);
            lvl[j][j + 1] = 1 + lvl[i][j];
            visited[j][j + 1] = true;
            ans++;
        }

        if (pos1 <= j - 1 and a[i] and !visited[i][j + 1]) {
            q.emplace(i, j + 1);
            lvl[i][j + 1] = 1 + lvl[i][j];
            visited[i][j + 1] = true;
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}