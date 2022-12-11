#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5005;
bool can[N][N];
int dp[N];
int A[N];
int cnt[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 0 ; i <= n; i ++ ){
        dp[i] = -1;
    }
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
    }
    int mx;
    for(int i = 1; i <= n; i ++ ){
        mx = 0;
        for(int j = i ; j <= n; j ++) {
            cnt[A[j]] ++ ;
            mx = max(mx, cnt[A[j]]);
            if(mx * 2 <= (j - i + 1) && (j - i + 1) % 2 == 0){
                can[i][j]=true;
            }
            else{
                can[i][j]=false;
            }
        }
        for(int j = 1; j <= n; j ++ ) cnt[j] = 0;
    }
    int res = 0;
    for(int i = 1; i <= n ; i ++ ){
        if(can[1][i-1] || i == 1){
            dp[i]=1;
        }
        for(int j = i - 1; j >= 1; j -- ){
            if(i == j + 1 || can[j+1][i-1]){
                if(A[i] == A[j] && dp[j] != -1){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        if(i == n || can[i + 1][n]){
            res = max(res, dp[i]);
        }
    }
    cout << res << "\n";
}


int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}