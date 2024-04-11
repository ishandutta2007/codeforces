#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int>pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1010;
const int MOD = 998244353;
int dp[N][N][2][2][2]; // [i][j][has0][has1][last]
void add(int &a, int b){
    a = (a + b) % MOD;
}

int main(){
    fastIO;
    string x, y;
    cin >> x >> y;
    int n = x.size();
    int m = y.size();
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ;j < m ; j ++ ){
            dp[i+1][j][1][0][0] = 1;
            dp[i][j+1][0][1][1] = 1;
        }
    }
    int sol;
    char val;
    for(int i = 0 ; i <= n; i ++ ){
        for(int j = 0 ; j <= m ; j ++ ){
            for(int has0 = 0; has0 < 2; has0 ++ ){
                for(int has1 = 0; has1 < 2; has1 ++ ){
                    for(int las = 0; las < 2; las ++ ){
                        if(dp[i][j][has0][has1][las] == 0) continue;
                        sol = dp[i][j][has0][has1][las];
                        if(las == 0)
                            val = x[i-1];
                        else
                            val = y[j-1];
                        if(i + 1 <= n){
                            if(x[i] != val) add(dp[i+1][j][1][has1][0],sol);
                        }
                        if(j + 1 <= m){
                            if(y[j] != val) add(dp[i][j+1][has0][1][1],sol);
                        }
                    }
                }
            }
        }
    }
    int cum = 0;
    for(int i = 0 ; i <= n; i ++ ){
        for(int j = 0 ; j <= m ; j ++ ){
            for(int las = 0; las < 2; las ++ ){
                add(cum, dp[i][j][1][1][las]);
            }
        }
    }
    cout << cum << "\n";
    return 0;
}