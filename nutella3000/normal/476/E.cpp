#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;
 
const int inf = 1e17 + 7;
const int mod = 1e9 + 7;



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();

    vector<int> cnt(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(n / m + 2));

    for(int i = 0;i <= n;i++) {
        int id = 0;
        cnt[i] = inf;
        for(int j = i;j < n;j++) {
            if (s[j] == t[id]) 
                id++;

            if (id == m) {
                cnt[i] = j - i + 1 - m;
                break;
            } 
        }
    }

    for(int i = n;i >= 0;i--) {
        for(int j = 0;j < n / m + 2;j++) {
            if (j == 0) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = inf;

            if (i != n) 
                dp[i][j] = dp[i + 1][j];

            if (cnt[i] != inf)
                dp[i][j] = min(dp[i][j], dp[i + m + cnt[i]][j - 1] + cnt[i]);

            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }

    vector<int> res(n + 1);
    int max_num = 0;
    for(int i = 0;i < n / m + 2;i++) {
        if (dp[0][i] < inf)
            max_num = i;
    }

    max_num = (n - max_num * m);

    for(int i = 0;i < n / m + 2;i++) {
        for(int j = dp[0][i];j <= max_num;j++) {
            res[j] = i;
        }
    }
    for(int i = max_num + 1;i <= n;i++) {
        res[i] = res[max_num] - (i - max_num + m - 1) / m;
    }

    for(int i : res) cout << i << " ";
}