#include<bits/stdc++.h>
using namespace std;
 
const int MAXN = 4e3 + 10, MAXK = 810;
int n, k;
char g[MAXN][MAXN];
int dp[MAXN][MAXK];
int opt[MAXN][MAXK];
int pref[MAXN][MAXN];
int f[MAXN][MAXN];
 
inline void init(){
    for(int i = 0; i <= MAXK; i++){
        for(int j = 0; j < MAXN; j++){
            dp[j][i] = 1e9;
            //g[i][j] = 0;
            //pref[i][j] = 0;
            //f[i][j] = 0;
            //opt[i][j] = -1;
        }
    }
    //for(int i = 0; i < MAXN; i++){
    //    opt[0][i] = 0;
    //}
}
 
void solve(){
    init();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> g[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            pref[i][j] = (g[i][j] - '0') + (i > 0 ? pref[i-1][j] : 0) + (j > 0 ? pref[i][j-1] : 0) - (i > 0 && j > 0 ? pref[i-1][j-1] : 0);
        }
    }
    for(int i = 0; i < n; i++){
        f[i][i] = 0;
        for(int j = i + 1; j < n; j++){
            f[i][j] = pref[j][j] - (i > 0 ? pref[i-1][j] : 0) - (i > 0 ? pref[j][i-1] : 0) + (i > 0 ? pref[i-1][i-1] : 0);
            f[i][j] >>= 1;
            f[j][i] = f[i][j];
        }
    }
 
    for(int i = 0; i < n; i++){
        for(int j = k; j > 0; j--){
            int l = (i == 0 ? 0 : opt[i-1][j]);
            int r = (j == k ? i : opt[i][j + 1]);
            for(int k = l; k <= r; k++){
                if(dp[i][j] > (k == 0 ? 0 : dp[k - 1][j - 1]) + f[k][i]){
                    dp[i][j] = (k == 0 ? 0 : dp[k - 1][j - 1]) + f[k][i];
                    opt[i][j] = k;
                }
            }
        }
    }
    cout << dp[n - 1][k] << '\n';
}
 
 
 
signed main() {
    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
 
    #endif // DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n >> k)
        solve();
    return 0;
}