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

int n, m;
string a[50];

bool visited[50][50];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int i, int j) {
    visited[i][j] = true;

    for (int k = 0; k < 4; k++) {
        int x = i + dir[k][0], y = j + dir[k][1];
        if (x < 0 or x >= n or y < 0 or y >= m or a[x][y] == '#' or visited[x][y]) continue;
        dfs(x, y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        for (int i = 0; i < 50; i++) for (int j = 0; j < 50; j++) visited[i][j] = false;

        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> a[i];

        bool flag = false;
        for (int i = 0; i < n and !flag; i++) {
            for (int j = 0; j < m and !flag; j++) {
                if (a[i][j] == 'G') {
                    if (i > 0 and a[i-1][j] == 'B')
                        flag = true;
                    if (j > 0 and a[i][j-1] == 'B')
                        flag = true;
                    if (i + 1 < n and a[i+1][j] == 'B')
                        flag = true;
                    if (j + 1 < m and a[i][j+1] == 'B')
                        flag = true;
                }
            }
        }

        if (flag) {
            cout << "No\n";
            continue;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'B') {
                    if (i > 0 and a[i-1][j] == '.')
                        a[i - 1][j] = '#';
                    if (j > 0 and a[i][j-1] == '.')
                        a[i][j - 1] = '#';
                    if (i + 1 < n and a[i+1][j] == '.')
                        a[i + 1][j] = '#';
                    if (j + 1 < m and a[i][j+1] == '.')
                        a[i][j + 1] = '#';
                }
            }
        }

        if (a[n-1][m-1] == '.')
            dfs(n - 1, m - 1);

        flag = false;
        bool flag1 = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'G')
                    flag |= (!visited[i][j]), flag1 = true;
            }
        }

        flag |= (flag1 and !visited[n-1][m-1]);

        if (flag) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}