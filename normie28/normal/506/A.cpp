#include <bits/stdc++.h>
 using namespace std;
 #define endl "\n"
int p[30005];
int dp[30005][605];
 
int max(int a, int b){ return a > b ? a : b; }
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, d;
    cin>>n>>d;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        p[x]++;
    }
    dp[0][300] = 1;
    int res=0;
    d += 300;
    for(int i=d-300; i<=30000; i++){
        for(int j=0; j<=600; j++){
            if(i-d+j >= 0 && i-d+j < i && dp[i-d+j][j]) dp[i][j] = max(dp[i][j], dp[i-d+j][j]+p[i]);
            if(i-d+j+1 >= 0 && i-d+j+1 < i && j < 600 && dp[i-d+j+1][j+1]) dp[i][j] = max(dp[i][j], dp[i-d+j+1][j+1]+p[i]);
            if(i-d+j-1 >= 0 && i-d+j-1 < i && j > 0 && dp[i-d+j-1][j-1]) dp[i][j] = max(dp[i][j], dp[i-d+j-1][j-1]+p[i]);
            if(dp[i][j] > res) res = dp[i][j];
        }
    }
    cout<<res-1;
}