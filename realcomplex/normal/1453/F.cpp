#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 3005;
int dp[N][N];

void upd(int &a, int b){
    a = min(a, b);
}

int A[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 0; j <= n; j ++ ){
            dp[i][j]=(int)1e9;
        }
    }
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
    }
    dp[1][0] = 0;
    for(int j = 1; j <= n; j ++){
        upd(dp[1][j],dp[1][j-1]);
    }
    int flip;
    for(int i = 2; i <= n; i ++ ){
        flip = 0;
        for(int j = i - 1; j >= 1; j -- ){
            if(j + A[j] >= i){
                upd(dp[i][j + A[j]], dp[j][i-1]+flip);
                flip ++ ;
            }
        }
        for(int j = 1; j <= n; j ++ ){
            upd(dp[i][j],dp[i][j-1]);
        }
    }
    cout << dp[n][n] << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        solve();
    }
    return 0;
}