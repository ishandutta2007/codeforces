#include <bits/stdc++.h>

using namespace std;
#define int long long
#define loop1(from, n) for(int i = from; i < n;i++)
#define loop2(from, n) for(int i = from;i >= n;i--)
const int inf = 1e9 + 7;
int32_t main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    string s[n];
    for(int i = 0;i < n;i++) cin >> s[i];
    int x = -1;
    int y = -1;
    for(int i = 1;i < n - 1;i++) {
        for(int j = 1;j < m - 1;j++) {
            if (s[i][j] == '*' && s[i  -1][j] == '*' && s[i + 1][j] == '*' && s[i][j - 1] == '*' && s[i][j + 1] == '*') {
                x = i;
                y = j;
            }
        }
    }
    if (x == -1) {
        cout << "NO";
        return 0;
    }
    bool used[n][m];
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) used[i][j] = false;
    }
    for(int i = x - 1;i >= 0;i--) {
        if (s[i][y] == '*') {
            used[i][y] = true;
        }else break;
    }
    for(int i = x + 1;i < n;i++) {
        if (s[i][y] == '*') {
            used[i][y] = true;
        }else break;
    }
    for(int j = y - 1;j >= 0;j--) {
        if (s[x][j] == '*') {
            used[x][j] = true;
        } else break;
    }
    for(int j = y + 1;j < m;j++) {
        if (s[x][j] == '*') {
            used[x][j] = true;
        }else break;
    }
    used[x][y] = true;
    bool ans = true;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if (!used[i][j] && s[i][j] == '*') ans = false;
        }
    }
    if (ans) {
        cout << "YES";
    }else cout << "NO";
}