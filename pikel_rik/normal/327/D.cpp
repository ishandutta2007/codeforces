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
const int N = 505;

int n, m;
string a[N];

bool visited[N][N];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

vector<vector<int>> ans;

void dfs(int i, int j) {
    visited[i][j] = true;
    ans.push_back({1, i, j});

    for (auto &k : dir) {
        int x = i + k[0], y = j + k[1];
        if (x >= 0 and x < n and y >= 0 and y < m and !visited[x][y] and a[x][y] == '.') {
            dfs(x, y);
            ans.push_back({3, x, y});
            ans.push_back({2, x, y});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] and a[i][j] == '.') {
                dfs(i, j);
            }
        }
    }

    cout << ans.size() << "\n";
    for (const auto &v : ans) {
        if (v[0] == 1) cout << "B ";
        else if (v[0] == 2) cout << "R ";
        else cout << "D ";
        cout << v[1] + 1 << " " << v[2] + 1 << "\n";
    }
    return 0;
}