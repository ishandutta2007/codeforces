#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 2000

using namespace std;

string a, b;
int m, d;


int dp[MAXN + 1][MAXN + 1][2];

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline int check(string a) {
    int i, j, cif;
    memset(dp, 0, sizeof(dp));
    for(i = 0; i < a.size(); i++)
        a[i] -= '0';
    a.push_back(0);
    for(i = a.size() - 1; i > 0; i--)
        a[i] = a[i - 1];
    for(i = 0; i <= 9; i++)
        if(i != d) {
            if(i < a[0])
               dp[1][i % m][0]++;
            else if(i == a[0])
               dp[1][i % m][1]++;
        }
    for(i = 2; i < a.size(); i++)
        for(j = 0; j < m; j++) {
            for(cif = 0; cif <= 9; cif++)
                if(i % 2 == 1 && cif != d) {
                  int r = (j * 10 + cif) % m;
                  dp[i][r][0] += dp[i - 1][j][0];
                  mod(dp[i][r][0]);
                  if(cif == a[i]) {
                      dp[i][r][1] += dp[i - 1][j][1];
                      mod(dp[i][r][1]);
                  }
                  else if(cif < a[i]){
                     dp[i][r][0] += dp[i - 1][j][1];
                     mod(dp[i][r][0]);
                  }
                }
                else if(i % 2 == 0 && cif == d) {
                  int r = (j * 10 + cif) % m;
                  dp[i][r][0] += dp[i - 1][j][0];
                  mod(dp[i][r][0]);
                  if(cif == a[i]) {
                      dp[i][r][1] += dp[i - 1][j][1];
                      mod(dp[i][r][1]);
                  }
                  else if(cif < a[i]){
                      dp[i][r][0] += dp[i - 1][j][1];
                      mod(dp[i][r][0]);
                  }
                }
        }
    return (dp[a.size() - 1][0][0] + dp[a.size() - 1][0][1]) % MOD;
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    //int ;
    ios::sync_with_stdio(false);
    cin >> m >> d;
    cin >> a >> b;
    bool flag = 1;
    int r = 0;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] - '0' == d && i % 2 == 0)
           flag = 0;
        if(a[i] - '0' != d && i % 2 == 1)
           flag = 0;
        r = (r * 10 + a[i] - '0') % m;
    }
    if(r != 0)
        flag = 0;
    cout << (check(b) - check(a) + MOD + flag) % MOD;
    //cin.close();
    //cout.close();
    return 0;
}