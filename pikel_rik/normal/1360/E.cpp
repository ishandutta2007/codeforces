#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int n;
string a[50];
bool ans, visited[50][50];

void dfs(int i, int j) {
    visited[i][j] = true;

    if (i > 0 and !visited[i-1][j] and a[i-1][j] == '1') dfs(i - 1, j);
    if (j > 0 and !visited[i][j-1] and a[i][j-1] == '1') dfs(i, j - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];

        memset(visited, false, sizeof(visited));

        for (int i = 0; i < n; i++) {
            if (!visited[n-1][i] and a[n-1][i] == '1')
                dfs(n - 1, i);
        }

        for (int i = 0; i < n - 1; i++) {
            if (!visited[i][n-1] and a[i][n-1] == '1')
                dfs(i, n - 1);
        }

        ans = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == '1' and !visited[i][j])
                    ans = false;
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}