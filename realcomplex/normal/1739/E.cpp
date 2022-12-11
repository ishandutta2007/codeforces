#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
int dp[N][2][2];
int conf[2][N];

void maxi(int &x, int y){
    x=max(x,y);
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i = 0 ; i < 2; i ++ ){
        char f;
        for(int j = 1; j <= n; j ++ ){
            cin >> f;
            conf[i][j] = f - '0';
        }
    }
    for(int i = 0; i <= n; i ++ ){
        for(int p = 0 ;p < 2; p ++ ){
            for(int q = 0; q < 2; q ++ ){
                dp[i][p][q] = -(int)1e9;
            }
        }
    }
    dp[0][0][0]=0;
    int res = 0;
    for(int i = 1; i <= n; i ++ ){
        for(int p = 0 ;p < 2; p ++ ){
            for(int q = 0; q < 2; q ++ )
                maxi(dp[i][p][0], dp[i-1][p][q]);
        }
        if(conf[0][i]){
            maxi(dp[i][0][0], max(dp[i-1][0][0], dp[i-1][0][1]) + 1);
            maxi(dp[i][0][1], dp[i-1][1][0] + 1);
        }
        if(conf[1][i]){
            maxi(dp[i][1][0], max(dp[i-1][1][0], dp[i-1][1][1]) + 1);
            maxi(dp[i][1][1], dp[i-1][0][0] + 1);
        }
        if(conf[0][i] && conf[1][i]){
            maxi(dp[i][0][1], dp[i-1][1][0] + 2);
            maxi(dp[i][1][1], dp[i-1][0][0] + 2);
        }
        for(int p = 0 ; p < 2; p ++ ){
            for(int q = 0; q < 2; q ++ ){
                maxi(res, dp[i][p][q]);
            }
        }
    }
    cout << res << "\n";
    return 0;
}