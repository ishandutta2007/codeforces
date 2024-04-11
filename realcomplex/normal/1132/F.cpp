#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = 505;
int dp[N][N];
char s[N];

int solve(int L, int R){
    if(L > R)
        return 0;
    if(dp[L][R] != -1)
        return dp[L][R];
    if(L == R){
        dp[L][R] = 1;
    }
    else{
        dp[L][R] = 1 + solve(L + 1, R);
        for(int j = L + 1; j <= R; j ++ ){
            if(s[L] == s[j]){
                dp[L][R] = min(dp[L][R], solve(L + 1, j - 1) + solve(j, R));
            }
        }
    }
    return dp[L][R];
            
}

int main(){
    fastIO;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> s[i]; 
        for(int j = i; j <= n ; j ++ )
            dp[i][j] = -1;
    }
    cout << solve(1, n);
    return 0;
}