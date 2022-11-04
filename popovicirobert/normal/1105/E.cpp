#include <bits/stdc++.h>

using namespace std;

const int MAXM = 40;

map <string, int> mp;
bool vis[MAXM + 1];

bool bad[MAXM + 1][MAXM + 1];

int dp[1 << 20];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int cnt = 0;
    for(i = 1; i <= n; i++) {
        string str;
        int type;
        cin >> type;
        if(type == 2) {
            cin >> str;
            if(mp[str] == 0) {
                mp[str] = ++cnt;
            }
            for(int j = 1; j <= m; j++) {
                if(j != mp[str] && vis[j] == 1) {
                    bad[j - 1][mp[str] - 1] = bad[mp[str] - 1][j - 1] = 1;
                }
            }
            vis[mp[str]] = 1;
        }
        else {
            memset(vis, 0, sizeof(vis));
        }
    }
    int sz1 = m / 2, sz2 = m - sz1;
    for(int conf = 0; conf < (1 << sz2); conf++) {
        int cur = 0;
        bool flag = 1;
        for(int a = 0; a < sz2 && flag; a++) {
            if((conf & (1 << a)) == 0) {
                continue;
            }
            cur++;
            for(int b = 0; b < sz2 && flag; b++) {
                if((conf & (1 << b)) && bad[a + sz1][b + sz1] == 1) {
                    flag = 0;
                }
            }
        }
        if(flag) {
            dp[conf] = cur;
        }
    }
    for(int bit = 0; bit < sz2; bit++) {
        for(int conf = 0; conf < (1 << sz2); conf++) {
            if(conf & (1 << bit)) {
                dp[conf] = max(dp[conf], dp[conf ^ (1 << bit)]);
            }
        }
    }
    int ans = 0;
    for(int conf = 0; conf < (1 << sz1); conf++) {
        bool flag = 1;
        int cur = 0, cnf = 0;
        memset(vis, 0, sizeof(vis));
        for(int a = 0; a < sz1 && flag; a++) {
            if((conf & (1 << a)) == 0) {
                continue;
            }
            for(int b = sz1; b < m; b++) {
                if(bad[a][b] == 1) {
                    vis[b - sz1] = 1;
                }
            }
            cur++;
            for(int b = 0; b < sz1 && flag; b++) {
                if((conf & (1 << b)) == 0) {
                    continue;
                }
                if(bad[a][b]) {
                    flag = 0;
                }
            }
        }
        for(i = 0; i < sz2; i++) {
            if(vis[i] == 0) {
                cnf += (1 << i);
            }
        }
        if(flag) {
            ans = max(ans, cur + dp[cnf]);
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}