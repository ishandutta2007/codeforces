#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXK = 1000;

int dp[MAXK + 1], c[MAXK + 1];
int comb[MAXK + 1][MAXK + 1];

inline void mod(int &x) {
    if(x >= MOD)
       x -= MOD;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, k;
    ios::sync_with_stdio(false);
    cin >> k;
    for(i = 1; i <= k; i++) {
        cin >> c[i];
    }
    for(i = 0; i <= MAXK; i++) {
        comb[i][0] = 1;
        for(j = 1; j <= i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            mod(comb[i][j]);
        }
    }
    int nr = c[1];
    dp[1] = 1;
    for(i = 2; i <= k; i++) {
        dp[i] = (1LL * dp[i - 1] * comb[nr + c[i] - 1][c[i] - 1]) % MOD;
        nr += c[i];
    }
    cout << dp[k];
    //cin.close();
    //cout.close();
    return 0;
}