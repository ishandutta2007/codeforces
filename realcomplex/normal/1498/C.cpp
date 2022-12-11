#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MOD = (int)1e9 + 7;
const int N = 1010;
int dp[N][N][2];

int m;

int solve(int n, int k, int dir){
    if(k == 0) return 0;
    if(n == 0 || n > m) return 1;
    if(dp[n][k][dir] != 0) return dp[n][k][dir];
    int r;
    if(dir == 0) r = +1;
    else r = -1;
    return dp[n][k][dir] = (solve(n + r, k, dir) + solve(n - r, k - 1, (1-dir))) % MOD;
}

void solve(){
    int n, k;
    cin >> n >> k;
    m = n;
    for(int i = 0 ; i <= n + 1; i ++ ){
        for(int j = 0 ; j <= k ; j ++ ){
            for(int d = 0; d < 2; d ++ ){
                dp[i][j][d] = 0;
            }
        }
    }
    cout << solve(1, k, 0) << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ )
        solve();
    return 0;
}