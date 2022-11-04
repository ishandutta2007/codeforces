#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 43

using namespace std;

const int MAXN = 100;

vector < pair <int, int> > g[MAXN + 1];

int dp[MAXN + 1][MAXN + 1][26];

int solve(int x, int y, int val) {
    int mx = -1;
    if(dp[x][y][val] != -1)
        return dp[x][y][val];
    for(auto it : g[x])
        mx = max(mx, it.second);
    if(mx < val)
        return dp[x][y][val] = 0;
    for(auto it : g[x]) {
        if(it.second >= val)
            dp[x][y][val] = max(1 - solve(y, it.first, it.second), dp[x][y][val]);
    }
    return dp[x][y][val];
}

int main() {
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    int i, j, n, m, x, y;
    char ch;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= m; i++) {
        cin >> x >> y >> ch;
        g[x].push_back({y, ch - 'a'});
    }
    memset(dp, -1, sizeof(dp));
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            int ans = solve(i, j, 0);
            if(ans == 1)
                cout << "A";
            else
                cout << "B";
        }
        cout << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}