#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define double long double

//const int INF = 1000000000000000000ll;
const int mod = 1000000007;

int n, m;
vector<vector<char> > tab;
vector<vector<int> > dp;
vector<vector<int> > dp2;
//vector<vector<char> > pom;
vector<vector<char> > res;


bool foo(int ile, bool czy = false) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp2[i][j] = 0;
        }
    }
    
    for (int ii, jj, i = 1; i + 2 * ile <= n; i++) {
        for (int j = 1; j + 2 * ile <= m; j++) {
            ii = i + 2 * ile;
            jj = j + 2 * ile;
            int pole = (1 + 2 * ile) * (1 + 2 * ile);
            if (dp[ii][jj] - dp[i - 1][jj] - dp[ii][j - 1] + dp[i - 1][j - 1] == pole) {
                dp2[i][j]++;
                dp2[ii + 1][j]--;
                dp2[i][jj + 1]--;
                dp2[ii + 1][jj + 1]++;
                if (czy) {
                    res[i + ile][j + ile] = 'X';
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp2[i][j] += dp2[i - 1][j] + dp2[i][j - 1] - dp2[i - 1][j - 1];
            
            if (dp2[i][j] == 0 && tab[i][j] == 'X') {
                return false;
            }
        }
    }
    
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n + 2; i++) {
        tab.push_back(vector<char>(m + 5, '.'));
        dp.push_back(vector<int>(m + 5));
    }
    //pom = tab;
    res = tab;
    dp2 = dp;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> tab[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            if (tab[i][j] == 'X') dp[i][j]++;
        }
    }
    
    int pocz = 0, kon = n, sr;
    while (kon - pocz > 1) {
        sr = (pocz + kon) / 2;
        if (foo(sr)) pocz = sr;
        else kon = sr;
    }
    
    foo(pocz, true);
    cout << pocz << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << res[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}