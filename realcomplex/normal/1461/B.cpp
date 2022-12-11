#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 505;
int L[N][N];
int R[N][N];
int has[N][N];
int dp[N][N];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i <= n + 1; i ++ ){
        for(int j = 0 ; j <= m + 1; j ++ ){
            L[i][j]=R[i][j]=has[i][j]=0;
            dp[i][j]=0;
        }
    }
    char f;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m ; j ++ ){
            cin >> f;
            if(f == '*') has[i][j]=1;
            else has[i][j]=0;
            dp[i][j]=has[i][j];
            if(has[i][j]==0)
                L[i][j]=0;
            else
                L[i][j]=L[i][j-1]+1;
        }
        for(int j = m ; j >= 1; j -- ){
            if(has[i][j]==0)R[i][j]=0;
            else R[i][j]=R[i][j+1]+1;
        }
    }
    ll soln = 0;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m ; j ++ ){
            if(has[i][j]==0){
                dp[i][j]=0;
            }
            else{
                dp[i][j] = min({L[i][j],R[i][j],dp[i-1][j]+1});
                soln += dp[i][j];
            }
        }
    }
    cout << soln << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        solve();
    }
}