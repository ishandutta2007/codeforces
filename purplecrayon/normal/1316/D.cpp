#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e3+10, MOD = 998244353;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dc[4] = {'D', 'R', 'U', 'L'};

int n;
ar<int, 2> a[N][N];
string ans[N];

void dfs(int i, int j) {
    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni < 0 || ni >= n || nj < 0 || nj >= n || ans[ni][nj] != '?' || a[ni][nj] != a[i][j]) continue;
        ans[ni][nj] = dc[(k + 2) % 4];
        dfs(ni, nj);
    }
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) ans[i] = string(n, '?');
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ar<int, 2> c; for (auto& x : c) cin >> x, x = max(-1, x-1);
            a[i][j] = c;

            if (c[0] != -1) 
                ans[c[0]][c[1]] = 'X';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((ans[i][j] == 'X') != (a[i][j] == ar<int, 2>{i, j})) {
                cout << "INVALID\n";
                return;
            }
            if (a[i][j] == ar<int, 2>{-1, -1}) {
                bool bad = 1;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= n || a[ni][nj] != ar<int, 2>{-1, -1}) continue;
                    ans[i][j] = dc[k], bad = 0;
                    break;
                }
                if (bad) {
                    cout << "INVALID\n";
                    return;
                }
                continue;
            }
            if (ans[i][j] == 'X') {
                dfs(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) for (auto c : ans[i]) if (c == '?') {
        cout << "INVALID\n";
        return;
    }

    cout << "VALID\n";
    for (int i = 0; i < n; i++) cout << ans[i] << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}