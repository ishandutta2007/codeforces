#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;



signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> l(n, vector<int>(m)), r(n, vector<int>(m));

    for(int i = 0;i < n;i++) {
        int k;
        cin >> k;
        while(k--) {
            int v_l, v_r;
            cin >> v_l >> v_r;
            v_l--; v_r--;

            for(int j = v_l;j <= v_r;j++) {
                l[i][j] = v_l;
                r[i][j] = v_r;
            }
        }
    }

    vector<vector<int>> dp(m, vector<int>(m));

    for(int len = 1;len <= m;len++) {
        for(int le = 0;le < m;le++) {
            int re = le + len - 1;
            if (re >= m) break;

            if (len == 1) {
                for(int i = 0;i < n;i++) {
                    if (l[i][le] == le && r[i][le] == le) dp[le][re]++;
                }
                dp[le][re] *= dp[le][re];

            }else{
                for(int i = le;i <= re;i++) {
                    int new_res = 0;
                    for(int j = 0;j < n;j++) {
                        if (l[j][i] >= le && r[j][i] <= re) new_res++;
                    }
                    new_res *= new_res;

                    if (i != le) new_res += dp[le][i - 1];
                    if (i != re) new_res += dp[i + 1][re];

                    dp[le][re] = max(dp[le][re], new_res);
                }
            }
        }
    }

    /*for(int i = 0;i < m;i++) {
        for(int j = i + 1;j < m;j++) {
            cout << i + 1 << " " << j + 1 << " " << dp[i][j] << endl;
        }
    }*/
    cout << dp[0][m - 1];
}