#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

int n, m;
char s[N][N];
int dp[N][N];

bool isInside(int u, int v) {
    return u >= 1 && u <= n && v >= 1 && v <= m;
}

int get(int u, int v, char c) {
    if (!isInside(u, v)) return 0;
    if (s[u][v] != c) return 0;
    return dp[u][v];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;   
    for (int i = 1; i <= n; i++) {
        cin >> (s[i] + 1);
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char u = s[i][j];
            int now = get(i - 1, j - 1, u);
            now = min(now, get(i - 1, j, u));
            now = min(now, get(i - 1, j + 1, u));
            now = min(now, get(i - 2, j, u));
            now++;
            res += now;
            dp[i][j] = now;
        }
    }
    cout << res << endl;
    return 0;
}